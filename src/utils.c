#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdarg.h>

char* easySprintf( const char* _stringFormat, ... ) {
	va_list _getLengthArgs;
	va_list _doWriteArgs;
	char* _completeString;

	va_start( _getLengthArgs, _stringFormat );
	va_copy(_doWriteArgs,_getLengthArgs); // vsnprintf modifies the state of _getLengthArgs so that we can't use it anymore, copy it so we can use it twice in total
	_completeString = malloc(vsnprintf(NULL,0,_stringFormat,_getLengthArgs)+1); // Get the size it would've written
	va_end( _getLengthArgs );
	vsprintf(_completeString,_stringFormat,_doWriteArgs); // This should not overflow because we already got the exact size we'll need
	va_end( _doWriteArgs ); // Even though it's a copy we still need to va_end it.

	return _completeString;
}

void seekPast(FILE* fp, unsigned char _target){
	while (1){
		int _lastRead = fgetc(fp);
		if (_lastRead==_target || _lastRead==EOF){
			break;
		}
	}
}
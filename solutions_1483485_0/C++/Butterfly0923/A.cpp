#include <stdio.h>
#include <string.h>

#define LEN 128

char const * s = "yhesocvxduiglbkrztnwjpfmaq";
char t[LEN];

int main ( ) {
	int c, T, X;

	for ( c = 0; c < LEN; t[c] = c, ++c );
	strncpy ( &t['a'], s, strlen ( s ) );

	scanf ( "%d", &T ); while ( '\n' != getchar ( ) );
	for ( X = 1; X <= T; ++X ) {
		printf ( "Case #%d: ", X );
		while ( '\n' != ( c = getchar ( ) ) ) putchar ( t[c] );
		putchar ( '\n' );
	}

	return 0;
}

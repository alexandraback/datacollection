#include <stdio.h>
#include <string.h>

char ref[ 256 ];

char samplei[ 500 ] = "ejpmysljylckdkxveddknmcrejsicpdrysirbcpcypcrtcsradkhwyfrepkymveddknkmkrkcddekrkdeoyakwaejtysrreujdrlkgcjv";
char sampleo[ 500 ] = "ourlanguageisimpossibletounderstandtherearetwentysixfactorialpossibilitiessoitisokayifyouwanttojustgiveup";

void init ( void ) {
	for ( int i = 0 ; samplei[ i ] ; ++i ) {
		ref[ samplei[ i ] ] = sampleo[ i ];
	}
	ref[ 'q' ] = 'z';
	ref[ 'z' ] = 'q';
}

int main ( void ) {
	freopen ( "in.txt", "r", stdin );
	freopen ( "out.txt", "w", stdout );
	init ();
	int T; char c;
	scanf ( "%d", &T ); getchar ();
	for ( int cas = 1 ; cas <= T ; ++cas ) {
		printf ( "Case #%d: ", cas );
		do {
			c = getchar ();
			if ( c == EOF || c == '\n' ) {
				break;
			} else if ( c == ' ' ) putchar ( c );
			else putchar ( ref[ c ] );
		} while ( 1 );
		putchar ( '\n' );
		if ( c == EOF ) break;
	}
	return 0;
}

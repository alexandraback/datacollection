#include <stdio.h>

int main ( ) {
	int T, c;
	int A, B;
	double min, e, pp, p;
	int i;

	for ( scanf ( "%d", &T ), c = 1; c <= T; ++c ) {
		scanf ( "%d%d", &A, &B );
		min = B + 2;
		for ( pp = 1, i = 1; i <= A; ++i ) {
			scanf ( "%lf", &p );
			pp *= p;
			e = ( A - i + B - i + 1 ) + ( 1 - pp ) * ( B + 1 );
			if ( min > e ) min = e;
		}
		printf ( "Case #%d: %.6lf\n", c, min );
	}

	return 0;
}

#include <stdio.h>

#define LEN 31

int ns[LEN], s[LEN];

int main ( ) {
	int i, j;
	int T, N, S, p, x, ti;

	for ( i = 1; i <= LEN; ++i ) ns[i] = ( i + 2 ) / 3, s[i] = ( i + 1 ) / 3 + 1, s[i] = s[i] < 10 ? s[i] : 10;
	for ( scanf ( "%d", &T ), x = 1; x <= T; ++x ) {
		scanf ( "%d%d%d", &N, &S, &p );
		for ( i = j = 0; i < N; ++i ) {
			scanf ( "%d", &ti );
			if ( p <= ns[ti] ) ++j;
			else if ( p <= s[ti] && S ) --S, ++j;
		}
		printf ( "Case #%d: %d\n", x, j );
	}

	return 0;
}

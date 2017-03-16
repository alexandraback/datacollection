#include <cstdio>
#include <algorithm>

using namespace std;

/*
0:	can must s
1:	can may s
2:	can not s
3:	no may s
4:	no not s
 */

int is ( int score, int P ) {
	int x = score / 3;
	if ( score % 3 == 2 ) {
		if ( x + 1 >= P ) return 1;
		else if ( x + 2 >= P ) return 0;
		else return 3;
	} else if ( score % 3 == 1 ) {
		if ( x >= 1 ) {
			if ( x + 1 >= P ) return 1;
			else return 3;
		} else {
			if ( x + 1 >= P ) return 2;
			else return 4;
		}
	} else {
		if ( x >= 1 ) {
			if ( x >= P ) return 1;
			else if ( x + 1 >= P ) return 0;
			else return 3;
		} else {
			if ( x >= P ) return 2;
			else return 4;
		}
	}
}

int main ( void ) {
	freopen ( "in.txt", "r", stdin );
	freopen ( "out.txt", "w", stdout );
	
	int T, N, S, P, score;
	scanf ( "%d", &T );
	for ( int cas = 1 ; cas <= T ; ++cas ) {
		scanf ( "%d%d%d", &N, &S, &P );
		int kind[ 5 ] = { 0 };
		for ( int i = 0 ; i < N ; ++i ) {
			scanf ( "%d", &score );
			++kind[ is ( score, P ) ];
		}
		int ans = 0;
		if ( kind[ 0 ] > S ) {
			ans = S + kind[ 1 ] + kind[ 2 ];
		} else ans = kind[ 0 ] + kind[ 1 ] + kind[ 2 ];
		printf ( "Case #%d: %d\n", cas, ans );
	}
	return 0;
}


#include <stdio.h>
#include <string.h>

#define N 2000010

int f[ N ];

int ten[ 10 ];
int stack[ 20 ];

void init ( void ) {
	memset ( f, 0, sizeof ( f ) );
	ten[ 0 ] = 1;
	for ( int i = 1 ; i < 10 ; ++i ) {
		ten[ i ] = 10 * ten[ i - 1 ];
	}
}

int sum ( int x, int A, int B, int cnt ) {
	int ret = 0, y = x, top = -1;
	for ( int i = 0 ; i < cnt ; ++i ) {
		int d = y % 10;
		y = y / 10 + ten[ cnt - 1 ] * d;
		if ( y >= x || y < A || y > B ) continue;
		else {
			if ( !f[ y ] ) {
				f[ y ] = 1;
				++ret;
				stack[ ++top ] = y;
			}
		}
	}
	while ( top != -1 ) {
		f[ stack[ top ] ] = 0;
		--top;
	}
	return ret;
}

int count ( int A, int B ) {
	int ret = 0, cnt = 0, x = A;
	while ( x ) { ++cnt; x /= 10; }
	for ( int i = A ; i <= B ; ++i ) {
		ret += sum ( i, A, B, cnt );
	}
	return ret;
}

int main ( void ) {
	freopen ( "in.txt", "r", stdin );
	freopen ( "out.txt", "w", stdout );
	int T, A, B;
	init ();
	scanf ( "%d", &T );
	for ( int cas = 1 ; cas <= T ; ++cas ) {
		scanf ( "%d%d", &A, &B );
		printf ( "Case #%d: %d\n", cas, count ( A, B ) );
	}
	return 0;
}


#include <cstdio>

bool test() {
	int h, w;
	scanf("%d %d", &h, &w );
	int M[101][101];
	for( int y = 0; y < h; y++ )
		for( int x = 0; x < w; x++ )
			scanf("%d", &M[y][x]);

	for( int y = 0; y < h; y++ )
		for( int x = 0; x < w; x++ ) {
			int m = 0, n = 0;
			for( int i = 0; i < h; i++ )
				if( M[i][x] > m )
					m = M[i][x];
			for( int i = 0; i < w; i++ )
				if( M[y][i] > n )
					n = M[y][i];
			if( m > M[y][x] and n > M[y][x] )
				return false;
		}
	return true;
}

int main() {
	int T;
	scanf("%d", &T );
	for( int i = 1; i <= T; i++ )
		printf("Case #%d: %s\n", i, test() ? "YES" : "NO" );
}

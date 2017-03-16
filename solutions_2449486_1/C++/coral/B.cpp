#include <stdio.h>
int a[105][105], T, n, m;
int judge ( int x, int y ) {
	int i, j, flag1 = 0, flag2 = 0;
	for ( i = 0; i < n; ++i )
		if ( a[i][y] > a[x][y] ) {
			flag1 = 1;
			break;
		}
	for ( j = 0; j < m; ++j )
		if ( a[x][j] > a[x][y] ) {
			flag2 = 1;
			break;
		}
	return flag1 & flag2;
}
int main ( ) {
	int i, j, b, e, minx, flag;
	scanf ( "%d", &T );
	for ( int cases = 1; cases <= T; ++cases ) {
		printf ( "Case #%d: ", cases );
		scanf ( "%d%d", &n, &m );
		for ( i = 0; i < n; ++i )
			for ( j = 0; j < m; ++j ) scanf ( "%d", &a[i][j] );
		
		for ( flag = 1, i = 0; i < n && flag; ++i ) {
			minx = 0x7FFFFFFF;
			for ( j = 0; j < m; ++j ) if ( a[i][j] < minx ) minx = a[i][j];
			//printf ( "minx=%d\n", minx );
			for ( j = 0; j < m && a[i][j] > minx; ++j );
			//for ( ; j < m && a[i][j] == minx; ++j )
			b = j;
			for ( j = m-1; j >= 0 && a[i][j] > minx; --j );
			//for ( ; j >=0 && a[i][j] == minx; --j );
			e = j;
			//printf ( "b=%d	e=%d\n", b, e );
			for ( j = b; j <= e && flag; ++j )
				if ( judge ( i, j ) ) {
					//printf ( "i=%d j = %d\n", i, j );
					printf ( "NO\n" );
					flag = 0;
					continue;
				}
		}
		if ( flag ) printf ( "YES\n" );
	}
}

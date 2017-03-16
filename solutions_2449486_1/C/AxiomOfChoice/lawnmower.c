#include <stdio.h>

#define min(x,y) (x<y?x:y)
#define max(x,y) (x>y?x:y)

#define N 105

int n, m, g[N][N], r[N], c[N];

void run()
{
	int i, j;

	scanf( "%d%d", &n, &m );
	for( i = 0; i < n; i++ ) for( j = 0; j < m; j++ )  scanf( "%d", &g[i][j] );

	for( i = 0; i < n; i++ ) for( r[i] = j = 0; j < m; j++ ) r[i] = max( r[i], g[i][j] );
	for( j = 0; j < m; j++ ) for( c[j] = i = 0; i < n; i++ ) c[j] = max( c[j], g[i][j] );

	int ok = 1;
	for( i = 0; i < n; i++ ) for( j = 0; j < m; j++ ) ok &= g[i][j] == min( r[i], c[j] );
	printf( ok ? "YES\n" : "NO\n" );
}

int main()
{
	int T, t;
	scanf( "%d", &T );
	for( t = 1; t <= T; t++ )
	{
		printf( "Case #%d: ", t );
		run();
	}
	return 0;
}

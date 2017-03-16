#include <cstdio>
#include <cstring>

inline int max( const int &a, const int &b )
{
	if ( a > b ) return a;
	return b;
}

int n, s, p;
int c[1024];

int dp[1024][1024];

int u( int x )
{
	if ( x >= p ) return 1;
	return 0;
}

int main()
{
	int t, T;
	int i, j, k;
	
	scanf( "%d", &T );
	for ( t = 1; t <= T; t++ )
	{
		scanf( "%d %d %d", &n, &s, &p );
		for ( i = 1; i <= n; i++ )
		{
			scanf( "%d", &c[i] );
		}
		for ( i = 0; i <= s; i++ )
		{
			dp[0][i] = 0;
		}
		for ( i = 1; i <= n; i++ )
		{
			for ( j = 0; j <= s; j++ )
			{
				dp[i][j] = 0;
				for ( k = 0; k <= 10; k++ )
				{
					if ( 3*k == c[i] )
						dp[i][j] = max( dp[i][j], dp[i-1][j] + u(k) );
					if ( 3*k+1 == c[i] && k <= 9 )
						dp[i][j] = max( dp[i][j], dp[i-1][j] + u(k+1) );
					if ( 3*k+2 == c[i] && k <= 9 )
						dp[i][j] = max( dp[i][j], dp[i-1][j] + u(k+1) );

					if ( ( 3*k+2 == c[i] ) && ( j >= 1 ) && ( k <= 8 ) )
						dp[i][j] = max( dp[i][j], dp[i-1][j-1] + u(k+2) );
					if ( ( 3*k+3 == c[i] ) && ( j >= 1 ) && ( k <= 8 ) )
						dp[i][j] = max( dp[i][j], dp[i-1][j-1] + u(k+2) );
					if ( ( 3*k+4 == c[i] ) && ( j >= 1 ) && ( k <= 8 ) )
						dp[i][j] = max( dp[i][j], dp[i-1][j-1] + u(k+2) );
				}
			}
		}
		
		printf( "Case #%d: %d\n", t, dp[n][s] );
	}
	return 0;
}

#include <stdio.h>
#include <string.h>

int g[1002][1002], len[1002];
bool visited[1002], diamond;

void dfs( int u )
{
	int i, v;
	for( i = 1; i <= len[u]; i++ )
	{
		v = g[u][i];

		if( visited[v] == true )
		{
			diamond = true;
			return;
		}

		visited[v] = true;

		dfs( v );

		if( diamond == true )
		{
			return;
		}
	}
}

int main()
{
	freopen( "R1C_A-large.in", "r", stdin );
	freopen( "R1C_A-large.out", "w", stdout );

	int T, u, v, kase, i, N, d, D;
	scanf( "%d", &T );

	for( kase = 1; kase <= T; kase++ )
	{
		memset( g, 0, sizeof( g[0]));
		memset( len, 0, sizeof( len ));

		scanf( "%d", &N );

		for( u = 1; u <= N; u++ )
		{
			scanf( "%d", &D );

			for( d = 1; d <= D; d++ )
			{
				scanf( "%d", &v );

				g[u][++len[u]] = v;
				//visited[u][v] = 1;
			}
		}

		int i;
		for( i = 1; i <= N; i++ )
		{
			diamond = false;
			memset( visited, false, sizeof( visited ));
			visited[i] = true;

			dfs( i );

			if( diamond == true )
			{
				printf( "Case #%d: Yes\n", kase );
				break;
			}
		}
		if( i > N )
		{
			printf( "Case #%d: No\n", kase );
		}
	}
	return 0;
}
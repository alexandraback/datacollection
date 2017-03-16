using namespace std;

#include <bits/stdc++.h>

int R, C, M;
int dp[ 55 ][ 55 ][ 2505 ];
int path[ 55 ][ 55 ][ 2505 ];

int test(int r, int maxC, int rem)
{
	int &ret = dp[ r ][ maxC ][ rem ];

	if ( ret != -1 ) return ret;

	if ( r == R + 1 )
	{
		return ret = (rem == M) ? 1 : 0;
	}

	ret = 0;
	for (int i = 0; i <= maxC; i++)
	{
		int marked = 0;

		if (i > 0)
		{
			if ( r == 1 ) marked += min( C, i + 1);
			if ( r + 1 <= R ) marked += min( C, i + 1 );
		}

		if ( test( r + 1, i, rem - marked ) )
		{
			path[ r ][ maxC ][ rem ] = i;
			return ret = 1;
		}
	}

	return ret;
}

char grid[ 55 ][ 55 ];

void fill(int r, int maxC, int rem)
{
	if ( r > R ) return;

	int h = path[r][maxC][rem];

	//printf("%d\n", h);

	int marked = 0;
	if ( h > 0 )
	{
		if ( r == 1 )
		{
			marked += min( C, h + 1);
			for (int j = 1; j <= min( C, h+1 ); j++)
				grid[r][j] = '.';
		}
		if ( r + 1 <= R )
		{
			marked += min( C, h + 1 );
			for (int j = 1; j <= min( C, h+1 ); j++)
				grid[r+1][j] = '.';
		}
	}

	fill( r+1, h, rem - marked );
}

int main()
{
	int ntc;

	scanf("%d", &ntc);
	for (int tc = 1; tc <= ntc; tc++)
	{
		scanf("%d %d %d", &R, &C, &M);

		memset( dp, -1, sizeof dp );

		printf("Case #%d:\n", tc);

		if ( R*C == M + 1 )
		{
			for (int i = 1; i <= R; i++)
			{
				for (int j = 1; j <= C; j++)
				{
					grid[i][j] = '*';
				}
			}

			grid[1][1] = 'c';

			for (int i = 1; i <= R; i++)
			{
				for (int j = 1; j <= C; j++)
				{
					printf("%c", grid[i][j]);
				}
				printf("\n");
			}

			continue;
		}

		if ( test( 1, C, R * C ) )
		{
			for (int i = 1; i <= R; i++)
			{
				for (int j = 1; j <= C; j++)
				{
					grid[i][j] = '*';
				}
			}

			fill( 1, C, R * C );
			grid[1][1] = 'c';

			for (int i = 1; i <= R; i++)
			{
				for (int j = 1; j <= C; j++)
				{
					printf("%c", grid[i][j]);
				}
				printf("\n");
			}
		}
		else printf("Impossible\n");
	}

	return 0;
}

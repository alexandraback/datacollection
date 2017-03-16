#include <stdio.h>
#include <string.h>

#define MAXN 100
#define MAXH 100

int square[MAXN][MAXN];
int is_k[2][MAXN];

int N, M;

int main()
{
	int Tcases;
	scanf("%d", &Tcases);
	int cases;
	for ( cases = 0; cases < Tcases; cases++)
	{
		scanf("%d %d", &N, &M);
		int i, j, k;
		for ( i = 0; i < N; i++)
		{
			for ( j = 0; j < M; j++)
			{
				scanf("%d", &square[i][j]);
			}
		}

		int flag = 1;
		for ( k = 1; k <= MAXH && flag; k++)
		{
			memset( is_k, 0, sizeof( is_k));
			for ( i = 0; i < N; i++)
			{
				for ( j = 0; j < M; j++)
				{
					is_k[0][i] += square[i][j] == k;
					is_k[1][j] += square[i][j] == k;
				}
			}
			for ( i = 0; i < N; i++)
			{
				if ( is_k[0][i] == M)
				{
					for ( j = 0; j < M; j++)
					{
						square[i][j] = k + 1;
					}
				}
			}

			for ( j = 0; j < M; j++)
			{
				if ( is_k[1][j] == N)
				{
					for ( i = 0; i < N; i++)
					{
						square[i][j] = k + 1;
					}
				}
			}

			for ( i = 0; i < N; i++)
			{
				for ( j = 0; j < M; j++)
				{
					flag &= square[i][j] > k;
//					printf("%d ", square[i][j]);
				}
//				printf("\n");
			}
//			printf("%d\n", flag);
		}

		printf("Case #%d: %s\n", cases + 1, flag ? "YES" : "NO");
	}

	return 0;
}

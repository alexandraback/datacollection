#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 51

int N,M,K,T;
char G[MAXN][MAXN];

void fill(int n,int m,int k)
{
	int i,j;
	for (i=0;i<n;i++)
		for (j=0;j<m;j++)
		{
			if (k > 0)
			{
				k--;
				G[i][j] = '*';
			}
		}
}

int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	int i,j;
	scanf("%d",&T);
	for (int cases=1;cases<=T;cases++)
	{
		scanf("%d%d%d",&N,&M,&K);
		printf("Case #%d:\n",cases);
		memset(G,'.',sizeof G);
		if (N == 1 || M == 1)
		{
			fill(N,M,K);
			if (N == 1)
			{
				G[0][M-1] = 'c';
			}
			else
			{
				G[N-1][0] = 'c';
			}
		}
		else if (N*M == K+1)
		{
			fill(N,M,K);
			G[N-1][M-1] = 'c';
		}
		else
		{
			int t = (N-2) * (M-2);
			bool c = false;
			if (K > t)
			{
				bool imp = false;
				int e = K - t;
				if (e & 1)
				{
					if (K > N*M - 9 || N == 2 || M == 2)
					{
						imp = true;
					}
					else
					{
						K ++;
						c = true;
					}
				}
				else
				{
					if (K > N*M - 4)
					{
						imp = true;
					}
				}
				if (imp)
				{
					printf("Impossible\n");
					continue;
				}
			}
			int k = min((N-2)*(M-2), K);
			fill(N-2,M-2, k);
			if (c)
			{
				G[N-3][M-3] = '.';
			}
			K -= k;
			if (c)
			{
				k = min((N-3)*2,K);
			}
			else
			{
				k = min((N-2)*2,K);
			}
			K -= k;
			for (i=0;i<N-2;i++)
			{
				if (k > 0)
				{
					k-=2;
					G[i][M-2] = G[i][M-1] = '*';
				}
			}
			k = min((M-2)*2,K);
			for (j=0;j<M-2;j++)
			{
				if (k > 0)
				{
					k-=2;
					G[N-2][j] = G[N-1][j] = '*';
				}
			}
			G[N-1][M-1] = 'c';
		}
		for (i=0;i<N;i++)
		{
			for (j=0;j<M;j++)
			{
				printf("%c",G[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}

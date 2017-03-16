#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<string>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<algorithm>
#include<iostream>
using namespace std;

int n, m;

char res[55][55];
int a[55*55][55][55];

int func(int k, int p, int l)
{
	if(l < 2 || k == 1 || k < 0)
		return 0;
	if(k == 0)
		return 1;
	if(p == m)
		return 0;
	if(a[k][p][l] != -1)
		return a[k][p][l];
	a[k][p][l] = 0;
	if(k <= l)
	{
		for(int i = 0; i < k; i++)
			res[i][p] = '.';
		return 1;
	}
	if(func(k-l, p+1, l))
	{
		for(int i = 0; i < l; i++)
			res[i][p] = '.';
		return 1;
	}
	if(func(k, p, l-1))
		return 1;
	return 0;
}

int main()
{
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);

	int TT;
	scanf("%d", &TT);
	for(int T = 0; T < TT; T++)
	{
		printf("Case #%d: \n", T+1);
		int k;
		scanf("%d%d%d", &n, &m, &k);
		memset(res, 0, sizeof(res));
		memset(a, -1, sizeof(a));
		if(k == m*n - 1)
		{
			res[0][0] = 'c';
			for(int i = 0; i < n; i++)
			{
				for(int j = 0; j < m; j++)
				{
					if(!i && !j)
						continue;
					res[i][j] = '*';
				}
				printf("%s\n", res[i]);
			}
		}
		else if(n == 1)
		{
			for(int i = 0; i < k; i++)
				res[0][i] = '*';
			for(int i = k; i < m; i++)
				res[0][i] = '.';
			res[0][m-1] = 'c';
			printf("%s\n", res[0]);
		}
		else if(m == 1)
		{
			for(int i = 0; i < k; i++)
				printf("*\n");
			for(int i = k; i < n-1; i++)
				printf(".\n");
			printf("c\n");
		}
		else
		{
			k = n*m-k;

			bool f = 0;
			for(int i = n; i >= 2; i--)
			{
				if(k - 2*i >= 0)
				{
					if(func(k - 2*i, 2, i))
					{
						for(int t = 0; t < 2; t++)
						{
							for(int j = 0; j < i; j++)
								res[j][t] = '.';
						}
						f = 1;
						break;
					}
				}
			}
			if(!f)
			{
				printf("Impossible\n");
				continue;
			}

			res[0][0] = 'c';
			for(int i = 0; i < n; i++)
			{
				for(int j = 0; j < m; j++)
				{
					if(res[i][j] != '.' && res[i][j] != 'c')
						res[i][j] = '*';
				}
				printf("%s\n", res[i]);
			}
		}
	}

	return 0;
}
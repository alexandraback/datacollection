#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int a[110][52], grid[52][52], c[2510];
int T, t, n, m;

int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> n;
		m = 2 * n - 1;
		memset(c, 0, sizeof(c));
		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				scanf("%d", &a[i][j]);
				c[a[i][j]] = (c[a[i][j]] + 1) & 1;
			}
		}
		printf("Case #%d:", t);
		for (int i = 0; i <= 2500; i++)
			if (c[i] & 1) printf(" %d", i);
		puts("");
	}
}
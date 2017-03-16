#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 100;

int dat[maxn], e, r, n;
int f[maxn][maxn], now[maxn];

void init()
{
	scanf("%d%d%d", &e, &r, &n);
	for (int i = 1; i <= n; i++) scanf("%d", &dat[i]);
}

int work()
{
	for (int i = 0; i <= e; i++) now[i] = dat[1] * (e - i);
	for (int i = 0; i <= e; i++) f[1][i] = 0;
	for (int i = 0; i <= e; i++) f[1][min(i + r, e)] = max(f[1][min(i + r, e)], now[i]);
	
	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j <= e; j++)
		{
			now[j] = 0;
			for (int k = 0; k <= e; k++)
			{
				if (j + k > e) break;
				now[j] = max(now[j], f[i - 1][j + k] + dat[i] * k);
			}
		}
		for (int j = 0; j <= e; j++) f[i][j] = 0;
		for (int j = 0; j <= e; j++) f[i][min(j + r, e)] = max(f[i][min(j + r, e)], now[j]);
	}
	
	int ans = 0;
	for (int i = 0; i <= e; i++) ans = max(ans, f[n][i]);
	return ans;
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++)
	{
		init();
		printf("Case #%d: %d\n", i, work());
	}
	return 0;
}

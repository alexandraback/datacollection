#include <cstdio>
const int maxn = 105;
const double eps = 1e-8;
int n, l, s, next[maxn];
int f[maxn][maxn];
double g[maxn][maxn];
char tp[maxn], tar[maxn];
double search(int i, int j)
{
	if (i == s)
		return 0;
	if (g[i][j] > -eps)
		return g[i][j];
	g[i][j] = 0;
	for (int k = 1; k <= n; k++)
	{
		int tmp = j;
		while (tmp && tp[k] != tar[tmp + 1])
			tmp = next[tmp];
		if (tp[k] == tar[tmp + 1])
			tmp++;
		if (tmp == l)
			g[i][j] += search(i + 1, next[tmp]) + 1;
		else
			g[i][j] += search(i + 1, tmp);
	}
	g[i][j] /= n;
	return g[i][j];
}
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int test;
	scanf("%d", &test);
	for (int tt = 1; tt <= test; tt++)
	{
		scanf("%d%d%d", &n, &l, &s);
		scanf("%s", tp + 1);
		scanf("%s", tar + 1);
		next[1] = 0;
		for (int i = 2; i <= l; i++)
		{
			int j = next[i - 1];
			while (j && tar[j + 1] != tar[i])
				j = next[j];
			if (tar[j + 1] == tar[i])
				next[i] = ++j;
			else
				next[i] = 0;
		}
		for (int i = 0; i <= s; i++)
			for (int j = 0; j <= l; j++)
				f[i][j] = -1;
		f[0][0] = 0;
		for (int i = 0; i < s; i++)
			for (int j = 0; j <= l; j++)
				for (int k = 1; k <= n; k++)
				{
					if (f[i][j] == -1)
						continue;
					int tmp = j;
					while (tmp && tp[k] != tar[tmp + 1])
						tmp = next[tmp];
					if (tp[k] == tar[tmp + 1])
						tmp++;
					if (tmp == l)
					{
						if (f[i][j] + 1 > f[i + 1][next[tmp]])
							f[i + 1][next[tmp]] = f[i][j] + 1;
					}
					else
					{
						if (f[i][j] > f[i + 1][tmp])
							f[i + 1][tmp] = f[i][j];
					}
				}
		int maxx = f[s][0];
		for (int i = 1; i <= l; i++)
			if (maxx < f[s][i])
				maxx = f[s][i];
		for (int i = 0; i <= s; i++)
			for (int j = 0; j <= l; j++)
				g[i][j] = -69;
		printf("Case #%d: %.7f\n", tt, maxx * 1.0 - search(0, 0));
	}
	return 0;
}

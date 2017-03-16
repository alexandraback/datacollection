#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 105;
int f[maxn][maxn], test, n, s, p, x, t;

int main()
{
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	
	scanf("%d", &test);
	for (int kase = 1; kase <= test; ++kase)
	{
		scanf("%d %d %d", &n, &s, &p);
		for (int i = 0; i <= n; ++i)
			for (int j = 0; j <= s; ++j)
				f[i][j] = -1;
		f[0][0] = 0;
		for (int i = 1; i <= n; ++i)
		{
			scanf("%d", &t);
			for (int j = 0; j <= s; ++j)
				if (f[i - 1][j] != -1)
				{
					if (j != s && t > 1)
					{
						int o = t % 3;
						if (o == 0)
							x = (t - 3) / 3 + 2;
						else
							if (o == 1)
								x = (t - 4) / 3 + 2;
							else
								x = (t - 2) / 3 + 2;
						f[i][j + 1] = max(f[i][j + 1], f[i - 1][j] + (x >= p));
					}
					x = t / 3;
					if (t % 3)
						++x;
					f[i][j] = max(f[i][j], f[i - 1][j] + (x >= p));
				}
		}
		printf("Case #%d: %d\n", kase, f[n][s]);
	}
	
	return 0;
}

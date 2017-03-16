#include <cstdio>
#include <algorithm>

using namespace std;

int c[25][25], test, n, x, y;
double ans, f[25][25];

int main()
{
	freopen("B.in", "r", stdin);
	for (int i = 0; i <= 20; ++i)
	{
		c[i][0] = c[i][i] = 1;
		for (int j = 1; j < i; ++j)
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
	}
	scanf("%d", &test);
	for (int kase = 1; kase <= test; ++kase)
	{
		scanf("%d %d %d", &n, &x, &y);
		if (x < 0)
			x = -x;
		int m = 0;
		while ((2 * (m + 1) - 1) * (m + 1) <= n)
			++m;
		if (x + y <= (m - 1) * 2)
			ans = 1.0;
		else
		{
			ans = 0;
			int rem = n - (2 * m - 1) * m;
			int lim = 2 * m;
			f[0][0] = 1.0;
			for (int i = 1; i <= lim; ++i)
				f[0][i] = f[i][0] = f[0][i - 1] * 0.5;
			for (int i = 1; i <= lim; ++i)
				for (int j = 1; j <= lim; ++j)
				{
					double p1 = 0.5, p2 = 0.5;
					if (i == lim)
						p2 = 1.0;
					if (j == lim)
						p1 = 1.0;
					f[i][j] = f[i - 1][j] * p1 + f[i][j - 1] * p2;
				}
			for (int j = y + 1; j <= lim; ++j)
				ans += f[rem - j][j];
		}
		printf("Case #%d: %.2lf\n", kase, ans);
	}
	
	return 0;
}

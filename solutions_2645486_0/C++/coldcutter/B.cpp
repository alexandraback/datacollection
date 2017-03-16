#include <cstdio>
#include <algorithm>
using namespace std;

int f[20][10], v[20], test, e, r, n;

int main()
{
	scanf("%d", &test);
	for (int kase = 1; kase <= test; ++kase)
	{
		scanf("%d %d %d", &e, &r, &n);
		for (int i = 1; i <= n; ++i)
			scanf("%d", &v[i]);
		for (int i = 0; i <= n; ++i)
			for (int j = 0; j <= e; ++j)
				f[i][j] = -1;
		f[0][e] = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j <= e; ++j)
				if (f[i][j] != -1)
					for (int k = 0; k <= j; ++k)
					{
						int x = j - k + r;
						if (x > e)
							x = e;
						f[i + 1][x] = max(f[i + 1][x], f[i][j] + k * v[i + 1]);
					}
		int ans = 0;
		for (int j = 0; j <= e; ++j)
			ans = max(ans, f[n][j]);
		printf("Case #%d: %d\n", kase, ans);
	}
	
	return 0;
}

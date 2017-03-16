#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#define rep(x, n) for (int x = 1; x <= n; ++x)
#define drp(x, n) for (int x = n; x; --x)
#define FOR(x, l, r) for (int x = l; x <= r; ++x)
int cases, n, m, d[25], ans, x, y;
int bo[2000009], p;
int main()
{
	//freopen("C-large.in", "r", stdin);
	//freopen("C-large.out", "w", stdout);
	scanf("%d", &cases);
	rep(ca, cases)
	{
		printf("Case #%d: ", ca);
		scanf("%d%d", &n, &m);
		ans = 0;
		for (int i = n; i <= m; i++)
		{
			++p;
			x = i;
			d[0] = 0;
			while (x)
			{
				d[++d[0]] = x % 10;
				x =(int) x / 10;
			}
			for (int j = 1; j < d[0]; j++)
			{
				y = 0;
				for (int k = d[0]; k; k--) y = y * 10 + d[(k - j - 1 + d[0]) % d[0] + 1];
				if (y > i && y <= m && bo[y] != p)
				{
					++ans;
					bo[y] = p;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int T, n, x, a[10010], ans, y, cnt, w;
int main()
{
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &x, &n);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		sort(a + 1, a + n + 1);
		printf("Case #%d: ", ++w);
		if (x == 1 && n > 0) 
		{
			printf("%d\n", n);
			continue;
		}
		ans = n, cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			if (x > a[i])
			{
				x += a[i];
				if (i == n) ans = min(ans, cnt);
			}
			else
			{
				ans = min(ans, cnt + n - i + 1);
				while (x <= a[i])
				{
					x += x - 1;
					cnt++;
				}
				x += a[i];
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

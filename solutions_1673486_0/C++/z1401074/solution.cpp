#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int T, n, m, cnt;
double a[100010], x, ans;
int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	scanf("%d", &T);
	while (T--)
	{
		++cnt;
		scanf("%d%d", &n, &m);
		a[0] = 1;
		for (int i = 1; i <= n; i++)
		{
			scanf("%lf", &x);
			a[i] = a[i - 1] * x;
		}
		ans = (double)m + 2;
		for (int i = 1; i <= n; i++) ans = min(ans, (1 - a[i]) * (double)(2 * m + 2 - 2 * i + n) + a[i] * (double)(m + n - 2 * i + 1));
		printf("Case #%d: ", cnt);
		printf("%.6lf\n", ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

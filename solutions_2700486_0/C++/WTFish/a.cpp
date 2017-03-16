#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;
int x, y, n, w, T;
void work()
{
	int p = x + y >> 1;
	p = (2 * p + 1) * (p + 1);
	if (n >= p)
	{
		puts("1.0");
		return;
	}
	int tp = (x + y) / 2 - 1;
	tp = (2 * tp + 1) * (tp + 1);
	if (n <= tp)
	{
		puts("0.0");
		return;
	}
	n -= tp;
	if (x == 0)
	{
		puts("0.0");
		return;
	}
	long double u, v, c = 1;
	u = 0; v = 0;
	for (int i = 0; i <= min(n, x + y); i++)
	{
		int j = n - i;
		if (j <= x + y)
		{
			u += c;
			if (i >= y + 1) v += c;
		}
		c = c / (i + 1) * (n - i);
	}
	if (u <= 1e-9) u = 1;
	v /= u;
	double ans = double(v);
	printf("%.8lf\n", ans);
}

int main()
{
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d%d", &n, &x, &y);
		x = abs(x), y = abs(y);
		printf("Case #%d: ", ++w);
		work();
	}
	return 0;
}

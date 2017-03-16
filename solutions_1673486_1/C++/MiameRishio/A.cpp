#include <iostream>

using namespace std;

const int maxn = 100005;
double a[maxn], p[maxn];

int main() {
	for (int i = 0; i < maxn; i++)
		p[i] = 1;
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	int Tn;
	scanf("%d", &Tn);
	double ans, n, m;
	for (int te = 1; te <= Tn; ++te)
	{
		ans = 0;
		int m, n;
		scanf("%d%d", &m, &n);
		int rest = n - m;
		for (int i = 1; i <= m; ++i)
		{
			scanf("%lf", a + i);
			p[i] = p[i - 1] * a[i];
		}
		ans = n + 2;
		for (int i = 0; i <= m; i++) {
			double t = p[m - i] * (rest + 2 * i + 1) + (1 - p[m - i]) * (rest + 2 * i + 2 + n);
			if (t < ans)
				ans = t;
		}

		printf("Case #%d: %.8f\n", te, ans);
	}
	return 0;
}

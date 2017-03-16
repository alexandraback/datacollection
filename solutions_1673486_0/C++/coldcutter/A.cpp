#include <cstdio>

const int maxn = 100005;

int test, A, B;
double p[maxn], sp[maxn];

int main()
{
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	
	scanf("%d", &test);
	for (int kase = 1; kase <= test; ++kase)
	{
		scanf("%d %d", &A, &B);
		sp[0] = 1;
		for (int i = 1; i <= A; ++i)
		{
			scanf("%lf", &p[i]);
			sp[i] = sp[i - 1] * p[i];
		}
		double ans = B + 2;
		for (int i = 0; i <= A; ++i)
		{
			double tmp = sp[A - i] * (2 * i + B - A + 1) + (1 - sp[A - i]) * (2 * i + 2 * B - A + 2);
			if (tmp < ans)
				ans = tmp;
		}
		printf("Case #%d: %.6lf\n", kase, ans);
	}
	
	return 0;
}

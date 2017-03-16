#include <cstdio>
#include <cstring>

const double eps = 1e-7;

int main()
{
	int t, T;
	scanf("%d", &T);
	for (t = 1; t <= T; ++t)
	{
		double c, f, x;
		double prod = 2.0;
		scanf("%lf %lf %lf", &c, &f, &x);
		double mt = x / prod;
		double sm = 0;
		while (prod < f * (x + c) / c + eps)
		{
			double ans = x / prod + sm;
			if (ans + eps < mt)
				mt = ans;
			double de = c / prod;
			sm += de;
			prod += f;
		}
		printf("Case #%d: %.9lf\n", t, mt);
	}
	return 0;
}

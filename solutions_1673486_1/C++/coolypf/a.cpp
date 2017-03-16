#include <stdio.h>
#include <algorithm>

using namespace std;

double p[200000];
double w[200000];
double x[200000];

int main()
{
	int ccc;
	scanf("%d", &ccc);
	for (int cc = 1; cc <= ccc; ++cc)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		for (int i = 0; i < a; ++i)
			scanf("%lf", p + i);
		double acc = 1.0;
		for (int i = 0; i < a; ++i)
		{
			acc *= p[i];
			w[i] = acc;
		}
		x[0] = acc;
		for (int i = a - 1; i > 0; --i)
		{
			x[a - i] = w[i - 1] * (1.0 - p[i]);
		}
		x[a] = 1.0 - p[0];
		
		double res = (b - a + 1.0) * x[0], r = b + 2.0;
		for (int i = 1; i <= a; ++i)
			res += x[i] * (2.0 * b - a + 2.0);
		res = min(res, r);
		for (int back = 1; back <= a; ++back)
		{
			r = 0.0;
			for (int i = 0; i <= a; ++i)
			{
				if (i <= back) r += x[i] * (b - a + 2.0 * back + 1.0);
				else r += x[i] * (2.0 * b - a + 2.0 * back + 2.0);
			}
			res = min(res, r);
		}
		
		printf("Case #%d: %.6lf\n", cc, res);
	}
	return 0;
}
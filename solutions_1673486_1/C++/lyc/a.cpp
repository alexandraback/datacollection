#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int a, b, t;
double p[100010];
double ans;

int main()
{
	scanf("%d", &t);
	int ca = 0;
	while (t--)
	{
		ca++;
		scanf("%d%d", &a, &b);
		for (int i = 1; i <= a; i++)
			scanf("%lf", &p[i]);
		printf("Case #%d: ", ca);
		ans = b + 2;
		double pp = 1;
		if (b + a + 1 < ans)
			ans = b + a + 1;
		for (int j = 1; j <= a; j++)
		{
			pp *= p[j];
			int i = a - j;
			if (pp * (2 * i + b - a + 1) + (1 - pp) * (2 * b - a + 2 + 2 * i) < ans)
				ans = pp * (2 * i + b - a + 1) + (1 - pp) * (2 * b - a + 2 + 2 * i);
		}
		printf("%.8lf\n", ans);
	}
	return 0;
}

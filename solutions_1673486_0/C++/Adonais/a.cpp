#include <cstdio>
using namespace std;


int main()
{
	int t, T;
	int i, j, n, a, b;
	double p[100002];
	double op;
	double ans;
	scanf("%d", &T);
	for (t = 1; t <= T; t++)
	{
		ans = 0;
		scanf("%d %d", &a, &b);
		for (i = 0; i < a; i++)
		{
			scanf("%lf", &p[i]);
		}
		for (i = 1; i < a; i++)
		{
			p[i] *= p[i - 1];
		}
		op = p[a - 1];
		ans = ((b + 1 - a) * op) + ((b + b + 2 - a) * (1.0 - op));
		for (i = a - 2, j = 2; i >= 0; i--, j+=2)
		{
			op = ((b + j + 1 - a) * p[i]) + ((b + j + b + 2 - a) * (1.0 - p[i]));
			if (op < ans)
				ans = op;
		}
		op = b + 2;
		if (op < ans)
			ans = op;
		printf("Case #%d: %lf\n", t, ans);
	}
	return 0;
}
#include<cstdio>
double ans, p[100010];
void test (double q)
{
	if (ans > q)
	{
		ans = q;
	}
}
int main()
{
	int T;
	scanf ("%d", &T);
	for (int nCase = 1; nCase <= T; ++nCase)
	{
		int a, b;
		scanf ("%d%d", &a, &b);
		for (int i = 0; i < a; ++i)
		{
			scanf ("%lf", &p[i]);
			if (i)
			{
				p[i] = p[i-1] * p[i];
			}
			//printf ("%f ", p[i]);
		}
		//printf ("---\n");
		ans = 10000000;
		for (int k = 0; k < a; ++k)
		{
			double r = p[a-1-k];
			double q = r * (k + b - a + 1) + (1 - r) * (k + b + b - a + 2) + k;
			test (q);
			//printf ("%d %f %f %f\n", k, r, q, ans);
		}
		if (a == b)
		{
			test (p[a-1] + (1 - p[a-1]) * (b + 2));
		}
		else
		{
			test (b + 2);
		}
		printf ("Case #%d: %f\n", nCase, ans);
	}
	return 0;
}

#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
	double C, F, X, rate, ans;
	int T, ncas = 1;
	//FILE *p;
	//freopen("C:\\Users\\think\\Desktop\\B-small-attempt0.in", "r", stdin);
	//p = freopen("C:\\Users\\think\\Desktop\\B.txt", "w", stdout);
	scanf("%d", &T);
	while (T--)
	{
		ans = 0.0;
		scanf("%lf%lf%lf", &C, &F, &X);
		printf ("Case #%d: ", ncas++);
		rate = 2.0;
		if (X < C) printf("%0.7lf\n", X/2.0);
		else
		{
			ans = C/2.0;
			while (1)
			{
				if (ans+(X-C)/rate > ans+X/(rate+F))
				{
					rate += F;
					ans += C/rate;
				}
				else
				{
					ans += (X-C)/rate;
					break;
				}
			}
			printf("%0.7lf\n", ans);
		}
	}

	return 0;
}
#include <cstdio>

int a[222];

void test()
{
	int n;
	int X = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < n; i++) X += a[i];
	for(int i = 0; i < n; i++)
	{
		double low = 0, high = 100;
		while(high - low > 1e-7)
		{
			double mid = (low+high) / 2;
			double score = mid * X / 100.0 + a[i];
			double used = mid;
			for(int j = 0; j < n; j++) if(j != i)
			{
				double nscore = (score - a[j]) / X * 100.0;
				if(nscore > 0) used += nscore;
			}
			if(used > 100) high = mid;
			else low = mid;
		}
		printf("%.7lf ", low);
	}
	printf("\n");
}

int main()
{
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; i++)
	{
		printf("Case #%d: ", i);
		test();
	}
}


	#include <cstdlib>
	#include <cstdio>
	#include <algorithm>

	using namespace std;

	int x[500];

	void work()
	{
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i ++)
			scanf("%d", &x[i]);
		int sum = 0;
		for (int i = 0; i < n; i ++)
			sum += x[i];
		int y[500];
		for (int i = 0; i < n; i ++)
		{
			int y0 = 1;
			y[0] = x[i];
			int z0 = 0;
			int sum0 = 0;
			for (int j = 0; j < n; j ++)
				if (j != i)
				{
					if (x[j] <= x[i])
					{
						z0 ++;
						sum0 += x[i] - x[j];
					}
					if (x[j] > x[i])
					{
						y[y0] = x[j];
						y0 ++;
					}
				}
			y[y0] = 2147483647;
			y0 ++;
//			printf("debug: sum0: %d\n", sum0);
			sort(y, y + y0);
			double ans = 0;
			double leftp = 1;
			if (sum0 >= sum)	printf(" 0.000000");
			else
			{
				leftp = 1 - 1.0 * sum0 / sum;
//				printf("debug: leftp: %lf\n", leftp);
				int last = 0;
				while (leftp > 1e-6)
				{
					z0 ++;
					//printf("debug: z0: %d\n", z0);
					//printf("debug: 1.0 * leftp * sum : %lf\n", 1.0 * leftp * sum);
					//printf("debug: 1.0 * z0 * (x[last + 1] - x[last]) : %lf\n", 1.0 * z0 * (y[last + 1] - y[last]));
					if (1.0 * leftp * sum < 1.0 * z0 * (y[last + 1] - y[last]))
					{
						ans += leftp / z0;
						leftp = 0;
					}
					else
					{
						ans += 1.0 * (y[last + 1] - y[last]) / sum;
						leftp -= 1.0 * (y[last + 1] - y[last]) * z0 / sum;
					}
					last ++;
				}
				printf(" %lf", ans * 100);
			}
		}
		printf("\n");
	}

	int main()
	{
		freopen("a.in", "r", stdin);
		freopen("a.out", "w", stdout);
		int t;
		scanf("%d", &t);
		for (int i = 1; i <= t; i ++)
		{
			printf("Case #%d:", i);
			work();
		}
		return 0;
	}

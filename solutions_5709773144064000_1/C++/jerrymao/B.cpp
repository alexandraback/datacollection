#include <cstdio>

char __input[64];
double c;
double f;
double x;
int t;

int main()
{
	printf("Input file = "); fflush(stdout);
	scanf("%s", __input);
	freopen(__input, "r", stdin);
	freopen("out.B.txt", "w", stdout);

	scanf("%d", &t);
	for (int _ = 1;_ <= t;_++)
	{
		scanf("%lf%lf%lf", &c, &f, &x);
		double ans = 500000000000; // :D
		double time = 0; double rate = 2;
		for (int i = 0;;i++)
		{
			double temptime = x / rate;
			if (time + temptime < ans)
				ans = time + temptime;
			else break;
			time += (c / rate);
			rate += f;
		}
		printf("Case #%d: %.7lf\n", _, ans);
	}

	return 0;
}

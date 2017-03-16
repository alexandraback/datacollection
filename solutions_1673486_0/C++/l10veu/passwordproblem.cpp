#include <cstdio>

int main()
{
	int t;
	scanf("%d", &t);
	for (int c=1; c<=t; ++c)
	{
		int a, b;
		scanf("%d %d", &a, &b);

		double ev = b + 2;
		int tn = a + b - 1;

		double cp = 1;
		
		for (int i=0; i<a; ++i)
		{
			double p;
			scanf("%lf", &p);

			cp = p * cp;

			double tev = cp*tn + (1-cp)*(tn+b+1);
			if (tev < ev)
				ev = tev;

			tn -= 2;
		}

		printf("Case #%d: %.6f\n", c, ev);
	}
	
	return 0;
}
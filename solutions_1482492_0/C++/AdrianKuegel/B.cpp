#include <stdio.h>
#include <math.h>
#include <assert.h>

double t[1000], x[1000];

int main() {
	int tc, N, A;
	double D;
	scanf("%d", &tc);
	for (int scen=1; scen<=tc; ++scen)
	{
		printf("Case #%d:\n", scen);
		scanf("%lf %d %d", &D, &N, &A);
		int n = N;
		for (int i=0; i<N; ++i)
		{
			scanf("%lf %lf", &t[i], &x[i]);
			if (x[i] >= D && n == N)
			{
				if (i == 0)
				{
					n = 1;
					continue;
				}
				assert(t[i]-t[i-1] > 1e-9);
				double v = (x[i] - x[i-1]) / (t[i] - t[i-1]);
				// x[i-1] + t * v = D -> t = (D-x[i-1])/v
				double T = (D - x[i-1]) / v;
				t[i] = T;
				x[i] = D;
				n = N;
			}
		}
		for (int i=0; i<A; ++i)
		{
			double a;
			scanf("%lf", &a);
			// solve for N = 2
			// check how fast we can be at the end without the car in front
			// 0.5 * a * t * t = D
			// t = sqrt(4*0.5*a*D)/a;
			double t1 = sqrt(2*D*a)/a;
			if (t1 < t[n-1])
			{
				printf("%.10lf\n", t[n-1]);
			}
			else
			{
				printf("%.10lf\n", t1);
			}
		}
	}
	return 0;
}

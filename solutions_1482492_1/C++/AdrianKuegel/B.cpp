#include <stdio.h>
#include <math.h>
#include <assert.h>

double t[1000000], x[1000000];

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
			// maximum velocity to reach point x[i]
			double curT = 0, curPos = 0, curVel = 0;
			for (int i=0; i<n; ++i)
			{
				assert(curPos <= x[i]);
				double ti = (sqrt(curVel * curVel + 4*0.5*a*(x[i]-curPos))-curVel)/a;
				curVel = curVel + a * ti;
				curT += ti;
				if (curT < t[i])
				{
					curT = t[i];
				}
				curPos = x[i];
			}
			printf("%.10lf\n", curT);
		}
	}
	return 0;
}

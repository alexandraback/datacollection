#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
	int tc;
	scanf("%d", &tc);
	for (int ti = 1;ti <= tc;ti++)
	{
		printf("Case #%d:\n", ti);
		double D;
		int N, Q;
		scanf("%lf %d %d", &D, &N, &Q);
		vector< pair<double, double> > points;
		for (int i = 0;i < N;i++)
		{
			double t, x;
			scanf("%lf %lf", &t, &x);
			points.push_back(make_pair(t, x));
		}

		for (int i = 0;i < Q;i++)
		{
			double accel;
			scanf("%lf", &accel);

			double st = 0;
			double ed = 1e10;
			for (int it = 0;it < 100;it++)
			{
				double wait = (st + ed) / 2;

				int j;
				for (j = 0;j < N - 1;j++)
				{
					double pos = (points[j].first <= wait) ? 0.0f : (0.5 * accel * (points[j].first - wait) * (points[j].first - wait));
					if (pos > points[j].second)
						break;
				}
				if (j == N - 1)
				{
					double ta = points[j - 1].first;
					double tb = points[j].first;
					double xa = points[j - 1].second;
					double xb = points[j].second;

					double ratio = (D - xa) / (xb - xa);
					double eff_t = ta + (tb - ta) * ratio;

					double pos = (eff_t <= wait) ? 0.0f : (0.5 * accel * (eff_t - wait) * (eff_t - wait));
					if (pos <= D)
						j++;
				}
				
				if (j == N)
					ed = wait;
				else
					st = wait;
			}
			printf("%.10lf\n", (st + ed) / 2 + sqrt(D * 2.0 / accel));
		}
	}
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#include <vector>
#include <list>
#include <map>

#include <algorithm>

using namespace std;

int main(int argc, char **argv)
{
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);

	int testcount;
	scanf("%d", &testcount);
	for(int testnum = 1; testnum <= testcount; testnum++)
	{
		long double D;
		int N, A;

		scanf("%lf %d %d", &D, &N, &A);

		vector<long double> t(N);
		vector<long double> x(N);
		vector<long double> amax(A);

		for(int i = 0; i < N; i++)
		{
			scanf("%lf %lf", &t[i], &x[i]);
		}

		t.insert(t.begin(), 0);
		x.insert(x.begin(), 0);
		N++;

		for(int i = 0; i < N; i++)
		{
			if(fabs(x[i] - D) < 1.e-9)
			{
				N = i + 1;

				break;
			}
			else if(x[i] > D)
			{
				long double delta_x = x[i] - D;
				long double speed = (x[i] - x[i - 1])/(t[i] - t[i - 1]);
				long double delta_t = delta_x / speed;
				t[i] -= delta_t;
				x[i] = D;
				N = i + 1;

				break;
			}
		}
		
		// correct x, t : x_last <- D;

		for(int i = 0; i < A; i++)
		{
			scanf("%lf", &amax[i]);
		}

		printf("Case #%d:\n", testnum);

		for(int k = 0; k < A; k++)
		{
			long double v0 = 0;
			long double t_sum = 0;
			long double x0 = 0;

			for(int i = 1; i < N; i++)
			{
				long double delta_t = t[i] - t[i - 1];
				// long double delta_x = x[i] - x[i - 1];

				if( fabs(delta_t) < 1.e-9 )
				{
					continue;
				}

				long double a = min(amax[k], 2 * ((x[i] - x0) - v0 * delta_t) / (delta_t * delta_t));

				assert(v0 + a * delta_t > -1.e-8);

				t_sum += (sqrt(v0*v0 + 2 * (x[i] - x0) * a) - v0) / a;

				v0 += a * delta_t;

				x0 = x[i];
			}

			printf("%0.8lf\n", t_sum);
		}
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}
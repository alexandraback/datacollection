#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++)
	{
		vector<double> p2;
		vector<double> p;
		int A, B;

		scanf("%d %d", &A, &B);

		double cumul = 0;
		for (int k = 0; k < A; k++)
		{
			double val;
			scanf("%lf", &val);
			p.push_back(val);

			val = 1 - val;

			cumul += (1.0 - cumul) * val;
			p2.push_back(cumul);
			//printf("Cumul%d: %lf\n", k, cumul);
		}

		double bestavg = B + 2;
		for (int backsteps = 0; backsteps < A; backsteps++)
		{
			double base = p2[A - backsteps - 1];
			double nowavg = backsteps * 2 + (B - A) + 1 + base * (B + 1);
			if (nowavg < bestavg)
				{
					bestavg = nowavg;
					//printf("Backsteps %d %lf\n", backsteps, nowavg);
			}
		}

		printf("Case #%d: %.9lf\n", t + 1, bestavg);
	}
}
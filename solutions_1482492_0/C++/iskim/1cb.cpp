#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

double x[20000], t[20000];

int main()
{
	int TT;
	scanf("%d",&TT);
	for (int tt = 1; tt <= TT; tt++)
	{
		printf("Case #%d:\n", tt);
		double D;int N,A;
		scanf("%lf%d%d",&D,&N,&A);
		for (int i = 0; i < N; i++)
		{
			scanf("%lf%lf",&t[i],&x[i]);
		}

		for (int i = 0; i < A; i++)
		{
			double g;
			scanf("%lf",&g);
			double ans = sqrt(2 * D / g);
			if (N == 2) ans = max(
				ans, 
				(D - x[0]) / ((x[1] - x[0]) / (t[1] - t[0]))
				);
			printf("%lf\n", ans);
		}
	}
	return 0;
}
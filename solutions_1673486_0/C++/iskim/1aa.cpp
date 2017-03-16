#include <stdio.h>
#include <algorithm>
using namespace std;

double d[1000000];
double correct[1000000], wrong[1000000];

int main()
{



	int T;
	scanf("%d",&T);
	for (int TT = 1; TT <= T; TT++)
	{
		int A,B;
		scanf("%d%d",&A,&B);
		for (int i = 1; i <= A; i++)
		{
			scanf("%lf",&d[i]);
		}
		correct[1] = d[1];
		wrong[1] = 1 - d[1];

		for (int i = 2; i <= A; i++)
		{
			correct[i] = correct[i-1] * d[i];
			wrong[i] = correct[i-1] * (1 - d[i]);
		}

		double ans = (B - A + 1) * correct[A] + (B - A + 1 + B + 1) * (1 - correct[A]);

		double sum = correct[A];

		for (int i = A; i >= 1; i--)
		{
			sum += wrong[i];
			int k = A + 1 - i;
			ans = min(ans, (B - A + 2*k + 1) * sum + (B - A + 2 * k + 1 + B + 1) * (1 - sum));
		}

		ans = min(ans, 1. + B + 1);
		printf("Case #%d: %f\n",TT,  ans);
	}
	return 0;
}
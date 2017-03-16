#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	for(int testcase = 1; testcase <= T; testcase ++)
	{
		int a, b;
		scanf("%d%d",&a,&b);

		double ans = min(b + 2, a + b + 1);
		double correct = 1;

		for(int i = 0; i < a; i ++)
		{
			double prob;
			scanf("%lf",&prob);

			correct *= prob;

			double expect = (a - i - 1) + correct * (b - i) + (1 - correct) * (b - i + b + 1);
			ans = min(ans, expect);
		}

		printf("Case #%d: %.10f\n", testcase, ans);
	}
	return 0;
}
#include <stdio.h>
#define MIN( a, b) ( ( a) < ( b) ? ( a) : ( b))
#define MAXB 100000

double p[MAXB];

int main()
{
	int Tcases;
	scanf("%d", &Tcases);
	int cases;
	for ( cases = 0; cases < Tcases; cases++)
	{
		int A, B;
		scanf("%d %d", &A, &B);
		int i;
		for ( i = 0; i < A; i++)
		{
			scanf("%lf", p + i);
		}

		double ans = B + 2;
		double prob = 1.0;
		for ( i = 0; i <= A; i++)
		{
			double cur = B + B + 2 + A - 2 * i - ( B + 1) * prob;
			ans = MIN( ans, cur);
//			printf("%d %lf\n", i, cur);
			prob *= p[i];
		}

		printf("Case #%d: %lf\n", cases + 1, ans);
	}

	return 0;
}

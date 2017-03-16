#include <stdio.h>
#include <string.h>
#define MAXN 10010

double dp[MAXN], sum[MAXN];
double p[MAXN];

void Solve()
{
	double tot, tmp, ret = 1000000000;
	int i, A, B;
	scanf("%d%d", &A, &B);
	for (i = 1; i <= A; i++)
		scanf("%lf", p + i);
	tot = 1;
	dp[0] = sum[0] = 0;
	for (i = 1; i <= A; i++)
	{
		dp[i] = (1 - dp[i - 1]) * (1 - p[i]);
		sum[i] = sum[i - 1] + dp[i];
	}
	// for (i = 1; i <= A; i++)
		// printf("%.6f ", sum[i]);
	// printf("\n");
	for (i = 0; i <= A; i++)
	{
		tmp = sum[A - i] * (i * 2 + B - A + 1 + B + 1) + (1 - sum[A - i]) * (i * 2 + B - A + 1);
		if (ret - tmp > 1e-8)
			ret = tmp;
		// printf("tmp = %f\n", tmp);
	}
	tmp = 1 + B + 1;
	if (ret - tmp > 1e-8)
			ret = tmp;
	printf("%.6f\n", ret);
}

int main()
{
	int cas;
	scanf("%d", &cas);
	for (int i = 1; i <= cas; i++)
	{
		printf("Case #%d: ", i);
		Solve();
	}
	return 0;
}


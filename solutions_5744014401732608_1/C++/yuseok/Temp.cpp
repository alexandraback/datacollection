#include<stdio.h>

int main(void)	{
	int test, T;
	int i, j, n;
	long long bi[55];
	long long m;

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &T);

	bi[1] = bi[2] = 1;
	for (i = 3; i <= 50; i++)
		bi[i] = bi[i - 1] * 2;

	for (test = 1; test <= T; test++)	{
		int A[55][55] = { 0 };
		
		scanf("%d%lld", &n, &m);

		printf("Case #%d: ", test);

		if (m > bi[n])
			printf("IMPOSSIBLE\n");
		else
		{
			printf("POSSIBLE\n");

			for (i = 1; i < n; i++)	{
				for (j = i + 1; j < n; j++)
					A[i][j] = 1;
			}

			for (i = n - 1; i >= 1; i--)	{
				if (m >= bi[i])	{
					m -= bi[i];
					A[i][n] = 1;
				}
			}

			for (i = 1; i <= n; i++)	{
				for (j = 1; j <= n; j++)
					printf("%d", A[i][j]);
				printf("\n");
			}
		}
	}

	return 0;
}
#include<stdio.h>

int ans[100005];

int main(void)	{
	int test, T;
	int J, P, S, K;
	int i, j, p, s, n;
	int jp, js, ps;

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &T);

	for (test = 1; test <= T; test++)	{
		int JP[100] = { 0 };
		int JS[100] = { 0 };
		int PS[100] = { 0 };

		scanf("%d%d%d%d", &J, &P, &S, &K);

		n = 0;
		for (s = 0; s < S; s++)	{
			for (p = 0; p < P; p++)	{
				for (j = 0; j < J; j++)	{
					jp = j * 10 + p;
					js = j * 10 + s;
					ps = p * 10 + s;

					if (JP[jp] < K && JS[js] < K && PS[ps] < K)	{
						ans[n++] = j * 100 + p * 10 + s;
						JP[jp]++;
						JS[js]++;
						PS[ps]++;
					}
				}
			}
		}

		printf("Case #%d: %d\n", test, n);
		for (i = 0; i < n; i++)
			printf("%d %d %d\n", ans[i] / 100 + 1, ans[i] / 10 % 10 + 1, ans[i] % 10 + 1);
	}
}
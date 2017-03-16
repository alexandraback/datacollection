#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL pK[111];

int main()
{
	LL T, K, C, S, ans;

	scanf("%lld\n", &T);
	for (LL t = 1; t <= T; t++)
	{
		scanf("%lld%lld%lld", &K, &C, &S);

		printf("Case #%lld:", t);
		if (S < (K + C - 1) / C)
		{
			printf(" IMPOSSIBLE\n");
			continue;
		}

		pK[0] = 1;
		for (int i = 1; i <= C; i++)
			pK[i] = pK[i - 1] * K;

		for (int i = 0; i < K; i += C)
		{
			ans = 0;
			for (int j = 0; j < C && (i + j) < K; j++)
				ans += pK[C - 1 - j] * (i + j);
			printf(" %lld", ans + 1);
		}
		printf("\n");
	}

	return 0;
}
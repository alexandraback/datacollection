#include <cstdio>
#include <algorithm>
#include <memory.h>

using namespace std;

int A, B;
long long dp[101][101];
long long cntA[101], cntB[101];
int typeA[101], typeB[101];

int main()
{
	int tc;
	scanf("%d", &tc);
	for (int ti = 1;ti <= tc;ti++)
	{
		scanf("%d %d", &A, &B);
		for (int i = 0;i < A;i++)
			scanf("%lld %d", &cntA[i], &typeA[i]);
		for (int i = 0;i < B;i++)
			scanf("%lld %d", &cntB[i], &typeB[i]);

		memset(dp, 0, sizeof(dp));

		for (int a = 0;a < A;a++)
		{
			for (int b = 0;b < B;b++)
			{
				long long cur = dp[a][b];
				for (int type = 1;type <= 100;type++)
				{
					long long sumA = 0, sumB = 0;
					int na = a, nb = b;
					for (;na <= A && nb <= B;)
					{
						if (sumA < sumB)
						{
							if (na == A) break;
							if (typeA[na] == type)
								sumA += cntA[na];
							na++;
						}
						else
						{
							if (nb == B) break;
							if (typeB[nb] == type)
								sumB += cntB[nb];
							nb++;
						}
						if (dp[na][nb] < cur + min(sumA, sumB))
							dp[na][nb] = cur + min(sumA, sumB);
					}
				}
			}
		}

		long long ans = 0;
		for (int a = 0;a <= A;a++)
			for (int b = 0;b <= B;b++)
				if (ans < dp[a][b])
					ans = dp[a][b];

		printf("Case #%d: %lld\n", ti, ans);
	}
}

#include <cstdio>

const int INF = 100000000;

inline int max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int kase = 1; kase <= T; ++kase)
	{
		int D;
		scanf("%d", &D);
		int a[D];
		int maxd = 0;
		for (int i = 0; i < D; ++i)
		{
			scanf("%d", &a[i]);
			maxd = max(maxd, a[i]);
		}
		int ans = INF;
		for (int d = 1; d <= maxd; ++d)
		{
			int minans = d;
			for (int i = 0; i < D; ++i)
			{
				if (a[i] > d)
				{
					minans += (a[i] - 1) / d;
				}
			}
			if (minans < ans)
			{
				ans = minans;
			}
		}
		printf("Case #%d: %d\n", kase, ans);
	}
	return 0;
}

#include <cstdio>

int cnt[2501];

int main()
{
	int T;
	scanf("%d", &T);
	for (int kase = 1; kase <= T; ++kase)
	{
		int N;
		scanf("%d", &N);
		for (int i = 1; i <= 2500; ++i)
			cnt[i] = 0;
		for (int i = 0; i < N * (N + N - 1); ++i)
		{
			int t;
			scanf("%d", &t);
			cnt[t]++;
		}
		printf("Case #%d:", kase);
		for (int i = 1; i <= 2500; ++i)
			if (cnt[i] & 1)
				printf(" %d", i);
		puts("");
	}
	return 0;
}

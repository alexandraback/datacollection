#define _SCL_SECURE_NO_WARNINGS 
#define _CRT_SECURE_NO_WARNINGS 

#include <cstdio>

const int MAX_N = 1 << 20;
int cached[MAX_N];

int solve(int n)
{
	if (n == 0) return -1;
	bool seen[10] = {};
	int seen_num = 0;
	for (int m = n; ; m += n)
	{
		int z = m;
		while (z > 0)
		{
			int d = z % 10;
			z /= 10;
			if (!seen[d])
			{
				seen[d] = true;
				++seen_num;
				if (seen_num >= 10) return m;
			}
		}
	}
}

int main()
{
	for (int i = 0; i < MAX_N; ++i)
	{
		cached[i] = solve(i);
		//printf("%d: %d\n", i, cached[i]);
	}

	int T;
	scanf("%d", &T);
	for (int cs = 1; cs <= T; ++cs)
	{
		int N;
		scanf("%d", &N);
		//int ans = solve(N);
		int ans = cached[N];
		printf("Case #%d: ", cs);
		if (ans < 0) puts("INSOMNIA"); else printf("%d\n", ans);
	}
	return 0;
}
#include <cstdio>

char s[1001];

int main()
{
	int T;
	scanf("%d", &T);
	for (int kase = 1; kase <= T; ++kase)
	{
		int N;
		scanf("%d %s", &N, s);
		long long c = 0;
		long long ans = 0;
		for (int i = 0; i <= N; ++i)
		{
			if (s[i] > '0' && i > c)
			{
				ans += i - c;
				c = i;
			}
			c += s[i] - '0';
		}
		printf("Case #%d: %lld\n", kase, ans);
	}
	return 0;
}

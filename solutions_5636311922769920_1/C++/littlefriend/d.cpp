#include <cstdio>
#include <cstring>
int main(int argc, char** argv)
{
	int n;
	if (argc > 1)
	{
		freopen(argv[1], "r", stdin);
		freopen(argv[2], "w", stdout);
	}
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		int k, c, s;
		scanf("%d%d%d", &k, &c, &s);
		if (c*s < k)
		{
			printf("Case #%d: IMPOSSIBLE\n", i+1);
			continue;
		}
		printf("Case #%d:", i+1);
		int tk = 0;
		for (int j = 0; j < (k+c-1)/c; ++j)
		{
			long long ans = 0;
			for (int l = 0; l < c; ++l)
			{
				ans = ans * k + tk;
				if (tk < k-1)
					++tk;
			}
			printf(" %lld", ans+1);
		}
		puts("");
	}
	return 0;
}
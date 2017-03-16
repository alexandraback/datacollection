#include <cstdio>
const int maxt = 100, maxk = 100, maxc = 100;
int t, k, c, s;
int main()
{
	scanf("%d", &t);
	for(int Case = 1; Case <= t; ++Case)
	{
		scanf("%d%d%d", &k, &c, &s);
		if(s * c < k)
		{
			printf("Case #%d: IMPOSSIBLE\n", Case);
			continue;
		}
		printf("Case #%d:", Case);
		for(int i = 1, j = 0; i <= s && j < k; ++i)
		{
			long long val = 0;
			for(int o = 0; o < c && j < k; ++o, ++j)
				val = val * k + j;
			printf(" %lld", val + 1);
		}
		putchar('\n');
	}
	return 0;
}

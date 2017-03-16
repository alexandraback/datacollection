#include <cstdio>

int main()
{
	int T, K, C, S;
	scanf("%d", &T);
	for (int t=0; t<T; ++t)
	{
		scanf("%d%d%d", &K, &C, &S);
		printf("Case #%d:", t+1);
		int min = K/C;
		if (min * C < K)
			++min;
		if (S < min)
		{
			printf(" IMPOSSIBLE\n");
			continue;
		}
		for (int i = 0; i < K; )
		{
			long long r = 0;
			long long b = 1;
			int c = C;
			if (c > K)
				c = K;
			for (int j = 0; j < c-1; ++j)
				b *= K;
			for (int j = 0; j < c; ++j)
			{
				r += b * i;
				//printf("(%lld * %d)", b, i);
				++i;
				if (i == K)
					break;
				b /= K;
			}
			printf(" %lld", r+1);
		}
		printf("\n");
	}
	return 0;
}

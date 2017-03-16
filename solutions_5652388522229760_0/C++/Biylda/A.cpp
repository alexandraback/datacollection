#include <stdio.h>

typedef unsigned long long ULL;

int main(int argc, char **argv)
{
	const int seenAll = (1 << 10) - 1;
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; ++t)
	{
		int N;
		scanf("%d", &N);
		printf("Case #%d: ", t+1);
		if (N == 0)
		{
			printf("INSOMNIA\n");
		}
		else
		{
			int seen = 0;
			ULL n = 0;
			while (seen != seenAll)
			{
				n += N;
				for (ULL d = n; d > 0; d /= 10)
				{
					seen |= 1 << (d % 10);
				}
			}
			printf("%llu\n", n);
		}
	}
	return 0;
}

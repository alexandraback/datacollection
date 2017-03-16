#include <stdio.h>

int main()
{
	int T;
	scanf("%d", &T);
	int test;
	for(test = 1; test <= T; test++)
	{
		int K, C, S;
		scanf("%d%d%d", &K, &C, &S);
		printf("Case #%d: ", test);
		if(S * C < K)
			printf("IMPOSSIBLE\n");
		else
		{
			int i, j;
			int digit = 0;
			for(i = 0; i < S; i++)
			{
				unsigned long long int number = 0;
				for(j = 0; j < C; j++)
				{
					number *= K;
					number += digit % K;
					digit++;
				}
				printf("%lld ", number + 1);
				if(digit >= K)
					break;
			}
			printf("\n");
		}
	}
}

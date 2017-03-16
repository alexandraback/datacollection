#include <stdio.h>

int b;
long long int M, sum[60];

int main()
{
	int i, k, t;
	scanf("%d", &t);
	sum[0] = sum[1] = 1;
	for(i = 2; i < 51; i++)
		sum[i] = sum[i - 1] * 2;
	for(k = 0; k < t; k++)
	{
		scanf("%d%lld", &b, &M);
		if(M > sum[b - 1])
			printf("Case #%d: IMPOSSIBLE\n", k + 1);
		else if(M == sum[b - 1])
		{
			printf("Case #%d: POSSIBLE\n", k + 1);
			int j;
			for(i = 0; i < b; i++)
			{
				for(j = 0; j <= i; j++)
					printf("0");
				for(j = i + 1; j < b; j++)
					printf("1");	
				printf("\n");
			}
		}
		else
		{
			int lis[60];
			long long int cur = M;
			i = 1;
			lis[0] = 0;
			while(cur)
			{
				lis[i++] = cur % 2;
				cur /= 2;
			}
			while(i < b)
				lis[i++] = 0;
			printf("Case #%d: POSSIBLE\n", k + 1);
			int j;
			for(i = 0; i < b; i++)
			{
				for(j = 0; j <= i; j++)
					printf("0");
				for(j = i + 1; j < b - 1; j++)
					printf("1");
				if(i != b - 1)
					printf("%d", lis[i]);
				printf("\n");
			}
		}
	}
	return 0;
}

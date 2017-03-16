#include<cstdio>

int main()
{
	int tcc;
	scanf("%d", &tcc);
	for(int tc = 1; tc <= tcc; tc++)
	{
		printf("Case #%d: ", tc);
		int b;
		long long m;
		scanf("%d %lld", &b, &m);
		if(m > (1LL<<(b-2)))
		{
			printf("IMPOSSIBLE\n");
			continue;
		}
		
		long long cur = (1<<(b-3));
		int result[b];
		result[0] = 0;
		for(int i = 1; i < b - 1; i++)
		{
			if(m >= cur)
			{
				m -= cur;
				result[i] = 1;
			}
			else	result[i] = 0;
			cur /= 2;
		}

		if(m == 1)	result[b-1] = 1;
		else	result[b-1] = 0;

		printf("POSSIBLE\n");
		for(int i = 0; i < b; i++)
			printf("%d", result[i]);
		printf("\n");
		for(int i = 1; i < b; i++)
		{
			for(int j = 0; j < b; j++)
			{
				if(i >= j)	printf("0");
				else	printf("1");
			}
			printf("\n");
		}
	}
}

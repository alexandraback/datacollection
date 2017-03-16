#include <bits/stdc++.h>
using namespace std;

char str[33];

int main()
{
	int T, N, J;

	scanf("%d", &T);
	for (int t = 1; t <= T; t++)
	{
		scanf("%d%d", &N, &J);
		printf("Case #%d: \n", t);

		// "11"
		for (int i = 0; i < (1 << ((N / 2) - 2)) && J; i++)
		{
			memset(str, '0', sizeof(str));
			str[N - 1] = str[N - 2] = '1';
			str[1] = str[0] = '1';
			str[N] = '\0';
			for (int j = 1; (1 << (j - 1)) <= i; j++)
			{
				if (i & (1 << (j - 1)))
				{
					str[2 * j] = '1';
					str[2 * j + 1] = '1';
				}
			}
			printf("%s ", str);
			for (int b = 2; b <= 10; b++)
				printf("%d ", b + 1);
			printf("\n");
			J--;
		}

		// "101"
		for (int i = 0; i < (1 << ((N / 3) - 2)) && J; i++)
		{
			memset(str, '0', sizeof(str));
			str[N - 1] = str[N - 3] = '1';
			str[2] = str[0] = '1';
			str[N] = '\0';
			for (int j = 1; (1 << (j - 1)) <= i; j++)
			{
				if (i & (1 << (j - 1)))
				{
					str[3 * j] = '1';
					str[3 * j + 2] = '1';
				}
			}
			printf("%s ", str);
			for (int b = 2; b <= 10; b++)
				printf("%d ", b * b + 1);
			printf("\n");
			J--;
		}

		// "111"
		for (int i = 0; i < (1 << ((N / 3) - 2)) && J; i++)
		{
			memset(str, '0', sizeof(str));
			str[N - 1] = str[N - 2] = str[N - 3] = '1';
			str[2] = str[1] = str[0] = '1';
			str[N] = '\0';
			for (int j = 1; (1 << (j - 1)) <= i; j++)
			{
				if (i & (1 << (j - 1)))
				{
					str[3 * j] = '1';
					str[3 * j + 1] = '1';
					str[3 * j + 2] = '1';
				}
			}
			printf("%s ", str);
			for (int b = 2; b <= 10; b++)
				printf("%d ", b * b + b + 1);
			printf("\n");
			J--;
		}

		// "1001"
		for (int i = 0; i < (1 << ((N / 4) - 2)) && J; i++)
		{
			memset(str, '0', sizeof(str));
			str[N - 1] = str[N - 4] = '1';
			str[3] = str[0] = '1';
			str[N] = '\0';
			for (int j = 1; (1 << (j - 1)) <= i; j++)
			{
				if (i & (1 << (j - 1)))
				{
					str[4 * j] = '1';
					str[4 * j + 3] = '1';
				}
			}
			printf("%s ", str);
			for (int b = 2; b <= 10; b++)
				printf("%d ", b * b * b + 1);
			printf("\n");
			J--;
		}
	}

	return 0;
}
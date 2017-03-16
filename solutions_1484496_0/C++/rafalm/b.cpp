#include <cstdio>
int main()
{
	int T, test, N, i, s[20], j, sum;
	int t[2000001] = {0, };
	bool b;

	scanf("%d", &T);
	for (test = 1; test <= T; test++)
	{
		for (i = 0; i < 2000001; i++)
		{
			t[i] = 0;
		}

		scanf("%d", &N);
		for (i = 0; i < N; i++)
		{
			scanf("%d", &s[i]);
		}

		b = false;
		for (i = 1; i < (1 << N); i++)
		{
			sum = 0;
			for (j = 0; j < N; j++)
			{
				if (i & (1 << j))
				{
					sum += s[j];
				}
			}

			if (t[sum])
			{
				printf("Case #%d:\n", test);
				b = true;
				for (j = 0; j < N; j++)
				{
					if (t[sum] & (1 << j))
					{
						printf("%d ", s[j]);
					}
				}
				printf("\n");
				for (j = 0; j < N; j++)
				{
					if (i & (1 << j))
					{
						printf("%d ", s[j]);
					}
				}
				printf("\n");
				break;
			}
			else
			{
				t[sum] = i;
			}
		}

		if (!b)
		{
			printf("Case #%d: Impossible\n", test);
		}
	}

	return 0;
}

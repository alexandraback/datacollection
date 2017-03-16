#include <cstdio>
#include <cstring>

int move2(int a, int count, int digits)
{
	int i, p1 = 1, p2 = 1;

	for (i = 0 ; i < count; i++)
	{
		if (i < digits)
		{
			p1 *= 10;
		}
		else
		{
			p2 *= 10;
		}
	}

	return ((a % p2) * p1) + (a / p2);
}

int main()
{
	int T, A, B, i, j, k, v, p, count, result;
	int b[2000001];

	scanf("%d", &T);
	for (i = 1; i <= T; i++)
	{
		scanf("%d", &A);
		scanf("%d", &B);

		p = 10;
		count = 1;
		result = 0;
		memset(b, 0, sizeof(b));

		while (A >= p)
		{
			p *= 10;
			count++;
		}
		for (j = A; j <= B; j++)
		{
			if (j == p)
			{
				p *= 10;
				count++;
			}

			for (k = 1; k < count; k++)
			{
				v = move2(j, count, k);
				if (j < v && v <= B && b[v] < j)
				{
					result++;
					b[v] = j;
				}
			}
		}

		printf("Case #%d: %d\n", i, result);
	}

	return 0;
}

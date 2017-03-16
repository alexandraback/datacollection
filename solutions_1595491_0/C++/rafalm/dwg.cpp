#include <cstdio>
#include <cstdlib>

int compare (const void * a, const void * b)
{
	return ( *(int*)a - *(int*)b );
}

int GetScore(int v)
{
	return (v % 3) ? (v / 3 + 1) : (v / 3);
}

int GetSurprise(int v)
{
	return (v >= 2) ? GetScore(v + 2) : GetScore(v);
}

int main()
{
	int T, N, S, p, t[100], i, j, result;

	scanf("%d", &T);
	for (i = 1; i <= T; i++)
	{
		scanf("%d", &N);
		scanf("%d", &S);
		scanf("%d", &p);
		for (j = 0; j < N; j++)
		{
			scanf("%d", &t[j]);
		}
		qsort(t, N, sizeof(int), compare);

		result = 0;
		for (j = N - 1; j >= 0; j--)
		{
			if (GetScore(t[j]) >= p)
			{
				result++;
			}
			else if (S && GetSurprise(t[j]) >= p)
			{
				result++;
				S--;
			}
		}

		printf("Case #%d: %d\n", i, result);
	}

	return 0;
}

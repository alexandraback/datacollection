#include <cstdio>

#define MIN(a, b) (a < b ? a : b)
#define MAX(a, b) (a > b ? a : b)

int main()
{
	int T, test, N, M, i, j, k, l;
	unsigned long long a[101], A[101], b[101], B[101], t[101][101][3], min_v, resp;

	scanf("%d", &T);
	for (test = 1; test <= T; test++)
	{
		scanf("%d", &N);
		scanf("%d", &M);
		for (i = 0; i < N; i++)
		{
			scanf("%llu", &a[i]);
			scanf("%llu", &A[i]);
		}
		for (i = 0; i < M; i++)
		{
			scanf("%llu", &b[i]);
			scanf("%llu", &B[i]);
		}

		for (i = 0; i < N; i++)
		{
			for (j = 0; j < M; j++)
			{
				t[i][j][0] = 0;
				t[i][j][1] = 0;
				t[i][j][2] = 0;
			}
		}

		resp = 0;
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < M; j++)
			{
				t[i][j][0] += a[i];
				t[i][j][1] += b[j];
				if (A[i] == B[j])
				{
					min_v = MIN(t[i][j][0], t[i][j][1]);
					t[i][j][0] -= min_v;
					t[i][j][1] -= min_v;
					t[i][j][2] += min_v;
					resp = MAX(resp, t[i][j][2]);

					for (k = i; k < N; k++)
					{
						for (l = j; l < M; l++)
						{
							if (t[i][j][2] > t[k][l][2] && i != j)
							{
								if (A[i] == A[k])
								{
									t[k][l][0] += t[i][j][0];
								}
								if (B[j] == B[l])
								{
									t[k][l][1] += t[i][j][1];
								}
								t[k][l][2] = t[i][j][2];
							}
						}
					}
				}
			}
		}
		printf("Case #%d: %llu\n", test, resp);
	}

	return 0;
}

/* CGJ 2012 R1c */

#include <stdio.h>
#include <string.h>

#define MAX 105
#define min(a,b) (a<b?a:b)

unsigned long long map[MAX][MAX];

unsigned long long A[MAX][2];
unsigned long long B[MAX][2];

int
main ()
{
	int cases, cases_r=0, n, m, i, j, last_i;
	unsigned long long last_t, last_q, k, curr_q;

	scanf("%d", &cases);

	for (i=0; i<MAX; ++i)
		map[i][0] = map[0][i] = 0;

	while (cases_r++<cases)
	{
		scanf("%d%d", &n, &m);

		for (i=1; i<=n; ++i)
			scanf("%llu%llu", &A[i][0], &A[i][1]);

		for (i=1; i<=m; ++i)
			scanf("%llu%llu", &B[i][0], &B[i][1]);

		last_q = curr_q = last_q = k = last_t = 0;

		for (i=1; i<=n; ++i)
			for (j=1; j<=m; ++j)
			{
				if (A[i][1] == B[j][1])
				{
//printf("-%llu. %llu. ", min(A[i][0], B[j][0]), map[i-1][j-1]);
					k = min(A[i][0], B[j][0]);
					map[i][j] = map[i-1][j-1] + k;
					if (B[j][0] - k > last_q)
					{
						last_i = j;
						last_t = B[j][1];
						last_q = B[j][0] - k;
						curr_q = map[i][j];
					}
				}
				else
				{
					if (map[i-1][j] > map[i][j-1])
						map[i][j] = map[i-1][j];
					else
						map[i][j] = map[i][j-1];
					if (A[i][1] == last_t && (curr_q + min(A[i][0], last_q)) > map[i][j])
					{
						k = min(A[i][0], last_q);
						map[i][j] = (curr_q + k);
						last_q -= k;
						curr_q = map[i][j];
					}
				}
//printf("%d,%d: %llu\n", i, j, map[i][j]);
			}

		printf("Case #%d: %llu\n", cases_r, map[n][m]);
	}

	return 0;
}


#include <stdio.h>
#include <string.h>

#define NMAX 111
#define VMAX 111

char done[NMAX][NMAX];
int A[NMAX][NMAX], cnt[VMAX];
int M, N, i, j, k, num_done, value, ok;

int main() {
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B1.out", "w", stdout);

	int T, te;
	
	scanf("%d", &T);
	for (te = 1; te <= T; te++) {
		scanf("%d %d", &M, &N);

		memset(cnt, 0, sizeof(cnt));
		for (i = 1; i <= M; i++)
			for (j = 1; j <= N; j++) {
				scanf("%d", &A[i][j]);
				cnt[A[i][j]]++;
				done[i][j] = 0;
			}

		num_done = 0;
		for (ok = 1, value = VMAX - 1; value >= 1; value--)
			if (cnt[value] > 0) {
				for (i = 1; i <= M && ok; i++)
					for (j = 1; j <= N && ok; j++)
						if (A[i][j] == value && !done[i][j]) {
							// Check the row.
							for (k = 1; k <= N; k++)
								if (A[i][k] > A[i][j])
									break;
								
							if (k > N) {
								for (k = 1; k <= N; k++)
									if (A[i][k] == A[i][j] && !done[i][k]) {
										done[i][k] = 1;
										num_done++;
									}
								continue;
							}
							
							// Check the column.
							for (k = 1; k <= M; k++)
								if (A[k][j] > A[i][j])
									break;
								
							if (k > M) {
								for (k = 1; k <= M; k++)
									if (A[k][j] == A[i][j] && !done[k][j]) {
										done[k][j] = 1;
										num_done++;
									}
								continue;
							}
							
							ok = 0;
						}
			}

		printf("Case #%d: ", te);
		if (num_done == M * N && ok)
			printf("YES\n");
		else
			printf("NO\n");
	}
	
	return 0;
}

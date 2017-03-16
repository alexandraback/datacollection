#include <stdio.h>
int loan[100][100];
int main() {
	int T, N, M, test, i, j, k;
	scanf("%i", &T);
	for (test = 1; test <= T; test++) {
		int res = 1;
		scanf("%i %i", &N, &M);
		for(i = 0; i < N; i++)
			for (j = 0; j < M; j++)
				scanf("%i", &loan[i][j]);
		for (i = 0; i < N; i++)
			for (j = 0; j < M; j++) {
				int canRow = 1, canCol = 1;
				for (k = i - 1; k >= 0; k--)
					canRow &= (loan[k][j] <= loan[i][j]);
				for (k = i + 1; k < N; k++)
					canRow &= (loan[k][j] <= loan[i][j]);
				for (k = j - 1; k >= 0; k--)
					canCol &= (loan[i][k] <= loan[i][j]);
				for (k = j + 1; k < M; k++)
					canCol &= (loan[i][k] <= loan[i][j]);
				res &= (canRow | canCol);
			}
		printf("Case #%i: %s\n", test, res ? "YES" : "NO");
	}
	return 0;
}
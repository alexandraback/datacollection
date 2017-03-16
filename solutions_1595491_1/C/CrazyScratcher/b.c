#include <stdio.h>

int main() {
	int T, N, S, P;
	int tc;
	int i, j, k;

	scanf("%d", &T);
	for (tc = 1; tc <= T; tc++) {
		int res = 0;
		scanf("%d %d %d", &N, &S, &P);
		for (i = 0; i < N; i++) {
			scanf("%d", &j);
			if (j == 0) res += (P == 0 ? 1 : 0);
			else if (j >= 28) res++;
			else if (j % 3 == 2) {
				if (j / 3 + 1 >= P) res++;
				else if (S && j / 3 + 2 >= P) res++, S--;
			} else if (j % 3 == 0) {
				if (j / 3 >= P) res++;
				else if (S && j / 3 + 1 >= P) res++, S--;
			} else {
				if (j / 3 + 1 >= P) res++;
			}
		}
		printf("Case #%d: %d\n", tc, res);
	}
	return 0;
}


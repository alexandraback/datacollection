#include <stdio.h>

int main() {
	int T, A, B;
	int tc;
	int i, j, k, m;

	scanf("%d", &T);
	for (tc = 1; tc <= T; tc++) {
		int res = 0;
		scanf("%d %d", &A, &B);
		j = A;
		m = 1;
		while (j) {
			j /= 10;
			m *= 10;
		}
		for (j = A; j <= B; j++) {
			k = j;
			do {
				k = (k * 10) % m + k * 10 / m;
				if (k > j && k <= B) res++;
			} while (k != j);
		}
		printf("Case #%d: %d\n", tc, res);
	}
	return 0;
}


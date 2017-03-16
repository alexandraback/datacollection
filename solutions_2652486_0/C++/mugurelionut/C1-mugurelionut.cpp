#include <stdio.h>
#include <string.h>

#define VMAX 130
#define NMAX 13

char prod[VMAX], pfound[VMAX];
int sol[NMAX];
int R, N, M, K, conf, i, p;

int GenerateNumbers(int idx) {
	if (idx > N) {
		// Test the numbers.
		memset(pfound, 0, sizeof(pfound));
		for (conf = 0; conf < (1 << N); conf++) {
			p = 1;
			for (i = 1; i <= N; i++)
				if ((conf & (1 << (i - 1))) > 0)
					p *= sol[i];
			pfound[p] = 1;
		}
		
		for (p = 1; p < VMAX; p++)
			if (prod[p] && !pfound[p])
				return 0;
		return 1;
	} else {
		for (sol[idx] = 2; sol[idx] <= M; sol[idx]++)
			if (GenerateNumbers(idx + 1))
				return 1;
		return 0;
	}
}

int main() {
	freopen("C-small-1-attempt0.in", "r", stdin);
	freopen("C1small.out", "w", stdout);

	int T, i, x;
	
	scanf("%d", &T);
	printf("Case #1:\n");
	scanf("%d %d %d %d", &R, &N, &M, &K);

	while (R--) {
		memset(prod, 0, sizeof(prod));
		for (i = 1; i <= K; i++) {
			scanf("%d", &x);
			prod[x] = 1;
		}

		GenerateNumbers(1);
		for (i = 1; i <= N; i++)
			printf("%d", sol[i]);
		printf("\n");
		for (i = 1; i <= N; i++)
			fprintf(stderr, "%d", sol[i]);
		fprintf(stderr, "\n");
	}
	
	return 0;
}

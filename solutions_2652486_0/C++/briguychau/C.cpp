#include <stdio.h>
#include <algorithm>

void solve(int N, int M, int K) {
	int prod;
	int counter = 0;
	int other;
	int * list = (int *)calloc((M + 1), sizeof(int));
	for (int i = 0; i < K; i++) {
		scanf("%d", &prod);
		for (int j = 2; j <= M; j++) {
			counter = 0;
			other = prod;
			while (true) {
				if ((other % j != 0) || (other <= 1)) break;
				other /= j;
				counter++;
			}
			if (list[j] < counter) {
				list[j] = counter;
			}
		}
	}
	counter = 0;
	for (int j = 2; j <= M; j++) {
		counter += list[j];
	}
	
	if (counter == N) {
		for (int j = M; j >= 2; j--) {
			while (list[j] >= 1) {
				printf("%d", j);
				list[j]--;
			}
		}
	} else if (counter < N) {
		for (int j = M; j >= 2; j--) {
			while (list[j] >= 1) {
				printf("%d", j);
				list[j]--;
			}
		}
		for (int j = 0; j < N - counter; j++) {
			printf("2");
		}
	} else {
		counter = N;
		for (int j = M; j >= 2; j--) {
			while (list[j] >= 1) {
				printf("%d", j);
				list[j]--;
				counter--;
				if (counter == 0) break;
			}
			if (counter == 0) break;
		}
	}
	
	
	free(list);
	printf("\n");
	return;
}

int main() {
	int T, R, N, M ,K;
	scanf("%d", &T);
	scanf("%d %d %d %d", &R, &N, &M, &K);
	printf("Case #1: \n");
	for (int i = 0; i < R; i++) {
		solve(N, M, K);
	}
	return 0;
}


#include <stdio.h>

void printll(long long x) {
	if (x >= 10) printll(x / 10);
	putchar('0' + (int)(x % 10));
}

int main(void) {
	int T, caseCount;
	if (scanf("%d", &T) != 1) return 1;
	for (caseCount = 1; caseCount <= T; caseCount++) {
		int K, C, S;
		if (scanf("%d%d%d", &K, &C, &S) != 3) return 1;
		printf("Case #%d:", caseCount);
		if (K == S) {
			long long position[128];
			long long len = 1;
			int i, j;
			for (i = 0; i < K; i++) position[i] = i;
			for (i = 1; i < C; i++) {
				len *= K;
				for (j = 0; j < K; j++) {
					position[j] = j * len + position[j];
				}
			}
			for (i = 0; i < K; i++) {
				putchar(' ');
				printll(position[i] + 1);
			}
			putchar('\n');
		} else {
			puts(" NOT IMPLEMENTED");
		}
	}
	return 0;
}

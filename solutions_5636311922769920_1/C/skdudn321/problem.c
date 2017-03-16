#include<stdio.h>
#include<stdlib.h>

int main(void) {
	int T;
	int i, j, w, x;

	int K, C, S;

	long long mul;

	freopen("D-large.in", "r", stdin);
	freopen("out.txt", "w", stdout);

	scanf("%d", &T);
	for (i = 1; i <= T; i++) {
		scanf("%d %d %d", &K, &C, &S);
		if (K > C * S) {
			printf("Case #%d: IMPOSSIBLE\n", i);
		}
		else {
			printf("Case #%d:", i);
			for (j = 0; j < K;) {
				mul = 1;
				x = j;
				for (w = 0; w < C; w++) {
					if (x < K) {
						x++;
					}
					mul = K * (mul - 1) + x;
				}
				printf(" %lld", mul);
				j += C;
			}
			printf("\n");
		}
	}
}
#include <stdio.h>

int
main(void) {
	int T, seqno;
	scanf("%d", &T);
	int A, B, K;
	for (seqno = 1; seqno <= T; seqno++) {
		scanf("%d%d%d", &A, &B, &K);

		int res = 0;
		int i, j;
		for (i = 0; i < A; i++) {
			for (j = 0; j < B; j++) {
				if ((i & j) < K) {
					res++;
				}
			}
		}
		printf("Case #%d: %d\n", seqno, res);
	}

	return 0;
}

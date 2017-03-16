#include <stdio.h>
#include <algorithm>

int motarr[1000];

int
main(void) {
	int T, seq;
	int A, N;
	int i;
	scanf("%d", &T);

	for (seq = 1; seq <= T; seq++) {
		scanf("%d%d", &A, &N);	
		for (i = 0; i < N; i++) {
			scanf("%d", &motarr[i]);
		}

		std::sort(motarr, motarr + N);

		int optval = N;
		if (A > 1) {
			int size = A;
			int nop = 0;
			for (i = 0; i < N; i++) {
				// migrate
				while (size <= motarr[i]) {
					size += size - 1;
					nop++;
				}
				size += motarr[i];
				// nop++;

				int t = nop + (N - i - 1);
				if (t < optval) {
					optval = t;
				}
			}
		}
		printf("Case #%d: %d\n", seq, optval);
	}
	return 0;
}

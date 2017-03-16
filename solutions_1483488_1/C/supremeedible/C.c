#include <stdio.h>

int digits(int A) {
	int d = 1;

	while(A >= 10) {
		A /= 10;
		d++;
	}

	return d;
}

main() {
	int T, Q;
	scanf(" %d", &T);

	for(Q = 1; Q <= T; Q++) {
		int A, B, i, j;
		scanf(" %d %d", &A, &B);

		int m = 1;
		int d = 1;
		int r = 0;

		int k = 0;
		int l;
		int hits[d];

		while(A >= m * 10) { m *= 10; d++; }
		//printf("*** m=%d\n", m);

		for(i = A; i < B; i++) {
			int e = i;
			k = 0;

			for(j = 1; j < d; j++) {
				e = (e % 10) * m + (e / 10);
				if(i < e && e <= B) {
					for(l = 0; l < k; l++) if(hits[l] == e) break;
					if(l == k) { hits[k++] = e; r++; }
				}
			}
		}

		printf("Case #%d: %d\n", Q, r);
	}
}

#include <stdio.h>

main() {
	int T, Q;
	scanf(" %d", &T);

	for(Q = 1; Q <= T; Q++) {
		int N, S, p, i, d;
		scanf(" %d %d %d", &N, &S, &p);

		int yes = 0, maybe = 0;

		for(i = 0; i < N; i++) {
			scanf(" %d", &d);

			if(p <= 1) {
				if(d >= p) yes++;
			} else {
				if(d >= 3 * p - 2) yes++;
				else if(d >= 3 * p - 4) maybe++;
			}
		}

		yes += (maybe > S) ? S : maybe;
		printf("Case #%d: %d\n", Q, yes);
	}
}

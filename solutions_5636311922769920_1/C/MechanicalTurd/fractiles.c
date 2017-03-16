#include <stdio.h>

int main() {
	int T, K, C, S;
	scanf("%u", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%u %u %u", &K, &C, &S);
		printf("Case #%u:", t);
		
		// a well-placed student can guess C tiles
		if (S * C < K) {
			puts(" IMPOSSIBLE");
		} else {
			int c = 0;
			long long pos = 0;
			for (int k = 0; k < K; k++) {
				pos = pos * K + k;
				if (++c == C)
					c = 0, printf(" %lld", pos + 1), pos = 0;
			}
			if (c > 0)
				printf(" %lld", pos + 1);
			putchar('\n');
		}
	}
	return 0;
}

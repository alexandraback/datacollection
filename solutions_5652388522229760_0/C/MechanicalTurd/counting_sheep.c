#include <stdint.h>
#include <stdio.h>

int main() {
	unsigned T, N;
	scanf("%u", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%u", &N);
		printf("Case #%u: ", t);
		if (N == 0) {
			puts("INSOMNIA");
		} else {
			unsigned y = N, mask = 0;
			while (1) {
				for (unsigned u = y; u != 0; u /= 10)
					mask |= 1 << (u % 10);
				if (mask == 0x3ff)
					break;
				y += N;
			}
			printf("%u\n", y);
		}
	}
	return 0;
}

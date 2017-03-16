#include <stdio.h>
#include <assert.h>

int main (void) {
    int T = 0, N = 0, S = 0, p = 0, cur = 0;
    int scanned = scanf("%d", &T);
    for (int currentcase = 1; currentcase <= T; ++currentcase) {
		int output = 0;
		scanned = scanf("%d%d%d", &N, &S, &p);
		int min = 0, max = 0;
		if (p == 0) {
			min = 0;
			max = 0;
		} else if (p == 1) {
			min = 1;
			max = 1;
		} else {
			min = 3 * p - 4;
			max = min + 2;
		}
		for (int i = 0; i < N; ++i) {
			scanned = scanf("%d", &cur);
			if (max <= cur) {
				++output;
			} else if (min <= cur && 0 < S) {
				++output;
				--S;
			}
		}
		printf("Case #%d: %d\n", currentcase, output);
    }
    return 0;
}

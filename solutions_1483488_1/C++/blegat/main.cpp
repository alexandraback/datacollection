#include <stdio.h>
#include <assert.h>

int num[8], numn; // one en trop
int mem[10], memn;
// The pair must have the smaller on the left, that is, (n, m) n < m
// num in the reverse order
// 876543210
//        42

void write (int n) {
	int i = 0;
	for (i = 0; n != 0; ++i) {
		num[i] = n % 10;
		n /= 10;
	}
	numn = i;
}

int recycled_pair (int n, int min, int max) {
	int out = 0;
	memn = 0;
	write(n);
	for (int i = 0; i < numn; ++i) { // i + 1 < numn would also work
		if (num[i] != 0) {
			int m = 0;
			for (int j = i + numn; i < j; --j) {
				m = 10 * m + num[j % numn];
			}
			if (n < m && m <= max) {
				bool ok = true;
				for (int h = 0; h < memn; ++h) {
					if (mem[h] == m)
						ok = false;
				}
				if (ok) {
					out++;
					mem[memn++] = m;
				}
			}
		}
	}
	return out;
}

int main (void) {
    int T = 0;
    int scanned = scanf("%d", &T);
    for (int currentcase = 1; currentcase <= T; ++currentcase) {
		int n = 0, m = 0, output = 0;
		scanf("%d%d", &n, &m);
		for (int i = n; i <= m; ++i) {
			output += recycled_pair(i, n, m);
		}
		printf("Case #%d: %d\n", currentcase, output);
    }
    return 0;
}

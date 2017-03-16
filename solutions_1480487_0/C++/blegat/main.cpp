#include <stdio.h>
#include <assert.h>
#include <algorithm>

int s[1000];
int d[1000];
int n;
int sum;

double rout (int ind) {
	int su = sum;
	for (int i = n-1; ind <= i; --i) {
		int max_x_i = su + sum;
		if (s[i] * (i+1) <= max_x_i) {
			return 100. * ((double) max_x_i - (i+1) * s[ind]) / ((double) sum * (i+1));
		}
		su -= s[i];
	}
	return 0;
}

double out (int ind) {
	for (int i = 0; i < n; ++i) {
		if (s[i] == d[ind])
			return rout(i);
	}
	assert(false);
}

int main (void) {
    int T;
    int scanned = scanf("%d", &T);
    for (int currentcase = 1; currentcase <= T; ++currentcase) {
		scanf("%d", &n);
		sum = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &s[i]);
			d[i] = s[i];
			sum += s[i];
		}
		std::sort(s, s + n);
		printf("Case #%d:", currentcase);
		for (int i = 0; i < n; ++i) {
			printf(" %.8f", out(i));
		}
		printf("\n");
    }
    return 0;
}

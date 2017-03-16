#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define min(a, b) ((a) < (b) ? (a) : (b))
int R, C, W;
int b[21];

int solve() {
	int i = W-1, c = 0;
	memset(b, 0, sizeof(b));
	while (i < C) {
		b[i] = 1;
		c++;
		if (i + W >= C)
			break;
		i += W;
	}
	fprintf(stderr, "first hit at %d on %d moves (scan other rows = %d)\n", i, c, (R-1)*c);
	int j;
	for (j = 0; j < C; ++j)
		fprintf(stderr, "%d ", b[j]);
	fprintf(stderr, "\n");
	return ((R-1) * c) + c + W - 1 + (i != C - 1);
}

int main() {
	int i, t, x = 1;
	scanf("%d\n", &t);
	while (t--) {
		scanf("%d %d %d\n", &R, &C, &W);
		printf("Case #%d: %d\n", x++, solve());
	}
	return 0;
}

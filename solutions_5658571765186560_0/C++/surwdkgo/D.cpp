#include <stdio.h>
#include <algorithm>

int ans(int x, int r, int c) {
	if (x >= 7) return 1;
	if (r < c) std::swap(r, c);
	if (r*c%x) return 1;
	if (r < x) return 1;
	if (x <= 2) return 0;
	if (x == 3) return c <= 1;
	if (c <= (x+1)/2) return 1;
	return 0;
}

int main() {
	int cas;
	int x, r, c;
	scanf("%d", &cas);
	for (int ii=0; ii<cas; ii++) {
		scanf("%d%d%d", &x, &r, &c);
		printf("Case #%d: %s\n", ii+1, ans(x,r,c) ? "RICHARD" : "GABRIEL");
	}
	return 0;
}

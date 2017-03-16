#include <stdio.h>
#include <iostream>
using namespace std;
int g[4][4] = {
	{0, 1, 2, 3},
	{1, 4, 3, 6},
	{2, 7, 4, 1},
	{3, 2, 5, 4}
};

int G(int x, int y) {
	int tx = x & 4;
	x %= 4;
	int ty = y & 4;
	y %= 4;
	int t = g[x][y];
	t ^= tx;
	t ^= ty;
	return t;
}
char s[10020];
int t;
int main() {
	scanf("%d", &t);
	for (int tt = 1; tt <= t; tt++) {
		int l, x;
		scanf("%d%d", &l, &x);
		scanf("%s", s);
		for (int i = 0; i < l; i++) {
			s[i] -= 'i' - 1;
		}
		int res = 0;
		int step = 0;
		for (int i = 0; i < l * x; i++) {
			res = G(res, s[i % l]);
			if (step == 0 && res == 1) {
				step++;
			}
			if (step == 1 && res == 3) {
				step++;
			}
			if (step == 2 && res == 4) {
				step++;
			}
		}
		printf("Case #%d: %s\n", tt, step == 3 && res == 4 ? "YES": "NO");
	}
	return 0;
}
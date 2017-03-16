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
		long long X;
		scanf("%d%lld", &l, &X);
		x = min(X, 100LL + X % 4);
		scanf("%s", s);
		for (int i = 0; i < l; i++) {
			s[i] -= 'i' - 1;
		}
		int res = 0;
		int step = 0;
		int lpos = 0, rpos = 0;
		for (int i = 0; i < l * min(4, x); i++) {
			res = G(res, s[i % l]);
			if (step == 0 && res == 1) {
				step++;
				lpos = i;
				break;
			}
		}
		res = 0;
		for (int i = 0; i < l * min(4, x); i++) {
			res = G(s[l - 1 - i % l], res);
			if (step == 1 && res == 3) {
				step++;
				rpos = l * x - 1 - i;
				break;
			}
		}
		res = 0;
		for (int i = 0; i < l; i++) {
			res = G(res, s[i]);
		}
		int tmp = 0;
		for (int i = 0; i < x % 4; i++) {
			tmp = G(tmp, res);
		}

		if (step == 2 && tmp == 4) {
			step++;
		}

		if (lpos > rpos) {
			step--;
		}

		printf("Case #%d: %s\n", tt, step == 3 ? "YES": "NO");
	}
	return 0;
}
#include <cstdio>
#include <algorithm>
using namespace std;

double test() {
	int n,X,Y;
	scanf("%d%d%d", &n, &X, &Y);
	X = abs(X);
	int layer = 0;
	while (n >= 4*layer+1) {
		n -= 4*layer+1;
		layer++;
	}
	if (X+Y < 2*layer) {
		return 1.0;
	}
	if (X+Y > 2*layer) {
		return 0.0;
	}
	if (n == 0) {
		return 0.0;
	}
	if (X == 0) {
		return 0.0;
	}
	int L = 2*layer;
	int h = L + 1 - X;
	int qq[2];
	int cnt = 0;
	for (int m = 0; m < (1<<n); m++) {
		qq[0] = qq[1] = 0;
		for (int i = 0; i < n; i++) {
			int c = 0;
			if ((1<<i) & m) {
				c = 1;
			}
			if (qq[c] == L) {
				c = 1-c;
			}
			qq[c]++;
		}
		if (qq[0] >= h) {
			cnt++;
		}
	}
	return 1.0 * cnt / (1<<n);
}

int main() {
	int tt;
	scanf("%d", &tt);
	for (int ttt = 1; ttt <= tt; ttt++) {
		double res = test();
		printf("Case #%d: %.7lf\n", ttt, res);
	}
	return 0;
}

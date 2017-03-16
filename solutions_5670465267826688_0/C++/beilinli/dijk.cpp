#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int I = 2;
int J = 3;
int K = 4;

int q(char c) {
	if (c == 'i') return I;
	if (c == 'j') return J;
	if (c == 'k') return K;
	return -13109;
}

int mult(int a, int b) {
	int neg = (a * b >= 0) ? 1 : -1;
	if (a < 0) a = -a;
	if (b < 0) b = -b;

	if (a == 1 || b == 1) return neg * a * b;
	if (a == b) return -neg;
	if (a == I && b == J) return neg * K;
	if (a == I && b == K) return neg * (-J);
	if (a == J && b == I) return neg * (-K);
	if (a == J && b == K) return neg * I;
	if (a == K && b == I) return neg * J;
	if (a == K && b == J) return neg * (-I);

	return 0;
}

int main(void) {
	freopen(	"C-small-attempt0.in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int L, X;
		cin >> L >> X;
		string s;
		cin >> s;

		int i = 0, p = 1;
		for (; i < L * X && p != I; i++)
			p = mult(p, q(s[i % L]));
		if (i == L * X) {
			printf("Case #%d: NO\n", t);
			continue;
		}

		p = 1;
		for (; i < L * X && p != J; i++) p = mult(p, q(s[i % L]));
		if (i == L * X) {
			printf("Case #%d: NO\n", t);
			continue;
		}

		p = 1;
		for (; i < L * X; i++) p = mult(p, q(s[i % L]));

		if (p == K && i == L * X) printf("Case #%d: YES\n", t);
		else printf("Case #%d: NO\n", t);
	}
	return 0;
}

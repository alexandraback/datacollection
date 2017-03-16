#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

double p[110000];

double solve() {
	int A, B;
	scanf("%d%d", &A, &B);
	bool yes = true;
	double succ = 0;
	for (int i = 0; i < A; i++) {
		scanf("%lf", &p[i]);
		if (p[i] < 1e-10) {
			yes = false;
		} else {
			succ += log(p[i]);
		}
	}
	if (yes) succ = exp(succ);
	else succ = 0;

	double res = B << 2;

	// keep going
	double p1 = succ * (B - A + 1);
	double p2 = (1 - succ) * (B - A + 1 + B + 1);
	res = min(res, p1 + p2);

	// give up
	res = min(res, 1.0 + B + 1);

	// first wrong at i
	double t = 0;
	yes = true;
	for (int i = 0; i < A; i++) {
		if (yes) {
			succ = exp(t);
		} else {
			succ = 0;
		}
		p1 = succ * (A - i + B - i + 1);
		p2 = (1 - succ) * (A - i + B - i + 1 + B + 1);
		res = min(res, p1 + p2);
		if (p[i] < 1e-10) {
			yes = false; 
		} else {
			t += log(p[i]);
		}
	}

	return res;
}

int main() {	
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		printf("Case #%d: %.12lf\n", i, solve());
	}
	return 0;
}

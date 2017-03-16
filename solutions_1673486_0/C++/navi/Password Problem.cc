#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int T, A, B, rest;
double p[100000];

inline double gao1() {
	double ret = 0.0;
	double allRight = 1.0;
	for (int i = 0; i < A; ++i) {
		allRight *= p[i];
	}
	ret = rest + 1 + (1 - allRight) * (B + 1);
	return ret;
}

inline double gao2() {
	double ret = 1e100;
	double right = 1.0;
	for (int i = 0; i < A; ++i) {
		ret = min(ret, A - i + B - i + 1 + (1 - right) * (B + 1));
		right *= p[i];
	}
	return ret;
}

inline double gao3() {
	double ret = 1 + B + 1;
	return ret;
}

int main() {
	scanf("%d", &T);
	for (int caesNum = 1; caesNum <= T; ++caesNum) {
		scanf("%d%d", &A, &B);
		for (int i = 0; i < A; ++i) {
			scanf("%lf", &p[i]);
		}
		rest = B - A;
		double res = 1e100;
		res = min(res, gao1());
		res = min(res, gao2());
		res = min(res, gao3());
		printf("Case #%d: %.13f\n", caesNum, res);
	}
	return 0;
}

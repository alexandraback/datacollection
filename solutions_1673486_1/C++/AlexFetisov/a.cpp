// Alex Fetisov

#include <cstdio>

void initf() {
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
}

#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <sstream>
#include <string>

using namespace std;

double curP[1000000];

void solve() {
	int A, B;
	scanf("%d%d", &A, &B);
	double ret1 = 0, ret2 = 0, ret3 = 0;
	double pRight = 1;
	curP[0] = 1;
	for (int i = 1; i <= A; ++i) {
		scanf("%lf", &curP[i]);
		pRight *= curP[i];
		curP[i] *= curP[i-1];
	}
	ret1 = pRight * (B - A + 1) + (1. - pRight) * (B - A + 1 + B + 1);
	double ret = ret1;
	ret2 = B + 2;
	if (ret > ret2 + 1e-9) {
		ret = ret2;
	}
	for (int hitB = 0; hitB <= A; ++hitB) {
		ret3 = curP[A-hitB] * (hitB + B - A + hitB + 1) + (1 - curP[A-hitB]) * (hitB + B - A + hitB + 1 + B + 1);
		if (ret > ret3 + 1e-9) {
			ret = ret3;
		}
	}
	printf("%.9lf\n", ret);
}

int main() {
	initf();
	int T;
	scanf("%d", &T);
	for (int test = 1; test <= T; ++test) {
		printf("Case #%d: ", test);
		solve();
	}
	return 0;
}
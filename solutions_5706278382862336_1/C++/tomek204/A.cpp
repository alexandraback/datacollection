#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long int LL;

LL gcd(LL a, LL b) {
	while (b) {
		LL c = a%b;
		a = b;
		b = c;
	}
	return a;
}

LL P, Q;

bool pow2(LL A) {
	while (A) {
		if (A != 1 && A%2 != 0) return false;
		else A /= 2;
	}
	return true;
}

LL pot2(LL A) {
	LL ret = 1;
	while (A--) ret = ret + ret;
	return ret;
}

bool check(LL lvl) {
	LL M = pot2(lvl);
	return double(P)/double(Q) >= double(1)/double(M);
}

void solve(int testcase) {
	scanf("%lld/%lld", &P, &Q);
	LL r = gcd(P, Q);
	P /= r;
	Q /= r;
	if (!pow2(Q)) {
		printf("Case #%d: impossible\n", testcase);
		return;
	}
	
	for (int i = 1; i <= 40; i++) if (check(i)) {
		printf("Case #%d: %d\n", testcase, i);
		return;
	}
	
	printf("Case #%d: impossible\n", testcase);
}

int main() {
	int t; scanf("%d", &t);
	for (int i = 1; i <= t; i++) solve(i);
	return 0;
}
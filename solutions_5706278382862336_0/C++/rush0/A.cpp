#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#define OUT(x) cerr << #x << ": " << (x) << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long LL;

int T;
LL P, Q;

LL gcd(LL m, LL n) {
	return n ? gcd(n, m % n) : m;
}

LL lowbit(LL x) {
	return x & -x;
}

int main() {
	scanf("%d", &T);
	REP(tid, T) {
		scanf("%lld/%lld", &P, &Q);
		LL d = gcd(P, Q);
		if (d != 0) {
			P /= d;
			Q /= d;
		}
		if (Q - lowbit(Q) != 0 || Q > (1LL << 40)) {
			printf("Case #%d: impossible\n", tid + 1);
			continue;
		}
		int ans = 0;
		while (true) {
			++ans;
			Q /= 2;
			if (P >= Q) break;
		}
		printf("Case #%d: %d\n", tid + 1, ans);
	}
	return 0;
}
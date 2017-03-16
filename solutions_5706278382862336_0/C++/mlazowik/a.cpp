// Michał Łazowik

#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <utility>

using namespace std;

typedef long long LL;

#define REP(x, n) for (int x = 0; x < n; ++x)
#define FOR(x, b, e) for (int x = b; x <= (e); ++x)
#define FORD(x, b, e) for (int x = b; x >= (e); --x)
#define FOREACH(it, cont) for (__typeof(cont.begin()) it = cont.begin(); it != cont.end(); ++it)

#define F first
#define S second
#define MP make_pair
#define PB push_back

LL nwd(LL a, LL b) {
	LL c;

	while (b != 0) {
		c = a % b;
		a = b;
		b = c;
	}

	return a;
}

int log2(LL a) {
	int ret = 0;

	while (a > 1) {
		if (a % 2 == 1) {
			return -1;
		}
		a /= 2;
		ret++;
	}

	return ret;
}

int solve(LL a, LL b) {
	LL div = nwd(a, b);
	a /= div;
	b /= div;
	int ret = 0;

	int anc = log2(b);
	if (a > b || anc == -1 || anc > 40) {
		return -1;
	}

	while (a < b) {
		b /= 2;
		ret++;
	}

	return ret;
}

int main() {
	int t;
	LL a, b;

	scanf("%d", &t);

	FOR(q, 1, t) {
		scanf("%lld/%lld", &a, &b);
		printf("Case #%d: ", q);
		int tmp = solve(a, b);
		if (tmp == -1) {
			printf("impossible");
		} else {
			printf("%d", tmp);
		}
		printf("\n");
	}

	return 0;
}

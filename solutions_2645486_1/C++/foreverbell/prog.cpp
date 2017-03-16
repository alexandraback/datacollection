#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <utility>

using namespace std;

typedef long long LL;
const int maxn = 10001;
int tests, e, r, n, v[maxn];
struct STATE {
	LL size, v;
	STATE(LL tsize, LL tv) {
		size = tsize, v = tv;
	}
	bool operator<(const STATE &r) const {
		return v < r.v;
	}
};

LL work() {
	multiset<STATE> SET;
	SET.clear();
	SET.insert(STATE(e, 0));
	LL ans = 0;
	for (int i = 1; i <= n; ++i) {
		LL sum = 0, sum2 = 0;
		while (!SET.empty()) {
			if (SET.begin()->v < v[i]) {
				sum += SET.begin()->size;
				ans -= SET.begin()->size * SET.begin()->v;
				SET.erase(SET.begin());
			} else {
				break;
			}
		}
		ans += (LL)sum * v[i];
		if (sum != 0) SET.insert(STATE(sum, v[i]));
		while (!SET.empty() && sum2 < r) {
			STATE tail = *(--SET.end());
			if (sum2 + tail.size < r) {
				SET.erase(--SET.end());
				sum2 += tail.size;
			} else {
				SET.erase(--SET.end());
				SET.insert(STATE(sum2 + tail.size - r, tail.v));
				sum2 = r;
			}
		}
		SET.insert(STATE(sum2, 0));
	}
	return ans;
}

int main() {
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	scanf("%d", &tests);
	for (int tt = 1; tt <= tests; ++tt) {
		scanf("%d%d%d", &e, &r, &n);
		for (int i = 1; i <= n; ++i) scanf("%d", v + i);
		printf("Case #%d: %I64d\n", tt, work());
	}
	return 0;
}

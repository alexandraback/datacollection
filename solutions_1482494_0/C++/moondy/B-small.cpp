#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int ABS(int x) {
	return x > 0 ? x : -x;
}

int solve() {
	vector<pair<int, int> > q;
	int n, a, b;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &a, &b);
		q.push_back(make_pair(a, i + 1));
		q.push_back(make_pair(b, -(i + 1)));
	}
	int ret = 1000000;
	sort(q.begin(), q.end());
	for (int mask = 0; mask < 1 << n; mask++) {
		int tot = 0;
		bool ok = true;
		int round = 0;
		for (int i = 0; i < n * 2; i++) {
			int level = ABS(q[i].second) - 1, star = 0;
			if (q[i].second < 0) star = 2;
			else star = 1;
			if (star == 1) {
				if (mask & (1 << level)) {
					if (tot < q[i].first) {
						ok = false;
						break;
					}
					tot++;
					round++;
				}
			} else {
				if (tot < q[i].first) {
					ok = false;
					break;
				}
				if (mask & (1 << level)) {
					tot++;
				} else {
					tot += 2;
				}
				round++;
			}
		}
		if (ok) ret = min(ret, round);
	}
	if (ret == 1000000) return -1;
	return ret;
}

int main() {
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		printf("Case #%d: ", i);
		int res = solve();
		if (res < 0) puts("Too Bad");
		else printf("%d\n", res);
	}
	return 0;
}

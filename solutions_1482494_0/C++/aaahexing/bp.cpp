#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int cas, n, sum, a[1010], b[1010], s[1010];

int main() {
	scanf("%d", &cas);
	for (int ca = 1; ca <= cas; ++ca) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			s[i] = 0;
			scanf("%d%d", &a[i], &b[i]);
		}
		sum = 0;
		int ans = 100000000;
		for (int mask = 0; mask < (1 << (n*2)); ++mask) {
			int cc = 0;
			vector< pair<int, int> > pr;
			for (int i = 0; i < n; ++i) {
				int ai = (mask & (1 << (i*2))) > 0;
				int bi = (mask & (1 << (i*2+1))) > 0;
				if (ai > 0 && bi > 0) {
					++cc;
					pr.push_back(make_pair(a[i], 1));
					pr.push_back(make_pair(b[i], 1));
				} else {
					if (ai > 0)
						pr.push_back(make_pair(a[i], 1));
					else if (bi > 0) {
						++cc;
						pr.push_back(make_pair(b[i], 2));
					}
				}
			}
			if (cc != n) continue;
			sort(pr.begin(), pr.end());
			sum = 0;
			bool ok = true;
			for (int i = 0; i < pr.size(); ++i) {
				if (sum >= pr[i].first) {
					sum += pr[i].second;
				} else {
					ok = false;
					break;
				}
			}
			if (ok)
				ans = min(ans, (int)pr.size());
		}
		printf("Case #%d: ", ca);
		if (ans >= 100000000)
			printf("Too Bad\n");
		else
			printf("%d\n", ans);
	}
	return 0;
}


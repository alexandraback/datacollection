#include<deque>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		static int id = 0;
		printf("Case #%d: ", ++id);
		int n, m, k;
		scanf("%d%d%d", &n, &m, &k);
		if (min(n, m) <= 2) {
			printf("%d\n", k);
			continue;
		} else {
			int ans = k;
			for (int w = 1; w <= m; ++w) {
				for (int h = 1; h <= n; ++h) {
					int cost, area;
					if (min(w, h) <= 2) {
						cost = k;
						area = k;
					} else {
						cost = 2 * (h - 2) + 2 * (w - 2);
						area = h * w - 4;
						if (area < k) {
							cost += k - area;
							area += k - area;
						}
					}
					if (area >= k) {
						ans = min(ans, cost);
					}
				}
			}
			for (int w = 3; w <= m; ++w) {
				int cost = w + w - 2, area = w + w - 2;
				vector<int> up, down;
				up.push_back(w);
				down.push_back(w - 2);
				int lup = (n + 1) / 2, ldown = 
				while (true) {
					ans = min(ans, cost + max(0, k - area));
				}
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}

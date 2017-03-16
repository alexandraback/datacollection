#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 1000

int main() {
	int nTests;
	scanf("%d", &nTests);
	for (int test = 1; test <= nTests; ++test) {
		int n, s, p;
		scanf("%d %d %d", &n, &s, &p);
		int vn[n], vy[n];
		for (int i = 0; i < n; ++i) {
			int total;
			scanf("%d", &total);
			if ((total + 2) / 3 >= p) {
				vn[i] = 1;
			} else {
				vn[i] = 0;
			}
			if (total < 2 || total > 28) {
				vy[i] = -INF;
			} else {
				if (total % 3 == 1) {
					if ((total + 2) / 3 >= p) {
						vy[i] = 1;
					} else {
						vy[i] = 0;
					}
				} else {
					if (((total + 2) / 3) + 1 >= p) {
						vy[i] = 1;
					} else {
						vy[i] = 0;
					}
				}
			}
		}
		vector<pair<int, int> > V;
		for (int i = 0; i < n; ++i) {
			V.push_back(make_pair(vn[i] - vy[i], i));
		}
		sort(V.begin(), V.end());
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			if (i < s) {
				ans += vy[V[i].second];
			} else {
				ans += vn[V[i].second];
			}
		}
		printf("Case #%d: %d\n", test, ans);
	}

	return 0;
}

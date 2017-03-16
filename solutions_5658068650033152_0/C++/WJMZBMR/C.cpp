#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <numeric>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int nc = 1; nc <= T; ++nc) {
		printf("Case #%d: ", nc);
		int n, m, k;
		cin >> n >> m >> k;
		if (n > m)
			swap(n, m);
		if (n <= 2) { //no innner point
			printf("%d\n", k);
			continue;
		}
		//consider innner point
		int ans = k;
		for (int I = 0; I <= k; ++I) {
			for (int x = 1; x <= n - 2; ++x) {
				int y = (I - 1) / x + 1;
				if (y <= m - 2) {
					int need = 2 * (x + y) - 1;
					if (x * y == I)
						++need;
					if (need + I >= k) {
						ans = min(ans, need);
					} else {
						ans = min(ans, need + (k - need - I));
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}

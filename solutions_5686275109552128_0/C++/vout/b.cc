#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int gao(int maxd, vector<int> &v) {
	int ret = 0;
	for (int i = 0; i < v.size(); ++i) {
		ret += v[i] <= maxd ? 0 : (v[i] - 1) / maxd;
	}
	return ret;
}

int main() {
	int T;
	cin >> T;
	for (int re = 1; re <= T; ++re) {
		int n;
		cin >> n;
		vector<int> v(n);
		for (int i = 0; i < n; ++i) {
			cin >> v[i];
		}

		int m = *max_element(v.begin(), v.end());
		int ans = m;
		for (int i = 1; i <= m; ++i) {
			ans = min(ans, gao(i, v) + i);
		}

		cout << "Case #" << re << ": " << ans << endl;
	}
	return 0;
}
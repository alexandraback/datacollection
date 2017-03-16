#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int C, D, V;
		cin >> C >> D >> V;
		if (C != 1) {
			cout << "Сase #" << t << ": don't know" << endl;
			continue;
		}
		vector<bool> a(V + 1, false);
		a[0] = true;
		for (int d = 0; d < D; ++d) {
			int coin;
			cin >> coin;
			for (int i = V; i >= coin; --i) {
				a[i] = a[i] || a[i - coin];
			}
		}
		int ans = 0;
		for (int coin = 1; coin <= V; ++coin) {
			if (!a[coin]) {
				++ans;
				for (int i = V; i >= coin; --i) {
					a[i] = a[i] || a[i - coin];
				}
			}
		}
		cout << "Case #" << t << ": " << ans << endl;
	}
	return 0;
}

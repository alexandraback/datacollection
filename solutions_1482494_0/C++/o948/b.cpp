#include <iostream>
#include <algorithm>
using namespace std;

void solve() {
	int n;
	cin >> n;
	pair<int,int> a[1000], b[1000];
	for (int i = 0; i < n; i++) {
		int ai, bi;
		cin >> ai >> bi;
		a[i] = make_pair(ai, i);
		b[i] = make_pair(bi, i);
	}

	sort(a, a+n);
	sort(b, b+n);

	bool done[1000][3] = {};
	int stars = 0, ans = 0;
	int i = 0, j = 0;
	while (j < n) {
		while (i < n && done[a[i].second][2]) {
			i++;
		}
		if (b[j].first > stars) {
			if (i == n || a[i].first > stars) {
				cout << "Too Bad" << endl;
				return;
			}
			stars += 1;
			done[a[i].second][1] = true;
			i++;
		} else {
			stars += 2 - done[b[j].second][1];
			done[b[j].second][2] = true;
			j++;
		}
		ans++;
	}
	cout << ans << endl;
}

int main() {
	int t; cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}


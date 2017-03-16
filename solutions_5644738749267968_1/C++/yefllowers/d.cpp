#include <iostream>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 1050;

int n;
double a[N], b[N];

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	sort(a, a + n);
	sort(b, b + n);
	int ans1 = 0;
	for (int i = n - 1, s = 0, t = n - 1; i >= 0; i--) {
		if (a[i] > b[t]) {
			ans1++;
			s++;
		} else {
			t--;
		}
	}
	int ans2 = 0;
	for (int i = n; i >= 1; i--) {
		bool ok = true;
		for (int j = 0; j < i; j++)
			ok &= a[n - i + j] > b[j];
		if (ok) {
			ans2 = max(ans2, i);
			break;
		}
	}
	cout << ans2 << ' ' << ans1 << endl;
}

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cout << "Case #" << t << ": ";
		solve();
	}
}
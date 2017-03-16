#include <bits/stdc++.h>

using namespace std;

int K, C, S;

void solve() {
	long long gap = 1;
	for (int c = 0; c < C - 1; c++) {
		gap *= K;
	}
	for (int s = 0; s < S; s++) {
		if (s > 0) {
			cout << ' ';
		}
		cout << s * gap + 1;
	}
	cout << '\n';
}

int main() {
	assert(freopen("D.in", "r", stdin));
	assert(freopen("D.out", "w", stdout));
	cin.sync_with_stdio(false);

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cout << "Case #" << t << ": ";

		cin >> K >> C >> S;
		solve();
		
		cerr << t << endl;
	}

	return 0;
}

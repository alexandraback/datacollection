#include <bits/stdc++.h>

#define _DEBUG

using namespace std;

const int N = (int)1e5 + 1;
const int inf = (int)1e9 + 7;
const int M = 261;
const int K = 10;

void solve(int test) {
	int k, c, s;
	cin >> k >> c >> s;
	cout << "Case #" << test << ": ";
	if (s < k) {
		cout << "IMPOSSIBLE" << endl;
		return;
	}
	for (int i = 1; i <= k; ++i) {
		cout << i << ' ';
	}
	cout << endl;
}

int main() {
#ifdef _DEBUG
	freopen("D-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int test = 1; test <= T; ++test) {
		solve(test);
	}
	return 0;
}
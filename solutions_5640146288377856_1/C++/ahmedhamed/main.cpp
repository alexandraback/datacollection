#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
	freopen("A-large.in", "rt", stdin);
	freopen("A-large.out", "wt", stdout);
	int t, r, c, w;
	cin >> t;
	for (int tst = 1; tst <= t; ++tst) {
		cin >> r >> c >> w;
		int ret1 = (r - 1) * (c / w);
		int ret2 = w + c / w - (c % w == 0);
		cout << "Case #" << tst << ": " << ret1 + ret2 << endl;
	}
	return 0;
}

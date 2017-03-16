#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
	freopen("A-small-attempt1.in", "rt", stdin);
	freopen("A-small-attempt1.out", "wt", stdout);
	int t, r, c, w;
	cin >> t;
	for (int tst = 1; tst <= t; ++tst) {
		cin >> r >> c >> w;
		cout << "Case #" << tst << ": " << w + c / w - (c % w == 0) << endl;
	}
	return 0;
}

#define DEBUG 0
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int cnt[2501];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cerr << fixed << setprecision(0);

	if (!DEBUG) {
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	}

	int _c, _start = static_cast<int>(clock());
	cin >> _c;

	for(int _cc = 1; _cc <= _c; ++_cc) {
		int _t = static_cast<int>(clock());
		cout << "Case #" << _cc << ": ";

		int n;
		cin >> n;

		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < 2 * n - 1; ++i) {
			for (int j = 0; j < n; ++j) {
				int k;
				cin >> k;
				++cnt[k];
			}
		}

		for (int i = 1; i <= 2500; ++i) {
			if (cnt[i] % 2 != 0) {
				cout << i << ' ';
			}
		}
		cout << '\n';

		cerr << "[Case #" << _cc << " complete, " << static_cast<int>(clock() - _t) << " ms, " << 100. * _cc / _c << "%]" << endl;
	}

	cerr << "Total time: " << static_cast<int>(clock() - _start) << " ms" << endl;

	return 0;
}


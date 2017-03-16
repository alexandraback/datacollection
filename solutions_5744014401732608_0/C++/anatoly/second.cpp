#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
#include <cstdlib>
#include <climits>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

template <typename T> using V = vector<T>;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> Pii;

const double Pi = acos(-1.0);

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i, l, r) for (int i = int(l); i < int(r); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	int T; cin >> T;

	forn(tc, T) {
		cout << "Case #" << tc + 1 << ": ";
		int B; ll M;
		cin >> B >> M;

		ll ans = 0;
		ll maxM = 1ll << (B - 2);
		if (M > maxM) {
			cout << "IMPOSSIBLE" << endl;
		}
		else {
			cout << "POSSIBLE" << endl;
			for (int i = 0; i < B; ++i) {
				string s(B, '0');
				for (int j = i + 1; j < B; ++j) {
					if (j == B - 1 && M != maxM) {
						ll x = i > 0 ? (1ll << (i - 1)) : 0;
						s[j] = (M & x) != 0 ? '1' : '0';
					}
					else {
						s[j] = '1';
					}
				}
				cout << s << endl;
			}

		}
	}
}
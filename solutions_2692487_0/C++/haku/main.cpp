#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <functional>
#include <iterator>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <climits>
#include <cassert>
#include <ctime>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pnt;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int INF = 1000 * 1000 * 1000 + 5;
const int MOD = 1000 * 1000 * 1000 + 7;

int t;

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	cin >> t;
	for (int q = 0; q < t; ++q) {
		ll a;
		int n;
		vector<ll> d;
		cin >> a >> n;
		int ans = n;
		d.resize(n);
		for (int i = 0; i < n; ++i)
			cin >> d[i];
		if (a > 1) {
			sort(d.begin(), d.end());
			for (int i = 0; i <= n; ++i) {
				ll x = a;
				int y = n - i;
				for (int j = 0; j < i; ++j) {
					while (x <= d[j]) {
						x += x - 1;
						++y;
					}
					x += d[j];
				}
				ans = min(ans, y);
			}
		}
		cout << "Case #" << q + 1 << ": " << ans << "\n";
	}
	return 0;
}
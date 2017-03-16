#include <algorithm>
#include <iostream>
#include <cstring>
#include <sstream>
#include <vector>
#include <cmath>
#include <set>
#include <map>

using namespace std;

#define int long long
#define double long double

#define ff first
#define ss second
#define mp make_pair
#define sqr(x) ((x)*(x))

typedef long long ll;
typedef pair <int, int> pie;

const int maxN = 1000 * 1000 + 100;

int d[maxN];
string vow = "aeiou";

bool vowel (char x) {
	return vow.find (x) != -1;
}

ll solve() {
	int n, l; string s; cin >> s >> n; l = s.size();
	vector <int> good;
	d[l] = 0;
	for (int i = l - 1; i >= 0; i--) {
		if (vowel (s[i])) d[i] = 0;
		else d[i] = d[i + 1] + 1;
		if (d[i] >= n) good.push_back (i);
	}
	reverse (good.begin(), good.end());

	ll res = 0;
	for (int i = 0; i < l; i++) {
		int x = lower_bound (good.begin(), good.end(), i) - good.begin();
		if (x == good.size()) continue;
		res += l - good[x] - n + 1;
	}
	return res;
}

main() {
	ios::sync_with_stdio (false);
	
	int tests; cin >> tests;
	for (int o = 1; o <= tests; o++) {
		ll ans = solve();
		cout << "Case #" << o << ": " << ans << endl;
	}

	return 0;
}

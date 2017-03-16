#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define SQR(a) ((a) * (a))
#define SZ(x) ((int) (x).size())
#define ALL(x) (x).begin(), (x).end()
#define CLR(x, a) memset(x, a, sizeof x)
#define VAL(x) #x << " = " << (x) << "   "
#define FOREACH(i, x) for(__typeof((x).begin()) i = (x).begin(); i != (x).end(); i ++)
#define FOR(i, n) for (int i = 0; i < (n); i ++)
#define X first
#define Y second

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

const int MAXN = 1 * 1000 + 10;

int main () {
	ios::sync_with_stdio(false);

	int tc; cin >> tc;
	for (int o = 0; o < tc; o ++) {
		cout << "Case #" << o + 1 << ": ";

		string s; cin >> s;
		int mx = -1;

		deque<char> ans;
		for (int i = 0; i < SZ(s); i ++) {
			mx = max(mx, s[i] - 'A');
			if ((s[i] - 'A') == mx)
				ans.push_front(s[i]);
			else ans.pb(s[i]);
		}

		for (int i = 0; i < SZ(ans); i ++)
			cout << ans[i];
		cout << endl;
	}
	return 0;
}


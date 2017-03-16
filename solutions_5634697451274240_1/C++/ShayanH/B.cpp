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

int f(string& s, int n) {
	if (n == -1) return 0;
	if (s[n] == '+') return f(s, n - 1);

	for (int i = 0; i <= n; i ++)
		s[i] = (s[i] == '+' ? '-' : '+');
	return f(s, n - 1) + 1;
}

int main () {
	ios::sync_with_stdio(false);
	
	int oo; cin >> oo;
	for (int o = 0; o < oo; o ++) {
		cout << "Case #" << o + 1 << ": ";

		string s; cin >> s;
		cout << f(s, s.size() - 1) << endl;
	}
	return 0;
}


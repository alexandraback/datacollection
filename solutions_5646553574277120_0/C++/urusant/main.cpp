#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>
using namespace std;

#define pb push_back
#define rs resize
#define mp make_pair
#define pi 3.1415926535897932384626433832795
#define sz(a) (int)(a).size()
#define Sort(a) sort((a).begin(), (a).end())
#define Reverse(a) reverse((a).begin(), (a).end())
#define sf scanf
#define pf printf
#define ms(a, x) memset((a), (x), sizeof(a))
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <vvi> vvvi;
typedef vector <vvvi> vvvvi;
typedef vector <bool> vb;
typedef vector <vb> vvb;
typedef vector <vvb> vvvb;
typedef vector <vvvb> vvvvb;
typedef long long ll;
typedef vector <ll> vl;
typedef vector <vl> vvl;
typedef vector <vvl> vvvl;
typedef vector <vvvl> vvvvl;
typedef pair <int, int> ii;
typedef vector <ii> vii;
typedef vector <vii> vvii;
typedef pair <int, ll> il;
typedef vector <il> vil;
typedef vector <vil> vvil;
typedef pair <ll, int> li;
typedef vector <li> vli;
typedef vector <vli> vvli;
typedef set <int> si;
typedef set <li> sli;
typedef set <il> sil;
typedef vector <string> vs;
typedef vector <vs> vvs;
typedef vector <vvs> vvvs;
typedef map <char, int> mci;
typedef pair <ll, ll> pll;
typedef vector <pll> vll;
typedef long double ld;

int ans = 100;
int d;

bool valid(vi a) {
	Sort(a);
	for (int i = 1; i < sz(a); ++i) {
		if (a[i] == a[i - 1]) {
			return 0;
		}
	}
	return 1;
}

bool check(int v, vi a) {
	vb u(v + 1);
	u[0] = 1;
	for (int i = 0; i < sz(a); ++i) {
		for (int j = v; j >= 0; --j) {
			if (u[j] && j + a[i] <= v) {
                //cerr << j << ' ' << a[i] << endl;
				u[j + a[i]] = 1;
			}
		}
	}
	for (int i = 0; i <= v; ++i) {
		if (!u[i]) {
			return 0;
		}
	}
	return 1;
}

void solve(int v, vector <int> a, int last = 0) {
	if (!valid(a)) {
		return;
	}
	if (check(v, a)) {
		ans = min(ans, sz(a));
		return;
	}
	if (sz(a) >= ans) {
		return;
	}
	for (int i = last + 1; i <= v; ++i) {
		a.pb(i);
		solve(v, a, i);
		a.pop_back();
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	cin >> T;
	for (int test = 1; test <= T; ++test) {
		int c, v;
		cin >> c >> d >> v;
		vi a(d);
		for (int i = 0; i < d; ++i) {
			cin >> a[i];
		}
		ans = d + 5;
		solve(v, a);
		cout << "Case #" << test << ": " << ans - d << endl;
	}
}

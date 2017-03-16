#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <deque>
#include <bitset>

#define sqr(x) ((x) * (x))
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define y0 ywuerosdfhgjkls
#define y1 hdsfjkhgjlsdfhgsdf
#define j1 j924
#define j0 j2834
#define sqrt(x) (sqrt(abs(x)))
#define re return
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = ((n) - 1); i >= 0; i--)
#define fill(a, x) memset(a, x, sizeof(a))

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <ii> vii;
typedef vector <vi> vvi;
typedef double D;
typedef vector <string> vs;

template <class T> inline T abs(T a) {
	return a > 0 ? a : -a;
}

int n;
int m;

const int nkeys = 201;
const int nboxes = 200;

int start[nkeys];
int key[nboxes];
int inside[nboxes][nkeys];

vi ans[1 << 20];
bool ok[1 << 20];
bool calc[1 << 20];

vi go(int mask, int n) {
	if (mask == ((1 << n) - 1)) {
		ok[mask] = true;
		calc[mask] = true;	
		re vi(0);
	}
	if (calc[mask]) {
		re ans[mask];
	}
	calc[mask] = true;
	vi &ans = ::ans[mask];
	int cur[nkeys];
	rep(i, nkeys)
		cur[i] = start[i];
	rep(i, n) {
		if (mask & (1 << i)) {
			cur[key[i]]--;
			rep(j, nkeys) {
				cur[j] += inside[i][j];
			}
		}
	}
	rep(i, n) {
		if (!(mask & (1 << i)) && cur[key[i]]) {
			vi tmp = go(mask ^ (1 << i), n);
			if (ok[mask ^ (1 << i)]) {
				ans = tmp;
				ans.pb(i);
				ok[mask] = true;
				return ans;
			}
		}
	}
	ok[mask] = false;
	ans = vi(0);
	return ans;
}

int main() {
	int T;
	cin >> T;
	rep(I, T) {
		fill(start, 0);
		fill(key, 0);
		fill(inside, 0);
		int k, n;
		cin >> k >> n;
		rep(i, k) {
			int x;
			cin >> x;
			start[x]++;
		}
		rep(i, n) {
			int m;
			cin >> key[i] >> m;
			rep(j, m) {
				int x;
				cin >> x;
				inside[i][x]++;
			}

		}
		fill(ok, 0);
		fill(calc, 0);
		vi ans = go(0, n);
		reverse(all(ans));
		cout << "Case #" << I + 1 << ":";
		if (!sz(ans)) {
			cout << " IMPOSSIBLE" << endl;
			continue;
		}
		rep(i, sz(ans))
			cout << " " << ans[i] + 1;
		cout << endl;
	}
	return 0;
}

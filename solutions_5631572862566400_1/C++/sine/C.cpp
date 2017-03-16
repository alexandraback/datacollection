#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <iomanip>

#pragma warning (disable:4996)

using namespace std;

#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); i--)

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define sz(x) ((int)(x).size())

typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> pii;

const ll mod = 1000000007;
ll powmod(ll a, ll b) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1) res = res*a%mod; a = a*a%mod; } return res; }

int main() {
	freopen("C-large.in", "r", stdin);
	freopen("c-l.out", "w", stdout);
	int t, cas = 1;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vi f(n + 1);
		vi st(n + 1, 0);
		vi eo(n + 1, 0);
		rep(i, 1, n + 1) {
			cin >> f[i];
		}
		int ans = 0;
		rep(i, 1, n + 1) {
			vi lp(n + 1, 0);
			int j = i;
			int sans = 0;
			int eans = -1;
			while (lp[f[j]] == 0) {
				lp[j] = 1;
				j = f[j];
				eans++;
			}
			if (f[f[j]] == j) {
				eo[j] = max(eo[j], eans);
			}
			while (st[j] == 0) {
				sans++;
				st[j] = 1;
				j = f[j];
			}
			ans = max(ans, sans);
		}
		int seo = 0;
		rep(i, 1, n + 1) {
			if (i == f[f[i]]) seo += (eo[i] + 1);
		}
		ans = max(ans, seo);
		cout << "Case #" << cas++ << ": " << ans << endl;
	}
	return 0;
}

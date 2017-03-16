#include <iostream>
#include <cstdio>
#include <cassert>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <algorithm>
#include <cmath>
#include <complex>
#include <string>
#include <sstream>
#include <cstdlib>
#include <numeric>
#include <bitset>
#include <deque>
#include <cstring>
using namespace std;

#define REP(i, m, n) for(int i=(m); i<int(n); ++i)
#define rep(i, n) for(int i=0; i<int(n); ++i)
#define each(it, a) for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); ++it)
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define pb push_back                                                                          
#define mp make_pair
#define def(a, x) __typeof(x) a = x
#define fi first
#define se second
typedef long long ll;
typedef pair<ll, ll> PI;
const int dx[] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[] = {0, 1, 0, -1, 1, -1, 1, -1};

const int INF = 1<<29;

const ll MOD = 1000000007;

class Modular {
public:
	ll N, mod;
	vector<ll> _fact, _invfact;
	Modular(ll N, ll mod) : N(N), mod(mod), _fact(N+1), _invfact(N+1) {
		assert(N < mod && 2 <= mod);
		_fact[0] = 1;
		rep(i, N) _fact[i+1] = _fact[i] * (i+1) % mod;
		_invfact[N] = pow(_fact[N], mod-2);
		rep(i, N) _invfact[N-i-1] = _invfact[N-i] * (N-i) % mod;
		assert(_invfact[0] == 1);
	}
	ll pow(ll b, ll p) { assert(p>=0); ll a=1; for(ll k=b%mod; p; p>>=1, k=k*k%mod) if (p&1) a=a*k%mod; return a; }
	ll inverse(ll x) { assert(x); return pow(x, mod-2); }
	ll fact(ll n) { assert(0<=n && n<=N); return _fact[n]; }
	ll invfact(ll n) { assert(0<=n && n<=N); return _invfact[n]; }
	ll comb(ll n, ll k) { return 0 <= k && k <= n ? assert(n<=N), _fact[n] * _invfact[n-k] % mod * _invfact[k] % mod : 0; } 
};

int N;
bool G[26][26];
int vis[26];

bool check(string s) {
	bool app[26] = {};
	bool ok = true;
	int cur = -1;
	rep(i, sz(s)) {
		int c = s[i]-'a';
		if (cur != c && app[c]) {
			ok = false;
			break;
		}
		cur = c;
		app[cur] = true;
	}
	return ok;
}
bool dfs(int i, int p) {
	if (vis[i] != -1) return false;
	vis[i] = p;
	rep(j, 26) if (G[i][j]) dfs(j, p);
	return true;
}
void solve() {
	Modular md(1000, MOD);
	cin >> N;
	vector<string> ss(N);
	rep(i, N) cin >> ss[i];

	ll ans = 1;
	int app[N];
	int inner[N];
	map<int, ll> M;
	int degs[2][110];
	memset(degs, 0, sizeof(degs));
	memset(G, 0, sizeof(G));
	bool valid[110] = {};
	rep(i, N) {
		if (!check(ss[i])) {
			cout << 0 << endl;
			return;
		}
		app[i] = 0;
		inner[i] = 0;
		rep(j, sz(ss[i])) {
			app[i] |= 1<<int(ss[i][j]-'a');
			if (ss[i][j] != ss[i][0] && ss[i][j] != ss[i][sz(ss[i])-1]) {
				inner[i] |= 1<<int(ss[i][j]-'a');
			}
		}
		int a = ss[i][0]-'a', b = ss[i][sz(ss[i])-1]-'a';
		valid[a] = valid[b] = true;
		if (__builtin_popcountll(app[i]) == 1) M[app[i]]++;
		else {
			degs[0][a]++;
			degs[1][b]++;
			G[a][b] = true;
		}
	}
	rep(i, N) rep(j, N) if (i != j) {
		if (inner[i] & app[j]) {
			/*
			cout << endl;
			cout << i << " " << j << endl;
			cout << bitset<26>(inner[i]) << endl;
			cout << bitset<26>(app[j]) << endl;
			*/
			cout << 0 << endl;
			return;
		}
	}
//	rep(k, 2) rep(i, 26) cout << k << " " << i << "  " << degs[k][i]  << endl;
	rep(k, 2) rep(i, 26) if (degs[k][i] > 1) {
		cout << 0 << endl;
		return;
	}

	ll cnt = 0;
	memset(vis, -1, sizeof(vis));
	rep(i, 26) if (valid[i] && degs[1][i] == 0 && dfs(i, i)) cnt++;
	rep(i, 26) if (valid[i] && vis[i] == -1) {
		cout << 0 << endl;
		return;
	}

	each(it, M) (ans *= md.fact(it->second)) %= MOD;
	(ans *= md.fact(cnt)) %= MOD;
	cout << ans << endl;
}

int main() {
	int T; cin >> T;
	for(int t=1; t<=T; t++) {
		cout << "Case #" << t << ": ";
		solve();
	}
}


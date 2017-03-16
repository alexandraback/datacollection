#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define present(t, x) (t.find(x) != t.end())
#define all(a) (a).begin(), (a).end()
#define uni(a) (a).erase(unique(all(a)), (a).end())
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define prec(n) fixed<<setprecision(n)
#define bit(n, i) (((n) >> (i)) & 1)
#define bitcount(n) __builtin_popcountll(n)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = acos((ld) -1);
const ld EPS = 1e-9;
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
inline ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> inline int chkmin(T& a, const T& val) {return a > val ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
inline ll isqrt(ll k) {ll r = sqrt(k) + 1; while (r * r > k) r--; return r;}
inline ll icbrt(ll k) {ll r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}

int cnt[26];
char digit[][10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
vi ans;

void go(int n, vi& cur) {
	if (sz(ans)) return;
	if (n == 10) {
		int ok = 1;
		FOR(i, 0, 26) {
			if (cnt[i]) {
				ok = 0;
				break;
			}
		}
		if (ok) {
			ans = cur;
		}
		return;
	}
	FOR(i, 0, 10) {
		FOR(j, 0, i) cur.pb(n);
		FOR(j, 0, strlen(digit[n])) cnt[digit[n][j] - 'A'] -= i;
		int ok = 1;
		FOR(j, 0, 26) {
			if (cnt[j] < 0) {
				ok = 0;
				break;
			}
		}
		if (ok) {
			go(n + 1, cur);
		}
		FOR(j, 0, strlen(digit[n])) cnt[digit[n][j] - 'A'] += i;
		FOR(j, 0, i) cur.pop_back();
	}
}

void solve() {
	int T; cin>>T;
	FOR(t, 1, T + 1) {
		cout<<"Case #"<<t<<": ";
		string s; cin>>s;
		ms(cnt, 0);
		FOR(i, 0, sz(s)) cnt[s[i] - 'A']++;
		vi cur; ans.clear();
		go(0, cur);
		FOR(i, 0, sz(ans)) cout<<ans[i];
		cout<<"\n";
	}
}

int main() {
//	ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	//printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}

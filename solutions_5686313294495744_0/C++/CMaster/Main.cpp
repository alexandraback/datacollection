#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define sz(s) ((int)(s.size()))
#define all(s) s.begin(),s.end()
#define rep(i,a,n) for(int i=a;i<=n;++i)
#define per(i,n,a) for(int i=n;i>=a;--i)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int MAXN = 3e5 + 256;
const char nxtl = '\n';
const double eps = (double)1e-9;
template<typename T> inline bool updmin(T &a, const T &b) {return a > b ? a = b, 1 : 0;}
template<typename T> inline bool updmax(T &a, const T &b) {return a < b ? a = b, 1 : 0;}

void solve(int t) {
	map < string, int > q, w;
	int n; cin >> n;
	vector < pair < string, string > > v;
	rep(i, 1, n) {
		string s, _s; cin >> s >> _s;
		q[s]++; w[_s]++;
		v.pb(mp(s, _s));
	}
	int res = 0;
	rep(msk, 1, (1<<n)-1) {
		bool ok = 1;
		rep(pos, 0, n-1) {
			if((1<<pos) & msk) {
				q[v[pos].first]--, w[v[pos].second]--;
			}
		}
		rep(pos, 0, n-1) {
			if((1<<pos) & msk) {
				ok &= (q[v[pos].first] >= 1 && w[v[pos].second] >= 1);
			}
		}
		rep(pos, 0, n-1) {
			if((1<<pos) & msk) {
				q[v[pos].first]++; w[v[pos].second]++;
			}
		}
		if(ok) updmax(res, __builtin_popcount(msk));
	}
	printf("Case #%d: %d\n", t, res);
}

int main() {
	#ifdef accepted
		freopen(".in", "r", stdin);
		freopen("a.out", "w", stdout);
	#endif
	int t; cin >> t;
	rep(i, 1, t) solve(i);
	return 0;
}

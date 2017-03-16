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

string s, _s;

ull _x, _y, res = LLONG_MAX;

void gen(ull x = 0, ull y = 0, int i = 0) {
	if(i == sz(s)) {
		if(updmin(res, max(x, y) - min(x, y))) _x = x, _y = y;
		return;
	}
	if(s[i] != '?' && _s[i] != '?') gen(x * 10ull + (s[i] - '0'), y * 10ull + (_s[i] - '0'), i+1);
	else if(s[i] == '?' && _s[i] != '?') {
		rep(ii, 0, 9) gen(x * 10ull + ii, y * 10ull + (_s[i] - '0'), i+1);
	}
	else if(s[i] != '?' && _s[i] == '?') {
		rep(ii, 0, 9) gen(x * 10ull + (s[i] - '0'), y * 10ull + ii, i+1);
	}
	else {
		rep(ii, 0, 9) rep(jj, 0, 9) {
			gen(x * 10ull + ii, y * 10ull + jj, i+1);
		}
	}
}

int main() {
	#ifdef accepted
		freopen(".in", "r", stdin);
		freopen("a.out", "w", stdout);
	#endif
	int t; cin >> t;
	int id = 1;
	while(t--) {
		cin >> s >> _s;
		printf("Case #%d: ", id++);
		gen();
		int cnt = 0;
		ull N = _x;
		do {
			cnt++;
			N /= 10ull;
		} while(N);
		cnt = sz(s) - cnt;
		rep(i, 1, cnt) cout << 0;
		cout << _x << ' ';
		N = _y;
		cnt = 0;
		do {
			cnt++;
			N /= 10ull;
		} while(N);
		cnt = sz(s) - cnt;
		rep(i, 1, cnt) cout << 0;
		cout << _y << nxtl;
		res = LLONG_MAX;
	}
	return 0;
}

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

string num[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
bool check(vector < int > &v, const string &w) {
	for(auto &to : w) v[to]--;
	bool ok = (*min_element(all(v)) >= 0);
	if(!ok) for(auto &to : w) v[to]++;
	return ok;
}
void solve(int t) {
	vector < int > v(555, 0);
	string cur; cin >> cur;
	for(auto &to : cur) v[to]++;
	string res = "";
	while(v['Z'] > 0) {
		assert(check(v, "ZERO"));
		res += (char)('0');
	}
	while(v['W'] > 0) {
		assert(check(v, "TWO"));
		res += (char)(2 + '0');
	}
	while(v['U'] > 0) {
		assert(check(v, "FOUR"));
		res += (char)(4 + '0');
	}
	while(v['X'] > 0) {
		assert(check(v, "SIX"));
		res += (char)(6 + '0');
	}
	while(v['G'] > 0) {
		assert(check(v, "EIGHT"));
		res += (char)(8 + '0');
	}
	while(v['H'] > 0) {
		assert(check(v, "THREE"));
		res += (char)(3 + '0');
	}
	while(v['O'] > 0) {
		assert(check(v, "ONE"));
		res += (char)(1 + '0');
	}
	while(v['F'] > 0) {
		assert(check(v, "FIVE"));
		res += (char)(5 + '0');
	}
	while(v['V'] > 0) {
		assert(check(v, "SEVEN"));
		res += (char)(7 + '0');
	}
	while(check(v, "NINE")) {
		res += (char)(9 + '0');
	}
	sort(all(res));
	if(!(*min_element(all(v)) == 0 && *max_element(all(v)) == 0)) {
		cerr << cur << ' '<< t << nxtl;
		exit(0);
	}
	printf("Case #%d: ", t);
	cout << res << nxtl;
}
int t;

int main() {
	#ifdef accepted
		freopen(".in", "r", stdin);
		freopen("a.out", "w", stdout);
	#endif
	cin >> t;
	rep(i, 1, t) solve(i);
	return 0;
}

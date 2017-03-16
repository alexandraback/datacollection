#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0;i < n;++i)
#define FOR(i, a, b) for(int i = a;i < b;++i)
#define F first
#define S second
typedef vector<int> vi;
typedef long long int ll;
typedef pair<int, int> ii;
typedef long long int ll;
typedef long double ld;
#define pc(x) __builtin_popcount(x)

int k, g, s;
string goal, key;
vector<char> slo;
ld p[220];
int m = 0;
ld r = 0;

void check(string str) {
	int cnt = 0;
	REP(i, s - g + 1) if(str.substr(i, g) == goal)++cnt;
	m = max(m, cnt);
	ld pr = ld(cnt);
	REP(i, s) pr *= p[str[i]];
	r += pr;
}

void perm(string str) {
	if(str.length() == s) check(str);
	else REP(i, slo.size()) perm(str + slo[i]);
}

void init() {
	set<char> s;
	REP(i, k) ++p[key[i]];
	REP(i, 220) {
		if(p[i]) slo.push_back(char(i));
		p[i] /= ld(k);
	}
}

int main() {
	int t;
	cin >> t;
	REP(i, t) {
		cin >> k >> g >> s >> key >> goal;
		m = 0;
		r = 0;
		slo.clear();
		REP(i, 220) p[i] = 0;
		init();
		perm("");
		cout << fixed << setprecision(10) << "Case #" << i + 1 << ": " << ld(m) - r << "\n";
	}
}
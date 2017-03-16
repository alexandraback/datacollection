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

int c, d, v;
int res = 0;
int have;

void init() {
	if((have & 2) == 0) {
		have |= 2;
		++res;
	}
	if(v >= 2) {
		if((have & 4) == 0) {
			have |= 4;
			++res;
		}
	}
}

int getsum(int x) {
	int res = 0;
	REP(i, v + 1) if((1 << i) & x) res += i;
	return res <= v ? res : 0;
}

bool valid(int x) {
	int S = x, it = S;
	int a = 1;
	do {
		a |= 1 << (getsum(it));
  		it = (it - 1) & S;
	} while (it != S);
	return a == (1 << (v + 1)) - 1;
}

int solve() {
	set<int> s;
	set<int> sol;
	int r = 100;
	FOR(i, 2, 17) FOR(j, 2, 17) FOR(k, 2, 17) {
		s.clear();
		s.insert(i);
		s.insert(j);
		s.insert(k);
		if(s.find(2) != s.end()) s.erase(s.find(2));
		int mask = 0;
		for(auto it : s) mask |= 1 << it;
		sol.insert(mask);
	}
	for(auto it : sol) {
		if(valid(have | it)) r = min(r, pc(it));
	}
	return r;
}

int main() {
	int t;
	cin >> t;
	REP(i, t) {
		cin >> c >> d >> v;
		res = have = 0;
		REP(i, d) {
			int x;
			cin >> x;
			have |= (1 << x);
		}
		init();
		res += solve();
		cout << "Case #" << i + 1 << ": " << res << "\n";
	}
}
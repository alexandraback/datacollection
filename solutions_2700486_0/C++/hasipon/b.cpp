#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;
vector<map<set<pair<int,int> >, double> > ans;
double solve() {
	int N, X, Y;
	cin >> N >> X >> Y;
	double p = 0;
	for (map<set<pair<int,int> >, double>::iterator it = ans[N].begin(); it != ans[N].end(); ++ it) {
		if (it->first.count(make_pair(X, Y))) p += it->second;
	}
	return p;
}
void f(int t, int x, int y, const set<pair<int,int> >& s, double p) {
	if (p == 0) return;
	if (y == 0) {
		set<pair<int,int> > ss = s;
		ss.insert(make_pair(x, y));
		ans[t][ss] += p;
		return;
	}
	int x0 = s.count(make_pair(x-1, y-1));
	int x1 = s.count(make_pair(x+1, y-1));
	if (x0) {
		if (x1) {
			set<pair<int,int> > ss = s;
			ss.insert(make_pair(x, y));
			ans[t][ss] += p;
		} else {
			f(t, x+1, y-1, s, p);
		}
	} else {
		if (x1) {
			f(t, x-1, y-1, s, p);
		} else if (s.count(make_pair(x, y-2))) {
			f(t, x-1, y-1, s, p/2);
			f(t, x+1, y-1, s, p/2);
		} else {
			f(t, x, y-2, s, p);
		}
	}
}
int main() {
	ans.resize(21);
	set<pair<int,int> > x;
	x.insert(make_pair(0,0));
	ans[1][x] = 1.0;
	for (int t = 2; t <= 20; ++ t) {
		for (map<set<pair<int,int> >, double>::iterator it = ans[t-1].begin(); it != ans[t-1].end(); ++ it) {
			f(t, 0, 50, it->first, it->second);
		}
	}
	int T;
	cin >> T;
	for (int tt = 1; tt <= T; ++ tt) {
		printf("Case #%d: %.7f\n", tt, solve());
	}
}

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>

using namespace std;

#define REP(i,n) for(int i = 0; i < (n); i++)
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define FORD(i,a,b) for(int i = (a); i >= (b); i--)

int id = 1;
map<string, int> m;

int toid(string s) {
	if (m.count(s) == 0) {
		m[s] = id++;
	}
	return m[s];
}

int vis[2200];
int put[2200];
int vi = 1;

void solve() {
	vi++;
	int n;
	cin >> n;
	id = 1;
	m.clear();
	vector<int> as, bs;
	as.reserve(n);
	bs.reserve(n);
	map<int, int> sa, sb;
	REP(i, n) {
		string a, b;
		cin >> a >> b;
		int ia = toid(a);
		int ib = toid(b);
		as.push_back(ia);
		bs.push_back(ib);
		sa[ia]++;
		sb[ib]++;
	}
	int res = 0;
	int found = 0;
	while (found < n) {
		bool cnt = false;
		REP(i, n) if (vis[i] != vi) {
			if (sa[as[i]] == 1 || sb[bs[i]] == 1) {
				vis[i] = vi;
				put[as[i]] = vi;
				put[bs[i]] = vi;
				found++;
				cnt = true;
			}
		}
		if (cnt) continue;
		REP(i, n) if (vis[i] != vi) {
			if (put[as[i]] == vi && put[bs[i]] == vi) {
				vis[i] = vi;
				found++;
				res++;
				put[as[i]] = vi;
				put[bs[i]] = vi;
				cnt = true;
			}
		}
		if (cnt) continue;
		REP(i, n) if (vis[i] != vi) {
			if (put[as[i]] != vi && put[bs[i]] != vi) {
				vis[i] = vi;
				found++;
				put[as[i]] = vi;
				put[bs[i]] = vi;
				cnt = true;
				break;
			}
		}
		if (cnt) continue;
		REP(i, n) if (vis[i] != vi) {
				vis[i] = vi;
				found++;
				put[as[i]] = vi;
				put[bs[i]] = vi;
				cnt = true;
				break;
		}
	}
	cout << res;
}

int main() {
	int t;
	cin >> t;
	REP(i, t) {
		cout << "Case #" << (i+1) << ": ";
		solve();
		cout << endl;
	}
}
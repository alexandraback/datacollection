#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <memory.h>
#include <vector>
#include <sstream>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <complex>

using namespace std;

#define REP(a,b) for (int a=0; a<(int)(b); ++a)
#define FOR(a,b,c) for (int a=(b); a<(int)(c); ++a)

bool check_bad(vector <int> &p, int n) {
	priority_queue <int> q;

	REP(i, p.size()) q.push(p[i]);
	while (n > 0) {
		if (q.top() <= n) return true;
		int val = q.top();
		q.pop();
		q.push(val / 2); q.push(val - val / 2);
		--n;
	}

	return false;
}

bool check(vector <int> &p, int n) {
	int ndec, splits, s;
	for (int nsplit = 0; nsplit < n; ++nsplit) {
		ndec = n - nsplit; splits = 0;
		for (int i = 0; i < p.size() && splits <= nsplit; ++i) {
			if (p[i] > ndec) {
				splits += (p[i] + ndec - 1) / ndec - 1;
			}
		}
		if (splits <= nsplit) return true;
	}

	return false;
}


int solve(vector <int> &p) {
	int lo = 1, hi = p[0], m;

	while (lo < hi) {
		m = (lo + hi) / 2;
		if (check(p, m)) hi = m;
		else lo = lo + 1;
	}

	return lo;
}

int main() {
	int t, d, res;
	vector <int> p;

	cin >> t;

	REP(tc, t) {
		cin >> d;
		p.resize(d);
		REP(i, d) cin >> p[i];

		sort(p.rbegin(), p.rend());

		cout << "Case #" << tc + 1 << ": " << solve(p) << endl;
	}

	

	return 0;
}
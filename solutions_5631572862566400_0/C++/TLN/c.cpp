#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <complex>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <gmpxx.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (n); ++i)
#define foreach(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); ++it)

template<typename T> inline void ignore(T) {
}

int solve(const vector<int> &next, int n) {
	vector<vector<int> > prev(n);
	forn(i, n) {
		prev[next[i]].push_back(i);
	}

	// 1st case: longest cycle
	int longestCycle = 0;
	vector<int> from(n, -1);
	forn(i, n) {
		from[i] = i;
		int x = next[i];
		int len = 1;
		while (from[x] != i) {
			from[x] = i;
			x = next[x];
			++len;
		}
		if (x == i) {
			longestCycle = max(longestCycle, len);
		}
	}

	// 2nd case: longest branches from a 2-cycle
	vector<int> branches;
	forn(i, n) {
		if (next[next[i]] == i && i < next[i]) {
			vector<bool> marked(n, false);
			marked[i] = true;
			marked[next[i]] = true;
			stack<pair<int, int> > s;

			s.push(make_pair(i, 0));
			int l1 = 0;
			while(!s.empty()) {
				int u = s.top().first;
				int d = s.top().second;
				s.pop();
				l1 = max(d, l1);
				for (int v : prev[u]) {
					if (!marked[v]) {
						marked[v] = true;
						s.push(make_pair(v, d+1));
					}
				}
			}

			s.push(make_pair(next[i], 0));
			int l2 = 0;
			while(!s.empty()) {
				int u = s.top().first;
				int d = s.top().second;
				s.pop();
				l2 = max(d, l2);
				for (int v : prev[u]) {
					if (!marked[v]) {
						marked[v] = true;
						s.push(make_pair(v, d+1));
					}
				}
			}

			branches.push_back(2 + l1 + l2);
		}
	}

	sort(branches.begin(), branches.end());
	int maxPath = 0;
	for (int l : branches) {
		maxPath += l;
	}

	return max(maxPath, longestCycle);
}

int main(void) {
	int t; cin >> t;
	forn(k, t) {
		int n; cin >> n;
		vector<int> next(n);
		forn(i, n) {
			int f; cin >> f;
			next[i] = f - 1;
		}
		int ans = solve(next, n);
		cout << "Case #" << (k+1) << ": " << ans << endl;
	}
	return 0;
}

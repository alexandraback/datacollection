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


struct Bipartite {
	vector<vector<int> > adjLeft;
	vector<vector<int> > adjRight;
	vector<int> matchLeft, matchRight;
	vector<bool> visited;
	int matchingSize;

	Bipartite(int p = 0, int q = 0) :
		adjLeft(p), adjRight(q),
		matchLeft(p, -1), matchRight(q, -1), matchingSize(0) {}

	bool depthFirstSearch(int x) {
		if (visited[x]) return false;
		visited[x] = true;
		forn(i, (int) adjLeft[x].size()) {
			int y = adjLeft[x][i];
			int z = matchRight[y];
			if (z < 0 || depthFirstSearch(z)) {
				matchRight[y] = x;
				matchLeft[x] = y;
				return true;
			}
		}
		return false;
	}

	bool findAugmentingPath(void) {
		visited.assign(adjLeft.size(), false);
		forn(i, (int) adjLeft.size())
			if (matchLeft[i] == -1 && depthFirstSearch(i))
				return true;
		return false;
	}

	void greedyMatching(void) {
		forn(x, (int) adjLeft.size())
			forn(i, (int) adjLeft[x].size()) {
				int y = adjLeft[x][i];
				if (matchLeft[x] == -1 && matchRight[y] == -1) {
					matchLeft[x] = y;
					matchRight[y] = x;
					++matchingSize;
				}
			}
	}

	int maximumMatching(void) {
		while(findAugmentingPath()) ++matchingSize;
		return matchingSize;
	}
};

int solve(const vector<pair<string, string> > &inputs) {
	map<string, int> left, right;
	int p = 0, q = 0;
	vector<pair<int, int> > edges;
	for(auto &ab : inputs) {
		int i, j;
		if (left.count(ab.first)) {
			i = left[ab.first];
		} else {
			i = p++;
			left[ab.first] = i;
		}
		if (right.count(ab.second)) {
			j = right[ab.second];
		} else {
			j = q++;
			right[ab.second] = j;
		}
		edges.emplace_back(i, j);
	}

	Bipartite matching(p, q);
	for(auto &ij : edges) {
		matching.adjLeft[ij.first].push_back(ij.second);
		matching.adjRight[ij.second].push_back(ij.first);
	}
	matching.maximumMatching();
	vector<int> unmatchedLeft(p, -1), unmatchedRight(q, -1);
	forn(i, p) {
		if (matching.matchLeft[i] == -1) {
			unmatchedLeft[i] = matching.adjLeft[i].front();
		}
	}
	forn(j, q) {
		if (matching.matchRight[j] == -1) {
			unmatchedRight[j] = matching.adjRight[j].front();
		}
	}
	int fakes = 0;
	for(auto &ij : edges) {
		int i = ij.first;
		int j = ij.second;
		// Skip edges in matching
		if (matching.matchLeft[i] == j) {
			continue;
		}
		// Skip left
		if (unmatchedLeft[i] == j) {
			continue;
		}
		// Skip right
		if (unmatchedRight[j] == i) {
			continue;
		}
		++fakes;
	}
	return fakes;
}

int main(void) {
	int t; cin >> t;
	forn(k, t) {
		int n; cin >> n;
		vector<pair<string, string> > inputs;
		forn(i, n) {
			string a, b;
			cin >> a >> b;
			inputs.emplace_back(a, b);
		}
		int ans = solve(inputs);
		cout << "Case #" << (k+1) << ": " << ans << endl;
	}
	return 0;
}

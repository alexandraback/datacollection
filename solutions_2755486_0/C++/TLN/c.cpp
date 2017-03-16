/*
 * c.cpp
 *
 */

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

using namespace std;

#define forn(i, n) for (int i = 0; i < (n); ++i)
#define foreach(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); ++it)

template<typename T> inline void ignore(T) {
}

struct Node {
	int xmin, xmax;
	int height;

	vector<Node> children;
};

bool attack(int a, int b, int s, Node &t) {
	if (a <= t.xmin && t.xmax <= b && t.height >= s)
		return false;

	return true;
}

const int ox = 500;

struct Tribe {
	int init;
	int n;
	int w, e;
	int s;
	int delta_d;
	int delta_x;
	int delta_s;

	void read() {
		cin >> init >> n >> w >> e >> s;
		cin >> delta_d >> delta_x >> delta_s;
	}

	int xmin(int i) {
		return ox + 2 * (w + i * delta_x);
	}
	int xmax(int i) {
		return ox + 2 * (e + i * delta_x);
	}
	int stren(int i) {
		return s + i * delta_s;
	}
};

int solve() {
	vector<int> wall(1000, 0);
	int m;
	cin >> m;
	vector<Tribe> tribes(m);
	forn(i, m)
		tribes[i].read();
	int success = 0;
	bool under_attack = true;
	for (int day = 0; under_attack; ++day) {
		vector<pair<pair<int, int>, int> > repair;
		under_attack = false;
		forn(i, m)
		{
			Tribe &t = tribes[i];
			int j = (day - t.init) / t.delta_d;
			if (j < t.n)
				under_attack = true;
			if (day < t.init)
				continue;
			if ((day - t.init) % t.delta_d == 0 && j < t.n) {
				int hmin = numeric_limits<int>::max();
				for (int x = t.xmin(j); x <= t.xmax(j); ++x)
					hmin = min(hmin, wall[x]);
				if (hmin < t.stren(j)) {
					++success;
					repair.push_back(
					        make_pair(make_pair(t.xmin(j), t.xmax(j)),
					                  t.stren(j)));
				}
			}
		}
		foreach(it, repair)
		{
			int xmin = it->first.first;
			int xmax = it->first.second;
			int h = it->second;
			for (int x = xmin; x <= xmax; ++x)
				wall[x] = max(wall[x], h);
		}
	}
	return success;
}

int main(void) {
	int total;
	cin >> total;
	forn(nc, total)
	{
		int ans = solve();
		cout << "Case #" << (nc + 1) << ": " << ans << endl;
	}
	return 0;
}

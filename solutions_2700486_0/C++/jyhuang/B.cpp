#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

int N, X, Y;
long long total = 0, hit = 0;

void go(int k, map<int, set<int> > &m, int x)
{
	if (k == 0) {
		total++;
		if (m[X].count(Y) > 0) hit++;
		return;
	}

	if (m[x].size() == 0) {
		bool has_l = m[x - 1].count(0) > 0;
		bool has_r = m[x + 1].count(0) > 0;
		if (has_l && has_r) {
			m[x].insert(1);
			go(k - 1, m, 0);
			m[x].erase(1);
		} else if (has_l) {
			m[x + 1].insert(0);
			go(k - 1, m, 0);
			m[x + 1].erase(0);
		} else if (has_r) {
			m[x - 1].insert(0);
			go(k - 1, m, 0);
			m[x - 1].erase(0);
		} else {
			m[x].insert(0);
			go(k - 1, m, 0);
			m[x].erase(0);
		}
	} else {
		int y = *m[x].rbegin();
		bool has_l = m[x - 1].count(y + 1) > 0;
		bool has_r = m[x + 1].count(y + 1) > 0;
		// cout << has_l << " " << has_r << endl;
		if (has_l && has_r) {
			m[x].insert(y + 2);
			go(k - 1, m, 0);
			m[x].erase(y + 2);
		} else if (has_l) {
			go(k, m, x + 1);
		} else if (has_r) {
			go(k, m, x - 1);
		} else {
			go(k, m, x + 1);
			go(k, m, x - 1);
		}
	}
}

int main(int argc, char *argv[])
{
	int T;
	cin >> T;
	for (int ti = 1; ti <= T; ti++) {
		cin >> N >> X >> Y;
		total = hit = 0;
		map<int, set<int> > m;
		// m[0].insert(0);
		go(N, m, 0);
		// cout << total << endl;
		printf("Case #%d: %.12f\n", ti, (double) hit / total);
	}
	return 0;
}

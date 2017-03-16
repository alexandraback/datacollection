#include <sstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cassert>
#include <ctime>
#include <map>
#include <math.h>
#include <cstdio>
#include <set>
#include <deque>
#include <memory.h>
#include <queue>


using namespace std;

#pragma comment(linker, "/STACK:64000000")

typedef long long ll;

const int MAXK = 0;
const int MAXN = 1 << MAXK;
const int INF = (int)1e9;

int n;
vector<int> a;
vector<int> used;
vector<vector<int> > e;

int dfs(int v, int proh) {
	int mx = 0;
	for (int to : e[v]) {
		if (to == proh) continue;
		mx = max(mx, dfs(to, -1));
	}
	return mx + 1;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		cout << "Case #" << test << ": ";
		cerr << "Case #" << test << ": ";
		
		cin >> n;
		a.resize(n);
		e.assign(n, vector<int>());
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			a[i]--;
			e[a[i]].push_back(i);
		}
		int ans = 0;
		int sumpairs = 0;
		used.assign(n, 0);
		for (int i = 0; i < n; i++) {
			int v = i;
			vector<int> vct;
			bool bad = 0;
			while (1) {
				if (used[v] == 2) {
					bad = 1;
					break;
				}
				if (used[v] == 1) {
					break;
				}
				used[v] = 1;
				vct.push_back(v);
				v = a[v];
			}
			for (int i = 0; i < (int)vct.size(); i++) used[vct[i]] = 2;
			if (bad) continue;
			while (vct[0] != v) {
				vct.erase(vct.begin());
			}
			if (vct.size() == 2) {
				sumpairs += dfs(vct[0], vct[1]) + dfs(vct[1], vct[0]);
			}
			else {
				ans = max(ans, (int)vct.size());
			}
		}
		ans = max(ans, sumpairs);

		cout << ans << endl;
		cerr << ans << endl;
	}

	return 0;
}
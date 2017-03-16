#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <ctime>
#include <numeric>

using namespace std;

#define sqr(a) ((a)*(a))
#define two(a) (1 << (a))
#define has(mask, a) ((mask) & two(a) ? 1 : 0)

int n, m, can[55][55], used[55], was[55];

string z[55];

void load() {
	scanf ("%d%d\n", &n, &m);
	
	for (int i = 0;i < n;i++) {
		cin >> z[i];
	}

	memset (can, 0, sizeof (can));
	for (int i = 0, a, b;i < m;i++) {
		cin >> a >> b;
		a--, b--;
		can[a][b] = can[b][a] = 1;
	}
}

void dfs (int v) {
	was[v] = 1;
	for (int i = 0;i < n;i++) {
		if (was[i] || used[i] || !can[v][i]) continue;
		dfs (i);
	}
}

int go (vector <int> s, int v) {
	int sz = s.size();
	while (sz > 0 && !can[s[sz - 1]][v]) {
		sz--;
	}

	if (sz == 0) return 0;

	//cerr << v << " " << sz << " " << s[sz - 1] << " " << can[s[sz - 1]][v] << endl;

	was[v] = 1;
	int res = 0;
	for (int i = 0;i < sz;i++) {
		dfs (s[i]);
	}
	dfs (v);
	
	for (int i = 0;i < n;i++) {
		res += was[i] || used[i];
	}

	return res == n;
}

void solve(int test) {
	string ans = "";
	memset (used, 0, sizeof (used));
	vector <int> s;
	for (int i = 0;i < n;i++) {
		int cur = -1;
		for (int j = 0;j < n;j++) {
			if (used[j]) continue;
			memset (was, 0, sizeof (was));

			if ((cur == -1 || z[cur] > z[j]) && (i == 0 || go (s, j))) {
				cur = j;
			}
		}
		//cerr << cur << " " << endl;
		assert (cur != -1);
		while ((int)s.size() > 0 && !can[s.back()][cur]) s.pop_back();
		s.push_back (cur);
		ans += z[cur];
		used[cur] = 1;
	}

	printf ("Case #%d: %s\n", test, ans.c_str());
}

int main() {
 	freopen ("a.in", "r", stdin);

 	int t;
 	scanf ("%d\n", &t);

 	for (int i = 1;i <= t;i++) {
 		load();
 		solve(i);
 	}

 	return 0;
}
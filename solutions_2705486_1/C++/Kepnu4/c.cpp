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
#include <fstream >
using namespace std;

#define sqr(a) ((a)*(a))
#define two(a) (1 << (a))
#define has(mask, a) ((mask) & two(a) ? 1 : 0)

string d[600006];

int nsize, dp[4005][6];

string s;

void load() {
	cin >> s;
}

inline pair <int, int> check (int pos, string &t, int last) {
	int res = 0;
 	for (int i = 0;i < (int)t.size();i++) {
 	 	if (s[pos + i] == t[i]) {
 	 	 	last++;
 	 	 	continue;
 	 	}

 	 	if (last < 5) return make_pair (-1, -1);

 	 	res++;
 	 	last = 1;
 	}
 	return make_pair (min (last, 5), res);
}

void solve(int test) {
	memset (dp, -1, sizeof (dp));

	dp[0][5] = 0;

	for (int i = 0;i < (int)s.size();i++) {
	 	for (int j = 1;j <= 5;j++) {
	 	 	if (dp[i][j] == -1) continue;

	 	 	for (int k = 0;k < nsize;k++) {
	 	 		if (i + d[k].size() > s.size()) continue;

	 	 		pair <int, int> t = check (i, d[k], j);

	 	 		if (t.first == -1) continue;

	 	 		//if (i == 0 && d[k].size() == 4) {
	 	 		// 	cerr << d[k] << " " << t.first << " " << t.second << endl;
	 	 		//}

	 	 		if (dp[i + d[k].size()][t.first] == -1 || dp[i + d[k].size()][t.first] > dp[i][j] + t.second) {
	 	 		 	dp[i + d[k].size()][t.first] = dp[i][j] + t.second;
	 	 		}
	 	 	}
	 	}
	}

	int ans = 10000;
	for (int i = 1;i <= 5;i++) {
		if (dp[s.size()][i] != -1) ans = min (ans, dp[s.size()][i]);
   	}

	printf ("Case #%d: %d\n", test, ans);
}

int main() {
	ifstream in ("dict");

	while (in >> d[nsize]) {
		nsize++;
	}

 	freopen ("a.in", "r", stdin);
 	freopen ("1", "w", stdout);

 	int t;
 	scanf ("%d\n", &t);

 	for (int i = 1;i <= t;i++) {
 		load();
 		solve(i);
 	}

 	return 0;
}
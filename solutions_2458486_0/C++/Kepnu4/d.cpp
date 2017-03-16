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

using namespace std;

#define sqr(a) ((a)*(a))
#define two(a) (1 << (a))
#define has(mask, a) ((mask) & two(a) ? 1 : 0)

int n, k, type[555], dp[1 << 20], p[1 << 20];

vector <int> ch[555];

map <int, int> cur;

void load() {
	cin >> k >> n;

	cur.clear();

	for (int i = 0;i < k;i++) {
	 	int a;
	 	cin >> a;
	 	cur[a]++;
	}

	for (int i = 0;i < n;i++) {
	    int t, k;
	    cin >> t >> k;
	    type[i] = t;

	    ch[i].resize(0);

	    for (int j = 0;j < k;j++) {
	     	int a;
	     	cin >> a;
	     	ch[i].push_back (a);
	    }
	}	
}

bool go (int mask) {
 	if (mask == two (n) - 1) return true;

 	int &res = dp[mask];
 	if (res != -1) return res;
 	res = 0;

 	map <int, int> keys = cur;

 	for (int i = 0;i < n;i++) {
 	 	if (!has (mask, i)) continue;

 	 	keys[type[i]]--;
 	 	for (int j = 0;j < (int)ch[i].size();j++) {
 	 	 	keys[ch[i][j]]++;
 	 	}
 	}

 	for (int i = 0;i < n;i++) {
 	 	if (has (mask, i) || keys[type[i]] == 0) continue;

 	 	int t = go (mask | two (i));
 	 	if (t) {
 	 		res = 1;
 	 		p[mask | two (i)] = i;
 	 		return 1;
 	 	}
 	}    	
 	return 0;
}

void solve(int test) {
	memset (dp, -1, sizeof (dp));

	if (!go (0)) {
	 	printf ("Case #%d: IMPOSSIBLE\n", test);
	 	return;
	}

	vector <int> ans;

	int cur = two (n) - 1;
	while (cur > 0) {
	 	ans.push_back (p[cur]);
	 	cur ^= two (p[cur]);
	}
	printf ("Case #%d: ", test);

	for (int i = (int)ans.size() - 1;i >= 0;i--) {
	 	printf ("%d ", ans[i] + 1);
	}
	printf ("\n");
}

int main() {
 	freopen ("a.in", "r", stdin);
 	freopen ("a.out", "w", stdout);

 	int t;
 	scanf ("%d\n", &t);

 	for (int i = 1;i <= t;i++) {
 		load();
 		solve(i);
 	}

 	return 0;
}

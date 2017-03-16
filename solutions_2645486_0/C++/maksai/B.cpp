#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
#define pii pair<int, int>
#define pdd pair<double, double>
#define mp make_pair
#define x first
#define y second
#define L(s) ((int)(s).size())
#define pb push_back
#define VI vector<int>
#define ll long long
int v[11111];
int n, tc, E, R;
inline ll solve(int st, int fn, int st_val, int fn_val) {
	if (st == fn) return 0;
	if (st + 1 == fn) {
		return (ll)v[st] * (st_val - fn_val);
	}
	int best_pos = st;
	for(int i = st + 1; i < fn; ++i) {
		if (v[i] > v[best_pos]) {
			best_pos = i;
		}
	}
	int at_pos = (int)(min((ll)E, (ll)st_val + (ll)(best_pos - st) * R));
	int after_pos = (int)(max(0LL, (ll)fn_val - (ll)(fn - 1 - best_pos) * R));
	if (at_pos < after_pos) {
		cerr << "ERROR\n";
		exit(0);
	}
	return (ll)(at_pos - after_pos) * v[best_pos] + 
				solve(st, best_pos, st_val, at_pos - R) +
				solve(best_pos + 1, fn, after_pos + R, fn_val);

}

inline int dfs(int lev, int en) {
	if (lev == n) return 0;
	int best = 0;
	for(int sp = 0; sp <= en; ++sp) {
		best = max(best, sp * v[lev] + dfs(lev + 1, min(E, en - sp + R)));
	}
	return best;
}
int main() {
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &tc);
	for(int tn = 1; tn <= tc; ++tn) {
		cerr << tn << endl;
		scanf("%d%d%d", &E, &R, &n);
		for(int i = 0; i < n; ++i) {
			scanf("%d", &v[i]);
		}
		cout << "Case #" << tn << ": " << solve(0, n, E, 0) << endl;
	}
} 
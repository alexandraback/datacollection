#include <iostream>
#include <cstdio>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;

int itc;
vector<vector<int>> ra;

int geth(int u) {
	// printf("%d\n", u);
	if (ra[u].empty()) return 0;
	int h = 0;
	for (int v: ra[u]) {
		h = max(h, geth(v));
	}
	return h+1;
}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	ra.assign(n, {});
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
		ra[a[i]].push_back(i);
	}
	vector<array<int,2>> b;
	vector<bool> vis(n, false);
	vector<bool> instk(n, false);
	int maxszcyc = 0;
	for (int i = 0; i < n; i++) if (!vis[i]) {
		int j;
		for (j = i; !vis[j] && !instk[j]; j = a[j]) {
			instk[j] = true;
		}
		if (!vis[j]) {
			int szcyc = 1;
			for (int k = a[j]; k != j; k = a[k]) szcyc++;
			maxszcyc = max(maxszcyc, szcyc);
			if (szcyc == 2) {
				b.push_back({j, a[j]});
				// printf("%d %d\n", j, a[j]);
				ra[j].erase(remove(ra[j].begin(), ra[j].end(), a[j]), ra[j].end());
				ra[a[j]].erase(remove(ra[a[j]].begin(), ra[a[j]].end(), j), ra[a[j]].end());
				// printf("%d %d\n", (int)ra[j].size(), (int)ra[a[j]].size());
				// for (auto x: ra[j]) printf("%d ", x); puts("");
				// for (auto x: ra[a[j]]) printf("%d ", x); puts("");
			}
		}
		for (int k = i; !vis[k]; k = a[k]) {
			vis[k] = true;
		}
	}
	// printf("%d\n", maxszcyc);
	int ans1 = 0;
	for (auto c: b) for (int u: c) {
		ans1 += 1+geth(u);
	}
	// printf("%d\n", ans1);
	int ans = max(ans1, maxszcyc);
	printf("%d\n", ans);
}

int main() {
	cin.sync_with_stdio(false);
	int ntc;
	cin >> ntc;
	for (itc = 1; itc <= ntc; itc++) {
		printf("Case #%d: ", itc);
		solve();
	}
}

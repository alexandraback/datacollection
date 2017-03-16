#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <string>
#include <map>
#include <cstdlib>
#include <ctime>
using namespace std;

#pragma comment(linker, "/STACK:64000000")

#define sqr(x) ((x)*(x))

int t;
int k, n;
int tp[105];
vector<int> ks[105];
int cur[105];
bool the_end;
int test;
bool used[105];
set<long long> hashcode;
long long deg[105];
long long p = 57;
int ans[105];

void init() {
	deg[0] = 1;
	for (int i = 1; i < 105; i++)
		deg[i] = deg[i - 1] * p;
}
void rec(int rest, long long cur_hash) {
	if (the_end || hashcode.find(cur_hash) != hashcode.end()) return;
	hashcode.insert(cur_hash);
	if (!rest) {
		the_end = true;
		cout << "Case #" << test << ":";
		for (int i = 1; i <= ans[0]; i++) cout << " " << ans[i];
		cout << endl;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (used[i]) continue;
		if (cur[tp[i]] == 0) continue;
		cur[tp[i]]--;
		used[i] = true;
		ans[++ans[0]] = i;
		for (int j = 0; j < ks[i].size(); j++) cur[ks[i][j]]++;
		rec(rest - 1, cur_hash + i*deg[i]);
		cur[tp[i]]++;
		used[i] = false;
		ans[0]--;
		for (int j = 0; j < ks[i].size(); j++) cur[ks[i][j]]--;
	}
}
int main() {
	freopen("D-small-attempt0.in", "rt", stdin);
	freopen("D-small-attempt0.out", "wt", stdout);

	init();
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> k >> n;
		for (int j = 0; j < 105; j++) cur[j] = 0;
		for (int j = 0; j < k; j++) {
			int a; cin >> a; 
			cur[a]++;
		}
		for (int j = 0; j < 105; j++) {
			ks[j].clear();
		}
		for (int j = 1; j <= n; j++) {
			int type; cin >> type;
			tp[j] = type;
			int q; cin >> q;
			for (int m = 0; m < q; m++) {
				int keys; cin >> keys;
				ks[j].push_back(keys);
			}
		}
		test = i + 1;
		the_end = false;
		hashcode.clear();
		rec(n, 0);
		if (!the_end) {
			cout << "Case #" << test << ": IMPOSSIBLE" << endl;
		}
	}

	return 0;
}
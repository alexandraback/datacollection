#include <iostream>
#include <cstdio>
#include <algorithm>
#include <math.h>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <memory.h>
#include <ctime>
#include <cassert>

using namespace std;

const int maxn = 401;

int n, m;
int t[maxn], k[maxn], b[maxn];
vector<int> a[maxn], ans;
vector<int> p[1 << 20];

void checksolve(vector<int> ans) {
	vector<int> cnt(201, 0);
	for (int i = 0; i < m; i++)
		cnt[b[i]]++;

	for (int i = 1; i <= n; i++) {
		ans[i]--;
		assert(cnt[t[ans[i]]] > 0);
		cnt[t[ans[i]]]--;
		for (int j = 0; j < a[ans[i]].size(); j++) {
			cnt[a[ans[i]][j]]++;
		}
	}
}

/*void rec(int mask) {
	if (!mask) return;
	rec(mask ^ (1 << p[mask]));
	ans.push_back(p[mask] + 1);
}*/

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		cout << "Case #" << test << ": ";

		cin >> m >> n;
		for (int i = 0; i < m; i++) {
			cin >> b[i];
		}

		for (int i = 0; i < n; i++) {
			cin >> t[i] >> k[i];
			a[i].clear();
			for (int j = 0; j < k[i]; j++) {
				int x;
				cin >> x;
				a[i].push_back(x);
			}
		}

		for (int i = 0; i < 1 << n; i++) p[i] = vector<int>(0);
		p[0].push_back(0);
		
		vector<int> cnt(201, 0);
		for (int i = 0; i < m; i++)
			cnt[b[i]]++;
		for (int mask = 0; mask < 1 << n; mask++) if (p[mask].size()) {
			for (int i = 0; i < n; i++) {
				if (mask & (1 << i)) {
					cnt[t[i]]--;
					for (int j = 0; j < a[i].size(); j++)
						cnt[a[i][j]]++;
				}
			}

			vector<int> v = p[mask];
			for (int i = 0; i < n; i++) { 
				v.push_back(i + 1);
				if (!(mask & (1 << i)) && cnt[t[i]] > 0 && (p[mask ^ (1 << i)].size() == 0 || v < p[mask ^ (1 << i)])) {
					p[mask ^ (1 << i)] = v;
				}
				v.pop_back();
			}

			for (int i = 0; i < n; i++) {
				if (mask & (1 << i)) {
					cnt[t[i]]++;
					for (int j = 0; j < a[i].size(); j++)
						cnt[a[i][j]]--;
				}
			}
		}

		if (p[(1 << n) - 1].size() == 0) {
			cout << "IMPOSSIBLE\n";
		} else {
			ans = p[(1 << n) - 1];
			for (int i = 1; i <= n; i++)
				cout << ans[i] << " \n"[i == n];
			checksolve(ans);
		}
	}

	return 0;
}
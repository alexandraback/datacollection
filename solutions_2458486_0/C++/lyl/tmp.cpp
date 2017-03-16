#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int maxn = 20;

int n, k, ko[maxn], cnt[210], from[1 << maxn];
vector<int> kn[maxn];
bool used[1 << maxn];


void dfs(int ss) {
	used[ss] = true;

	for (int i = 0; i < n; i++)
		if ((ss & (1 << i)) == 0 && cnt[ko[i]] > 0 && !used[ss + (1 << i)]) {
			cnt[ko[i]]--;
			for (int j = 0; j < kn[i].size(); j++)
				cnt[kn[i][j]]++;

			from[ss + (1 << i)] = i;
			dfs(ss + (1 << i));

			cnt[ko[i]]++;
			for (int j = 0; j < kn[i].size(); j++)
				cnt[kn[i][j]]--;
		}
}

int main() {
	int T;
	cin >> T;
	for (int tt = 1; tt <= T; tt++) {
		cin >> k >> n;
		int a;
		
		memset(cnt, 0, sizeof(cnt));
		memset(used, 0, sizeof(used));

		for (int i = 0; i < k; i++) {
			cin >> a;
			cnt[a]++;
		}
		
		for (int i = 0; i < n; i++) {
			cin >> ko[i];
			cin >> k;
			kn[i].clear();
			for (int j = 0; j < k; j++) {
				cin >> a;
				kn[i].push_back(a);
			}
		}

		dfs(0);
		if (used[(1 << n) - 1]) {
			vector<int> ans;
			int ss = (1 << n) - 1;
			for (int i = 0; i < n; i++) {
				ans.push_back(from[ss]);
				ss -= (1 << from[ss]);
			}

			printf("Case #%d:", tt);
			for (int i = n - 1; i >= 0; i--)
				printf(" %d", ans[i] + 1);
			printf("\n");
		} else
			printf("Case #%d: IMPOSSIBLE\n", tt);
	}
}

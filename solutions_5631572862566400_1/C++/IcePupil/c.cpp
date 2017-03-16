#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <queue>
#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
int n, m, ans, f[1100], len[1100];
int circle_id[1100];
bool vis[1100];
vector<int> circle[1100];

int main()
{
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	int nCase = 0, test;
	scanf("%d", &test);
	while (test --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) {
			scanf("%d", &f[i]);
		}
		m = 0;
		memset(circle_id, 0, sizeof(circle_id));
		int ans = 0;
		for (int i = 1; i <= n; i ++) {
			int j = i;
			memset(vis, false, sizeof(vis));
			while (!vis[j]) {
				vis[j] = true;
				j = f[j];
			}
			if (circle_id[j] == 0) {
				m ++;
				circle[m].clear();
				while (circle_id[j] == 0) {
					circle_id[j] = m;
					circle[m].push_back(j);
					j = f[j];
				}
				ans = max(ans, (int)circle[m].size());
			}
		}
		memset(len, 0, sizeof(len));
		for (int i = 1; i <= n; i ++)
		if (circle_id[i] == 0) {
			int j = i, k = 0;
			while (circle_id[j] == 0) {
				k ++;
				j = f[j];
			}
			len[j] = max(len[j], k);
		}
		int tot_len = 0;
		for (int i = 1; i <= m; i ++)
		if (circle[i].size() == 2) {
			tot_len += len[circle[i][0]] + len[circle[i][1]] + 2;
		}
		ans = max(ans, tot_len);
		nCase ++;
		printf("Case #%d: %d\n", nCase, ans);
	}
	return 0;
}

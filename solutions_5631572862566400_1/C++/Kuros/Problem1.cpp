#include <bits/stdc++.h>

using namespace std;

int T;

int BFF[1100];

vector<int> g[1100];

bool vis[1100];

int ans;

void find(int x, int num, int first) {
	vis[x] = 1;
	if(BFF[x] == first) ans = max(ans, num);
	if(!vis[BFF[x]]) find(BFF[x], num + 1, first);
	vis[x] = 0;
}

int dfs(int x, int first) {
	if(g[x].size() == 0) return 1;

	int mx = 0;
	for(int i = 0; i < g[x].size(); i++) {
		int v = g[x][i];
		if(v == BFF[first]) continue;
		mx = max(mx, dfs(v, first));
	}

	return mx + 1;
}

int main() {
	freopen("C-large.in","r",stdin);
	freopen("ans.txt","w",stdout);

	scanf("%d", &T);
	int cas = 1;
	while(T--) {
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) g[i].clear();
		for(int i = 1; i <= n; i++) {
			scanf("%d", &BFF[i]);
			g[BFF[i]].push_back(i);
		}
		ans = 0;

		for(int i = 1; i <= n; i++) {
			find(i, 1, i);
		}
		
		int sum = 0;
		
		for(int i = 1; i <= n; i++) {
			if(BFF[BFF[i]] == i && i < BFF[i]) {
				int a = dfs(i, i);
				int b = dfs(BFF[i], BFF[i]);
				sum += a + b;
			}
		}

		ans = max(ans, sum);


		printf("Case #%d: %d\n", cas++, ans);
	}
}
#include <bits/stdc++.h>
using namespace std;

int TC, N, a[1005], curans;
vector<int> v[1005];
bool vis[1005];

int dfs(int x) {
	vector<int> tmp;
	vis[x] = 1;
	//printf("vis of %d set\n", x);
	for (int i = 0; i < v[x].size(); i++) if (!vis[v[x][i]]) tmp.push_back(dfs(v[x][i]));
	sort(tmp.begin(), tmp.end(), greater<int>());
	//curans = max(curans, 1);
	if (tmp.size() >= 2) curans = max(curans, tmp[0] + tmp[1] + 1);
	if (tmp.size() >= 1) curans = max(curans, tmp[0] + 1);
	if (tmp.size() >= 1) return tmp[0] + 1;
	else return 1;
}
	

int main() {
	scanf("%d", &TC);
	for (int tc = 1; tc <= TC;tc++) {
		scanf("%d",&N);
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < N; i++) scanf("%d", &a[i]);
		for (int i = 0; i < N; i++) a[i]--;
		for (int i = 0; i < N; i++) v[i].clear();
		for (int i = 0; i < N; i++) v[a[i]].push_back(i);
		int ans = 0, actans = 0, cirans = 0;
		for (int i = 0; i < N; i++) {
			if (vis[i]) continue;
			//printf("%d is accepted\n", i);
			int t = i, h = i;
			t = a[t];
			h = a[a[h]];
			while (t != h) {
				t = a[t];
				h = a[a[h]];
			}
			vector<int> v;
			v.push_back(t);
			t = a[t];
			while (t != h) {
				v.push_back(t);
				t = a[t];
			}
			cirans = max(cirans, (int)v.size());
			for (int i = 0; i < v.size(); i++) vis[v[i]] = 1;

			if (v.size() == 2) {
				for (int i = 0; i < v.size(); i++) {
					int val = dfs(v[i]);
					actans += val;
				}
			}
		}
		printf("Case #%d: %d\n", tc, max(actans, cirans));
	}
}

#include <bits/stdc++.h>

using namespace std;

int F[1111];
int vis[1111];
int ooxx[1111];
int p[1111];
bool done[1111];
vector<int> Frev[1111];

bool inb[1111];
int binary = 0;

int dfs(int x) {
	int ans = 1;
	if (vis[x]) return 0;
	vis[x] = true;
	for(auto y: Frev[x]) {
		if (inb[y]) continue;
		ans = max(ans, dfs(y) + 1);
	}
	return ans;
}

int main(void)
{
	int T = 0;
	int TK = 0;
	scanf("%d",&T);
	while (T--) {
		printf("Case #%d: ", ++TK);

		int N = 0;
		scanf("%d",&N);
		for(int i = 1;i <= N;i++) Frev[i].clear();

		for(int i = 1;i <= N;i++) {
			scanf("%d", &F[i]);
			Frev[F[i]].push_back(i);
		}

		memset(inb, 0, sizeof(inb));

		binary = 0;
		for(int i = 1;i <= N;i++) {
			if (F[F[i]] == i) {
				inb[i] = inb[F[i]] = true;
				binary++;
			}
		}

		int tot = 0;
		for(int i = 1;i <= N;i++) {
			int tans = 0;
			if (!inb[i]) continue;
			for (auto y: Frev[i]) if(!inb[y]) {
				memset(vis, 0, sizeof(vis));
				tans = max(tans, dfs(y));
			}
			tot += tans;
		}

		int ans = binary + tot;
		for(int i = 1;i <= N;i++) {
			int cur = i;
			memset(vis,0,sizeof(vis));
			int tans = 0;
			while (!vis[cur]) {
				vis[cur] = true;
				if (inb[cur]) {
					ans = max(ans, binary + tans);
					break;
				}
				tans++;
				cur = F[cur];
			}
			if (cur == i) ans = max(ans, tans);
		}
		printf("%d\n",ans);
	}
	return 0;
}

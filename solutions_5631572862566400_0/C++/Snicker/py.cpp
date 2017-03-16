#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <vector>
#include <string>
#include <map>

using namespace std;

int bff[10010];
int path[10010];
bool vis[10010];
int sz[10010];
int ans = 0;
int id[100010];
void dfs(int cur, int len) {
	vis[cur] = 1;
	path[len - 1] = cur;
	if(vis[bff[cur]]) {
		if(sz[bff[cur]] != -1) {
			return;
		}
		bool fg = 0;
		int cnt = 0;
		for(int i = 0; i < len; i++) {
			if(path[i] == bff[cur]) {
				fg = 1;
			}
			if(fg) {
				cnt++;
			}
		}
		ans = max(cnt, ans);
		fg = 0;
		for(int i = 0; i < len; i++) {
			if(path[i] == bff[cur]) {
				fg = 1;
			}
			if(fg) {
				sz[path[i]] = cnt;
				id[path[i]] = bff[cur];
			}
		}
		return ;
	}
	dfs(bff[cur], len + 1);
}


int ed[100010];
int tot[100010];
void dfs2(int cur) {
	//printf("%d fuck\n", cur);
	vis[cur] = 1;
	if(vis[bff[cur]]) {
		ed[cur] = ed[bff[cur]];
		tot[cur] = tot[bff[cur]] + 1;
		return;
	}
	if(sz[bff[cur]] != -1) {
		if(sz[bff[cur]] == 2) {
			ed[cur] = bff[cur];
			tot[cur] = 2;
		}
		return;
	}
	dfs2(bff[cur]);
	ed[cur] = ed[bff[cur]];
	if(ed[cur] != -1) {
		tot[cur] = tot[bff[cur]] + 1;	
	}
}
int val[100010];
bool fff[100010];
int main(int argc, char const *argv[])
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T = 0;
	int cas = 0;
	scanf("%d", &T);
	while(T--) {
		cas++;
		printf("Case #%d: ", cas);
		int n;
		scanf("%d", &n);
		ans = 0;
		for(int i = 1; i <= n; i++) {
			scanf("%d", &bff[i]);
		}
		memset(vis, 0, sizeof(vis));
		memset(sz, -1, sizeof(sz));
		memset(ed, -1, sizeof(ed));
		for(int i = 1; i <= n; i++) {
			if(vis[i]) {
				continue;
			}
			dfs(i, 1);
		}
		memset(vis, 0, sizeof(vis));
		for(int i = 1; i <= n; i++) {
			if(vis[i] || sz[i] != -1) {
				continue;
			}
			dfs2(i);
		}
		memset(val, 0, sizeof(val));
		memset(fff, 0, sizeof(fff));
		for(int i = 1; i <= n; i++) {
			val[i] = max(val[i], 1);
			if(ed[i] != -1) {
				val[ed[i]] = max(val[ed[i]], tot[i]);
			}
		}
		int ans2 = 0;
		for(int i = 1; i <= n; i++) {
			//printf("%d & %d\n", i, ed[i]);
			if(sz[i] == 2) {
				if(fff[i]) {
					continue;
				}
				fff[bff[i]] = fff[i] = 1;
				ans2 += val[bff[i]] + val[i];
			}
		}
		printf("%d\n", max(ans, ans2));

	}
	return 0;
}
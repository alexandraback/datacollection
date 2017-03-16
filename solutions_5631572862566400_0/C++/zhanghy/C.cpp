#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

int T,N,ans;
int a[1200];
int vis[20];
int ned[20];
int tot,b[1200];
set<int> g[1200];

void dfs(int x) {
	b[++tot] = x; vis[x] = 1;
	if (vis[a[x]]) {
		if (a[x] == b[1] || a[x] == b[tot-1]) {
				if (ans < tot) {
					ans = tot;
				}
		}
		if (a[x] == b[tot-1]) {
			for (int i = 1;i <= N; i++) {
				if (!vis[i]) dfs(i);
			}
		}
	} else {
			dfs(a[x]);
	}
	--tot; vis[x] = 0;
}

int main() {
	freopen("3.in","r",stdin);
	freopen("3.out","w",stdout);
	scanf("%d",&T);
	for (int kase = 1;kase <= T; kase++) {
		scanf("%d",&N);
		for (int i = 1;i <= N; i++)
			scanf("%d",&a[i]);
		ans = 0;
		for (int i = 1;i <= N; i++) {
			memset(vis,0,sizeof vis);
			memset(ned,0,sizeof ned);
			tot = 0;
			dfs(i);
		}
		printf("Case #%d: %d\n",kase,ans);
	}

} 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

int bff[20], best, n;
bool vis[20];

void dfs(int s, int u, int req, int ans) {
	if (u==s || !req || bff[u]==s || bff[s]==u)
		best = max(best, ans);
	vis[u] = true;
	if (req) {
		if (!vis[bff[u]])
			dfs(s, bff[u], bff[bff[u]]!=u, ans+1);
	} else {
		for (int i=1; i<=n; ++i) {
			if (!vis[i])
				dfs(s, i, bff[i]!=u, ans+1);
		}
	}
	vis[u]=false;
}

int main() {
	int T, C, d;
	scanf("%d", &T);
	for (C=1;C<=T;++C) {
		scanf("%d",&n);
		best=0;
		for (int i=1; i<=n; ++i)
			scanf("%d", bff+i);
		for (int i=1; i<=n; ++i) {
			memset(vis, 0, sizeof(vis));
			dfs(i, i, 1, 1);
		}
		printf("Case #%d: %d\n", C, best);
	}
	return 0;
}


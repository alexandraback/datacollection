#include <stdio.h>
#include <string.h>
#include <algorithm>

const int MAXN = 1005;

int n;
int a[MAXN];
bool visit[MAXN];

int dep[MAXN];
int root[MAXN];
int max_dep[MAXN];

void get_dep(int x, int d = 0) {
	if (d > 1000) {
		visit[x] = 1;
		dep[x] = -10000;
	}
	if (visit[x]) return;
	get_dep(a[x], d + 1);
	dep[x] = dep[a[x]] + 1;
	root[x] = root[a[x]];
	visit[x] = 1;
}

int solve() {
	scanf("%d", &n);
	int i;
	for (i = 1; i <= n; i++) {
		scanf("%d", a + i);
	}
	int ans = -1;
	for (i = 1; i <= n; i++) {
		memset(visit, 0, sizeof(visit));
		int cnt = 1;
		int x = i;
		visit[i] = 1;
		while (!visit[a[x]]) {
			x = a[x];
			visit[x] = 1;
			++cnt;
		}
		if (a[x] == i) ans = std::max(ans, cnt);
	}
	int tmp = 0;
	memset(visit, 0, sizeof(visit));
	memset(root, 0, sizeof(root));
	for (i = 1; i <= n; i++) {
		if (visit[i]) continue;
		if (a[a[i]] == i) {
			visit[i] = visit[a[i]] = 1;
			dep[i] = dep[a[i]] = 1;
			root[i] = i;
			root[a[i]] = a[i];
		}
	}
	for (i = 1; i <= n; i++) {
		if (!visit[i]) {
			get_dep(i);
		}
	}
	memset(max_dep, 0, sizeof(max_dep));
	for (i = 1; i <= n; i++) {
		max_dep[root[i]] = std::max(max_dep[root[i]], dep[i]);
	}
	for (i = 1; i <= n; i++) {
		if (root[i] == i) {
			tmp += max_dep[i];
		}
	}
	ans = std::max(ans, tmp);
	return ans;
}

int main() {
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		printf("Case #%d: %d\n", i, solve());
	}
}
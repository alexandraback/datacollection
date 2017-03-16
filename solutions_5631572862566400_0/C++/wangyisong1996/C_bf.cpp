#include <stdio.h>

const int MAXN = 55;

int n;
int a[MAXN];
bool visit[MAXN];

int list[MAXN];

int ans;

inline bool check(int cnt) {
	for (int i = 0; i < cnt; i++) {
		int x = list[i];
		if (a[x] != list[(i + 1) % cnt] && a[x] != list[(i + cnt - 1) % cnt]) {
			return false;
		}
	}
	return true;
}

void dfs(int cnt) {
	if (cnt > ans && check(cnt)) {
		ans = cnt;
	}
	for (int i = 1; i <= n; i++) {
		if (!visit[i]) {
			visit[i] = 1;
			list[cnt] = i;
			dfs(cnt + 1);
			visit[i] = 0;
		}
	}
}

int solve() {
	scanf("%d", &n);
	int i;
	for (i = 1; i <= n; i++) {
		scanf("%d", a + i);
	}
	ans = 0;
	dfs(0);
	return ans;
}

int main() {
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		printf("Case #%d: %d\n", i, solve());
	}
}
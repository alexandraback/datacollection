#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#define LL __uint128_t
#define LD long double
int N, J;
using namespace std;
int n;
int ans;
int t[20];
int py[20];
bool used[20];
void check(int len) {
	for (int i = 0; i < len; i++) {
		int pre = (i - 1 + len) % len;
		int nxt = (i + 1 + len) % len;
		bool fr = py[t[i]] == t[pre] || py[t[i]] == t[nxt];
		if (fr == false) return;
	}
	ans = max(ans, len);
}
void dfs(int dep) {
	check(dep);
	for (int i = 1; i <= n; i++)
		if (used[i] == false) {
			t[dep] = i;
			used[i] = true;
			dfs(dep + 1);
			used[i] = false;
		}
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int cas, cases;
	scanf("%d", &cas);
	for (cases = 1; cases <= cas; cases ++) {
		scanf("%d", &n);
		ans = 0;
		for (int i = 1; i <= n; i++)
			scanf("%d", &py[i]);
		dfs(0);
		printf("Case #%d: %d\n", cases, ans);
	}
}

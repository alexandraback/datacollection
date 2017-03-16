#include<bits/stdc++.h>

using namespace std;
#define For(i,l,r) for (int i = l; i <= r; ++i)

vector<int> from[1111];
int dfs(int x, int fa) {
	int res = 1;
	for (auto y: from[x]) if (y != fa) res = max(res, dfs(y, x) + 1);
	return res;
}

int n, go[1111], vis[1111], idx[1111];
int main() {
	int T; cin >> T;
	For(TK,1,T) {
		printf("Case #%d: ", TK);
		cin >> n;
		For(i,1,n) scanf("%d", &go[i]);
		memset(vis, 0, sizeof vis);
		int ans_circle = 0;
		For(i,1,n) if (!vis[i]) {
			int d = 0;
			idx[i] = d;
			vis[i] = i;
			int cur = i;
			while (1) {
				cur = go[cur]; ++d;
				if (vis[cur]) {
					if (vis[cur] == i) {
						if (d - idx[cur] > 2) {
							ans_circle = max(ans_circle, d - idx[cur]);
						}
					}
					break ;
				}
				vis[cur] = i; idx[cur] = d;
			}
		}
		For(i,1,n) from[i].clear();
		For(i,1,n) from[go[i]].push_back(i);
		int ans_two = 0;
		For(i,1,n) For(j,i + 1,n) if (go[i] == j && go[j] == i) {
			ans_two += dfs(i, j) + dfs(j, i);
		}
		cout << max(ans_circle, ans_two) << endl;
	}
	return 0;
}

#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N(1111);
vector<int> edges[N];
int go[N];
int dfs(int v, int fa) {
	int res(1);
	for(int i(0); i < (int)edges[v].size(); i++) {
		int y(edges[v][i]);
		if(y != fa) {
			int res1(dfs(y, v));
			res = max(res, res1 + 1);
		}
	}
	return res;
}
int main() {
	int tests;
	scanf("%d", &tests);
	for(int qq(1); qq <= tests; qq++) {
		int n;
		scanf("%d", &n);
		printf("Case #%d: ", qq);
		for(int i(1); i <= n; i++) {
			edges[i].clear();
		}
		for(int i(1); i <= n; i++) {
			scanf("%d", &go[i]);
			edges[go[i]].push_back(i);
		}
		int ans(0);
		for(int i(1); i <= n; i++) {
			if(go[go[i]] == i) {
				int a(i), b(go[i]);
				ans = ans + dfs(a, b) + dfs(b, a);
			}
		}
		ans /= 2;
		for(int i(1); i <= n; i++) {
			int ans1(1);
			int x(go[i]);
			int lim(2 * n);
			for(;;) {
				lim--;
				if(lim == 0) {
					ans1 = -1;
					break;
				}
				if(x == i) {
					break;
				}
				x = go[x];
				ans1++;
			}
			ans = max(ans, ans1);
		}
		printf("%d\n", ans);
	}
}

#include <cstdio>
#include <algorithm>
#include <cassert>
#include <cstring>
using namespace std;

const int MAXN = 10000;

int N, T;
int p[MAXN], v[MAXN], done[MAXN];
vector<int> g[MAXN], g2[MAXN];

int dfs(int i, int par) {
	int ans = 0;
	for(int j: g[i]) if(j != par)
		ans = max(ans, dfs(j, i) + 1);
	return ans;
}

void dfs2(int i) {
	if(done[i])
		return;
	done[i] = 1;
	for(int j: g2[i])
		dfs2(j);
}

int main() {
	freopen("A.in", "r", stdin);
	scanf("%d", &T);
	for(int nt = 1; nt <= T; nt++) {
		scanf("%d", &N);
		for(int i = 0; i < MAXN; i++) {
			g[i].clear();
			g2[i].clear();
		}
		memset(done, 0, sizeof(done));
		memset(v, 0, sizeof(v));
		for(int i = 1; i <= N; i++) {
			scanf("%d", &p[i]);
			g[p[i]].push_back(i);
			g2[p[i]].push_back(i);
			g2[i].push_back(p[i]);
		}

		int ans1 = 0, ans2 = 0;
		for(int i = 1; i <= N; i++) {
			if(done[i])
				continue;
			int n = i;
			vector<int> cycle;
			while(!v[n]) {
				v[n] = 1;
				cycle.push_back(n);
				n = p[n];
			}
			for(int j = 0; j < cycle.size(); j++) {
				if(cycle[j] == n) {
					cycle.erase(cycle.begin(), cycle.begin() + j);
					break;
				}
				assert(j+1 != cycle.size());
			}
			//for(int x: cycle) printf("%d ", x); puts("");
			assert(cycle.size() >= 2);
			if(cycle.size() == 2) {
				ans2 += 2 + dfs(cycle[0], cycle[1]) + dfs(cycle[1], cycle[0]);
			} else {
				ans1 = max(ans1, int(cycle.size()));
			}
			dfs2(cycle[0]);
		}

		printf("Case #%d: %d\n", nt, max(ans1, ans2));
	}
}
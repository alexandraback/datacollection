#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <stack>
#include <cassert>
using namespace std;
const int Mn = 1111;
int n;
stack<int> stk;
vector<int> adj[Mn];
int p[Mn],f[Mn];
int deg[Mn];
int find(int x) {
	return (x == p[x]) ? x : p[x] = find(p[x]);
}
inline int dfs(int x, int p, int dep) {	
	int res = dep;
	for(int i = 0; i < adj[x].size(); ++i) {
		if(adj[x][i] != p) {
			res = max(res, dfs(adj[x][i], x, dep + 1));
		}
	}
	return res;
}
inline int calc(vector<int> cur) {
	int res = 0;
	for(int i = 0; i < cur.size(); ++i) {
		res += dfs(cur[i], cur[i ^ 1], 1);
	}
	return res;
}
int main() {
	int T;
	scanf("%d", &T);
	for(int cas = 1; cas <= T; ++cas) {
		memset(deg, 0, sizeof deg);
		for(int i = 0; i < Mn; ++i)
			adj[i].clear();
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i)
			p[i] = i;
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &f[i]);
			adj[f[i]].push_back(i);
			adj[i].push_back(f[i]);
			deg[f[i]]++;
			p[find(f[i])] = find(i);
		}
		for(int i = 1; i <= n; ++i) {
			if(deg[i] == 0) {
				stk.push(i);
			}
		}
		while(!stk.empty()) {
			int sta = stk.top();
			stk.pop();
			deg[f[sta]]--;
			if(deg[f[sta]] == 0) {
				stk.push(f[sta]);
			}
		}
		int ans1 = 0;
		int ans2 = 0;
		for(int i = 1; i <= n; ++i) {
			if(find(i) == i) {
				vector<int> cur;
				for(int j = 1; j <= n; ++j) {
					if(find(j) == i && deg[j] != 0) {
						cur.push_back(j);
					} 
				}
				if(cur.size() == 2) {
					ans1 += calc(cur);
				} else if(cur.size() > 2){
					ans2 = max(ans2, (int) cur.size());
				} else {
					assert(0);
				}
			}
		}
		printf("Case #%d: %d\n",cas,max(ans1,ans2));
	}

}
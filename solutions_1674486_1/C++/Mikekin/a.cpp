#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

int tt, n, m, tmp;
bool p;
bool u[1100];
vector<int> g;
vector<int> f[1100];

void dfs(int x,int y) {
	u[x] = true;
	int z;
	for (int i = 0; i < f[x].size(); i++) {
		z = f[x][i];
		if (z == y) continue;
		if (u[z]) {
			p = true;
			return;
		} else dfs(z, x);
		if (p) return;
	}
}

int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	cin >> tt;
	for (int t = 1; t <= tt; t++) {
		cin >> n;
		p = false;
		for (int i = 1; i <= n; i++) f[i].clear();
		g.clear();
		memset(u,0,sizeof(u));
		for (int i = 1; i <= n; i++) {
			cin >> m;
			for (int j = 0; j < m; j++) {
				cin >> tmp;
				u[tmp] = true;
				f[i].push_back(tmp);
			}
		}
		for (int i = 1; i <= n; i++) {
			if (!u[i]) {
				p = true;
				g.push_back(i);
			}
		}
		printf("Case #%d: ", t);
		if (p) {
			p = false;
			for (int i = 0; i < g.size(); i++) {
				memset(u, 0, sizeof(u));
				dfs(g[i], 0);
				if (p) break;
			}
		}
		if (p) 
			printf("Yes\n");
		else 
			printf("No\n");
	}
	return 0;
}


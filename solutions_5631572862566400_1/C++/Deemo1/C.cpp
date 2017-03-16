#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

const int MAXN = 1e3 + 10;

int n, aa, bb, mx, bff[MAXN], depth[MAXN], vis[MAXN];
vector<int>	adj[MAXN];

void dfs1(int v, int de = 0){
	if (vis[v] == 2)	return;
	if (vis[v] == 1){
		aa = max(aa, de - depth[v]);
		return;
	}
	vis[v] = 1;
	depth[v] = de;
	dfs1(bff[v], de + 1);
	vis[v] = 2;
}

void dfs2(int v, int p1, int p2, int de = 0){
	mx = max(mx, de + 2);
	for (int u:adj[v])
		if (u != p1 && u != p2)	dfs2(u, p1, p2, de + 1);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int te;	cin >> te;
	for (int w = 1; w <= te; w++){
		cout << "Case #" << w << ": ";
		cin >> n;
		for (int i = 0; i < n; i++)	adj[i].clear();
		for (int i = 0; i < n; i++){
			cin >> bff[i], bff[i]--;
			adj[bff[i]].push_back(i);
		}
		aa = bb = 0;
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < n; i++)
			if (!vis[i])	dfs1(i);
		for (int i = 0; i < n; i++)
			if (bff[i] > i && bff[bff[i]] == i){
				memset(vis, 0, sizeof(vis));
				mx = 0;
				dfs2(i, i, bff[i]);
				int tmp = mx;
				mx = 0;
				memset(vis, 0, sizeof(vis));
				dfs2(bff[i], i, bff[i]);
				bb += mx + tmp - 2;
			}
		cout << max(aa, bb) << "\n";
	}
	return 0;
}

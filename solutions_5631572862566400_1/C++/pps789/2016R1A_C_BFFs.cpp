#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int NMAX = 1111;
int loves[NMAX], n;
vector<int> g[NMAX]; // back

int getCycle(int root){
	vector<bool> vis(NMAX);
	vis[root] = true;
	int ret = 1;
	int here = root;
	while (1){
		int there = loves[here];
		if (vis[there]){
			if (there == root) return ret;
			else return 0;
		}
		else{
			vis[there] = true;
			ret++;
			here = there;
		}
	}
}

int dfs(int root, int fa){
	int ret = 1;
	int d = 0;
	for (int c : g[root]){
		if (c != fa){
			d = max(d, dfs(c, root));
		}
	}
	return ret + d;
}

int main(){
	freopen("large.in", "r", stdin);
	freopen("large.out", "w", stdout);
	int T; cin >> T;
	for (int tc = 1; tc <= T; tc++){
		cout << "Case #" << tc << ": ";
		for (int i = 0; i < NMAX; i++) g[i].clear();

		cin >> n;
		for (int i = 1; i <= n; i++){
			cin >> loves[i];
			g[loves[i]].push_back(i);
		}

		int C = 0;
		for (int i = 1; i <= n; i++) C = max(C, getCycle(i));

		int D = 0;
		for (int i = 1; i <= n; i++){
			for (int j = i + 1; j <= n; j++){
				if (loves[i] == j && loves[j] == i){
					D += dfs(i, j) + dfs(j, i);
				}
			}
		}
		cout << max(1, max(C, D)) << endl;
	}
}
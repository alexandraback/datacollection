#include<iostream>
#include <vector>
using namespace std;

vector<int> G[1001];

bool vis[1001];

int dfs(int u){
	int ans = 0;
	for(int i = 0; i < G[u].size(); ++i){
		if(vis[G[u][i]]){
			return 1;
		}
		vis[G[u][i]] = 1;
		ans |= dfs(G[u][i]);
	}
	return ans;
}
int main(){
	int T, N, u, v, m;
	cin >> T;
	
	for(int i = 1; i <= T; ++i) {
		cin >> N;
		for(int j = 1; j <= N; ++j) G[j].clear();
		for(int j = 1; j <= N; j++){
			cin >> m;
			for(int k = 0; k < m; ++k) {
				cin >> v;
				G[j].push_back(v);
			}	
		}
		int ans = 0;
		for(int k = 1; k <= N; ++k) {
			for(int j = 1; j <= N; ++j) vis[j] = 0;
			if(dfs(k)) { ans = 1; break; }
		}
		
		cout << "Case #" << i << ": " << (ans ? "Yes" : "No") << endl;
	}
}

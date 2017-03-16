#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cstdlib>
using namespace std;

vector<int> G[51];
bool visited[51];
int a[51];
pair<int,int> tmp[51];
map<int, int> m; 


void dfs(int i, vector<int>& v)
{
	v.push_back(a[i]);
	visited[i] = true;

	for(int k = 0; k < (int)G[i].size(); ++k) {
		if(!visited[G[i][k]]) {
			dfs(G[i][k], v);
		}
	}
}

int main() {
	int T;
	cin >> T;
	
	for(int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": ";
		int N, M;
		cin >> N >> M;

		for(int i = 0; i < N; ++i) {
			cin >> a[i];
		}
		
		for(int i = 0; i < M; ++i) {
			int u, v;
			cin >> u >> v;
			G[v-1].push_back(u-1);
			G[u-1].push_back(v-1);
		}
		
		for(int i = 0; i < N; ++i) {
			sort(G[i].begin(), G[i].end());
		}
		
		vector<int> ans(N, 999999);
		//dfs(0, ans);
		
		for(int i = 0; i < N; ++i) {
			fill(visited, visited + N, false);
			vector<int> c;
			dfs(i, c);
			
			if(c.size() != N) continue;

			
			ans = min(ans, c);
		}
		
		for(int i = 0; i < N; ++i) {
			cout << ans[i];
		}
		cout << endl;
	}
	
	return 0;
}
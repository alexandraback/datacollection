#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;
int n, m;
string zip[50];
vector<int> g[51];
string ans;
bool comprado[51];
bool vuelta[51][51];
void dfs(int u, int ini, string cad){
	if(cad.size() == n * 5){
		ans = min(ans, cad);
		return;
	}
	for(int i = 0; i < g[u].size(); i++){
		int v = g[u][i];
		if(vuelta[u][v]){
			vuelta[u][v] = false;
			dfs(v, ini, cad);
			vuelta[u][v] = true;
		}
		if(v != ini && comprado[v] == false){
			comprado[v] = true;
			vuelta[v][u] = true;
			dfs(v, ini, cad + zip[v]);
			vuelta[v][u] = false;
			comprado[v] = false;
		}

	}
}
int main() {
	int t;
	cin >> t;
	for(int caso = 1; caso <= t; caso++){
		cin >> n >> m;
		for(int i = 0; i < n; i++){
			cin >> zip[i];
			g[i].clear();
		}
		int u, v;
		for(int i = 0; i < m; i++){
			cin >> u >> v;
			u--, v--;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		ans = string(n * 5, '9');
		for(int i = 0; i < n; i++){
			memset(comprado, false, sizeof(comprado));
			memset(vuelta, false, sizeof(vuelta));
			dfs(i, i, zip[i]);
		}
		printf("Case #%d: %s\n", caso, ans.data());
	}
	return 0;
}
/*
4
3 2
10001
20000
10000
1 2
2 3
5 4
36642
28444
50012
29651
10953
1 4
2 3
2 5
4 5
5 5
36642
28444
50012
29651
10953
1 2
1 4
2 3
2 5
4 5
6 6
10001
10002
10003
10004
10005
10006
1 2
1 6
2 3
2 4
3 5
4 5

*/


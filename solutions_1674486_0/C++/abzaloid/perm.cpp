#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <cctype>

using namespace std;

int n, m, t;
vector <vector<int> > g;
vector <bool> b(1055, false);
bool ok = false;

void dfs(int v){
	b[v] = true;
	for (int i = 0; i < g[v].size(); i++)
		if (!b[g[v][i]]) dfs(g[v][i]); else if (b[g[v][i]]){
			ok = true;
			return;				
		}
};

int main(){
freopen("input.txt", "rt", stdin);
freopen("output.txt", "wt", stdout);
	cin >> t;
	for (int i = 0; i < t; i++){
	g.clear();
		cin >> n;
	g.resize(n);
		for (int j = 0; j < n; j++){
			cin >> m;
			for (int k = 0; k < m; k++){
				int x;				
				cin >> x;			
				g[j].push_back(--x);
			}	
		}	
	for (int u = 0; u < n; u++){
		for (int k = 0; k < n; k++) b[k] = false;
		b[u] = true;		
		ok = false;
		for (int k = 0; k < g[u].size(); k++){	
			if (b[g[u][k]]) ok = true; else	dfs(g[u][k]);
			if (ok) {
				break;			
			}	
		} 
		if (ok) break;
	}
	if (ok) printf("Case #%d: Yes\n", i + 1); else printf("Case #%d: No\n", i + 1);
	}
	return 0;
}

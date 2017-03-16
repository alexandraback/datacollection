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

int nclas, inherit, test;
vector <vector<int> > tmp1;
vector <bool> b(1055, false);
bool done = false;

void dfs(int v){
	b[v] = true;
	for (int i = 0; i < tmp1[v].size(); i++)
		if (!b[tmp1[v][i]]) dfs(tmp1[v][i]); else if (b[tmp1[v][i]]){
			done = true;
			return;				
		}
};

int main(){
	cin >> test;
	for (int i = 0; i < test; i++){
	tmp1.clear();
		cin >> nclas;
	tmp1.resize(nclas);
		for (int j = 0; j < nclas; j++){
			cin >> inherit;
			for (int k = 0; k < inherit; k++){
				int x;				
				cin >> x;			
				tmp1[j].push_back(--x);
			}	
		}	
	for (int u = 0; u < nclas; u++){
		for (int k = 0; k < nclas; k++) b[k] = false;
		b[u] = true;		
		done = false;
		for (int k = 0; k < tmp1[u].size(); k++){	
			if (b[tmp1[u][k]]) done = true; else	dfs(tmp1[u][k]);
			if (done) {
				break;			
			}	
		} 
		if (done) break;
	}
	if (done) printf("Case #%d: Yes\n", i + 1); else printf("Case #%d: No\n", i + 1);
	}
	return 0;
}
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int main() {
	int ntc;
	scanf("%d", &ntc);
	
	int tc;
	for (tc = 1; tc <= ntc; ++tc) {
		int n;
		scanf("%d", &n);
		
		vector<vector<int> > adj(n);
		vector<set<int> > parents(n); 
		queue<int> q;
		int bapak[n], terBapaki[n];
		
		for (int i = 0; i < n; ++i) {
			int nNode;
			scanf("%d", &nNode);
			
			// induk tak berbapak
			if (nNode == 0) {
				q.push(i);
			}
			
			bapak[i] = nNode;
			terBapaki[i] = 0;
			
			for (int j = 0; j < nNode; ++j) {
				int node;
				scanf("%d", &node);
				
				adj[node - 1].push_back(i);
			}
		}
		
		bool ketemu = false;
		
		// bfs
		while (!q.empty() && !ketemu) {
			int curNode = q.front();
			q.pop();
			
			set<int> curParents = parents[curNode];
			
			// untuk tiap anak
			for (int i = 0, m = adj[curNode].size(); i < m; ++i) {
				int newNode = adj[curNode][i];
				set<int> newParents = parents[newNode];
				
				//printf("%d %d\n", curNode, newNode);
				
				// coba masukin tiap value parent nya
				for (set<int>::iterator it = curParents.begin(); it != curParents.end(); ++it) {
					int value = *it;
					
					// masukin parent dari parent
					pair<set<int>::iterator,bool> ret = newParents.insert(value);
					
					// wuhu ketemu duplikat
					if (ret.second == false) {
						ketemu = true;
						
						break;
					}
				}
				
				pair<set<int>::iterator,bool> ret = newParents.insert(curNode);
				
				// wuhu ketemu duplikat
				if (ret.second == false) {
					ketemu = true;
					
					break;
				}
				
				parents[newNode] = newParents;
				terBapaki[newNode]++;
				
				// kalau bapaknya yang ngetraverse dah semua, baru boleh traverse
				if (bapak[newNode] == terBapaki[newNode]) {
					q.push(newNode);
				}
			}
		}
		
		if (!ketemu) {
			printf("Case #%d: No\n", tc);
		} else {
			printf("Case #%d: Yes\n", tc);
		}
	}
	
	return 0;
}

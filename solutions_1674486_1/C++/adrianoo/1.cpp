#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

int t, n, tt, l, a;
vector<int> graf[1010];
vector<int> starts, topo;
bool solved[1010];
bool res;
int paths[1010];

void dfs (int v) {
	solved[v] = true;
	for (int i=0; i<graf[v].size(); i++)
		if (!solved[graf[v][i]])
			dfs(graf[v][i]);
	topo.push_back(v);
}

int main () {
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i=1; i<=n; i++) {
			cin >> l;
			for (int j=0; j<l; j++) {
				cin >> a;
				graf[a].push_back(i);
			}
			if (l == 0)
				starts.push_back(i);
		}
		res = false;
		for (int i=0; i<starts.size(); i++)
			dfs(starts[i]);
		reverse(topo.begin(), topo.end());
		for (int q=0; q<starts.size(); q++) {
			for (int i=0; i<=n; i++)
				paths[i] = 0;
			paths[starts[q]] = 1;
			//cout << "ergfdg\n";
			for (int i=0; i<topo.size(); i++) {
				//cout << i << " " << topo[i] << " " << graf[topo[i]].size() << endl;
				for (int j=0; j<graf[topo[i]].size(); j++) {
				//	cout << "  " << graf[topo[i]][j] << endl;
					paths[graf[topo[i]][j]] += paths[topo[i]];
					if (paths[graf[topo[i]][j]] > 1) {
				//		cout << "hehe\n";
						i = 23435345;
						res = true;
						break;
					}
				}
			}
			for (int i=0; i<topo.size(); i++) {
				if (paths[topo[i]] > 1)
					res = true;
			}
			
		}
		cout << "Case #" << ++tt << ": " << (res?"Yes":"No") << endl;
		for (int i=1; i<=n; i++) {
			graf[i].clear();
			solved[i] = false;
			paths[i] = 0;
		}
		topo.clear();
		starts.clear();
	}
}


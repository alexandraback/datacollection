#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

const int M=1005;
const int N=1005;

bool adjmat[M][N], seen[N]; int matchL[M], matchR[N], m, n;
bool bpm(int u) { // Can we find augmenting path starting from u
  for(int v = 0; v < n; v++) if(adjmat[u][v] && !seen[v]) { seen[v] = true;
    if(matchR[v] == -1 || bpm(matchR[v]) ) { matchL[u] = v, matchR[v] = u;
      return true; } }
  return false; }
int main3() { memset(matchL,-1,sizeof matchL); memset(matchR,-1,sizeof matchR);
  // Read input, set m (left part), n (right part), and populate adjmat here
		map<string, int> map1;
		map<string, int> map2;
		int nrow; cin >> nrow;
		vector<string> lst1, lst2;

		memset(adjmat, 0, sizeof(adjmat));
		for (int i = 0; i < nrow; i++) {
			string s1, s2; cin >> s1 >> s2;
			lst1.push_back(s1); lst2.push_back(s2);
			if (map1.count(s1) == 0) {
				map1[s1] = map1.size()-1;
			}
			if (map2.count(s2) == 0) {
				map2[s2] = map2.size()-1;
			}
		}
		if (map1.size() > map2.size()) {
			map<string, int> tmp = map1;
			map1 = map2;
			map2 = tmp;
			vector<string> tmp2 = lst1;
			lst1 = lst2;
			lst2 = tmp2;
		}
		m=map1.size();
		n=map2.size();
		for (int i = 0; i < nrow; i++) {
			adjmat[map1[lst1[i]]][map2[lst2[i]]] = true;
			//cerr << "edge: " << map1[lst1[i]] << " " << map2[lst2[i]] << endl;
		}
  int cnt = 0;
  for(int i = 0; i < m; i++) {
    memset(seen, 0, sizeof seen);
    if( bpm(i) ) cnt++; // matchL[i] is the match
  }
return nrow - (m+n-cnt);
}

int main(){
	int nc; cin >> nc;
	for (int cs = 1; cs <= nc; cs++) {
		cout << "Case #" << cs << ": " << main3() << endl;
	}
}

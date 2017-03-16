#include <stdio.h>
#include <string>

#include <stdio.h>
#include <string.h>

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<int> adj[1122];
int M[100]; // matched people with y[i];
int V[100]; // visit check
int c;

bool dfs(int v) {
  if(V[v]==c) return false;
  V[v]=c;

  for(int i=0;i < adj[v].size();i++) {
    int t = adj[v][i];
    if(M[t]==-1 || (v!=M[t] && dfs(M[t])) ) { M[t]=v; return true; }
  }
  return false;
}

//int main(void) {
//	int n=1;
//	int res=0;
//
//
//	for(c=0;c<n;c++) if(dfs(c)) res++;
//
//	//for(int i=0;i<n;i++) printf("%d %d\n", i, M[i]);
//
//	return res;
//
//}

using namespace std;

int main(void) {
	freopen("C-small-attempt0 (1).in", "r", stdin);
	freopen("C-small.out.txt", "w", stdout);
	int T; scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		memset(V, -1, sizeof(V));
		memset(M, -1, sizeof(M));
		map<string, int> ma, mb;

		for (int i = 0; i < 1111; i++) adj[i].clear();
		int N; scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			char a[33], b[33]; scanf("%s %s", a, b);
			int ma_size = ma.size();
			if (!ma.count(a)) ma[a] = ma_size;
			int mb_size = mb.size();
			if (!mb.count(b)) mb[b] = mb_size;
			int a_idx = ma[a];
			int b_idx = mb[b];
			adj[a_idx].push_back(b_idx);
 		}
		int n = max(ma.size(), mb.size());
		int match = 0;
		for(c=0;c<n;c++) if(dfs(c)) match++;
		int res = N - ((int)ma.size() + (int)mb.size() - match);
		
		printf("Case #%d: %d\n", tc, max(0, res));
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
// bipartite matching
vector<int> adj[1005];
bool seen[1005];
int who[1005];
bool dfs(int x){
	if (seen[x]) return false;
	seen[x] = true;
	for (int y : adj[x]) if (who[y] != x) {
		if (who[y] == -1 || dfs(who[y])) {
			who[y] = x;
			return true;
		}
	}
	return false;
}
int main(){
	int T; cin >> T;
	for (int tc=1;tc<=T;tc++){
		fill(adj, adj+1005, vector<int>());
		int n; cin >> n;
		vector<string> aa (n), bb (n);
		for (int i=0;i<n;i++) cin >> aa[i] >> bb[i];
		set<string>sa(aa.begin(),aa.end());
		vector<string>va(sa.begin(),sa.end());
		set<string>sb(bb.begin(),bb.end());
		vector<string>vb(sb.begin(),sb.end());
		for (int i=0;i<n;i++){
			adj[lower_bound(va.begin(),va.end(),aa[i])-va.begin()].push_back(lower_bound(vb.begin(),vb.end(),bb[i])-vb.begin());
		}
		int sz=0;
		memset(who,-1,sizeof who);
		for (int x=0;x<(int)va.size();x++){memset(seen,0,sizeof seen);if(dfs(x))sz++;}
		printf("Case #%d: %d\n", tc, n - ((int)va.size() + (int)vb.size() - sz));
	}
}

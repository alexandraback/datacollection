#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;
typedef vector<bool> vb;

int to[1003];
int ind[1003];
int vis[1003];
vi g[1003];


int dfs(int cur, int pro){
	vis[cur] = 1;
	int mx = 1;
	for(int i = 0; i < g[cur].size(); i++){
		if(!vis[g[cur][i]] and g[cur][i] != pro){
			mx = max(mx, dfs(g[cur][i], pro) + 1);
		}
	}
	return mx;
}

int dfscicle(int cur, int start){
	vis[cur] = 1;
	if(to[cur] == start){
		return 1;
	}else if(!vis[to[cur]]){
		int ret = dfscicle(to[cur], start);
		if(ret){
			return ret + 1;
		}else{
			return 0;
		}
	}else{
		return 0;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++){
		int n;
		cin >> n;
		memset(ind, 0, sizeof ind);
		memset(to, 0, sizeof to);
		memset(vis, 0, sizeof to);
		for(int i = 0; i < 1001; i++){
			g[i].clear();
		}

		for(int i = 1; i <= n; i++){
			int aux;
			cin >> aux;
			ind[aux]++;
			to[i] = aux;
			g[aux].pb(i);
		}
	
		int ans = 0;

		for(int i = 1; i <= n; i++){
			memset(vis, 0, sizeof vis);
			ans = max(ans, dfscicle(i, i));
		}
		set<ii> s;	
		for(int i = 1; i <= n; i++){
			int aux = to[i];
			if(to[aux] == i)
				s.insert(mp(min(i, to[i]), max(i, to[i])));
		}
		
		
		int ans2 = 0;
		for(auto i : s){
			int idx1 = i.fi;
			int idx2 = i.se;
			memset(vis, 0, sizeof vis);
			ans2 += dfs(idx1, idx2);
			memset(vis, 0, sizeof vis);
			ans2 += dfs(idx2, idx1);
		}

		cout << "Case #" << t << ": " << max(ans,ans2) << endl;
	}	
	
	return 0;
}

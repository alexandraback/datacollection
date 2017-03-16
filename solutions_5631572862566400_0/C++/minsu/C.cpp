#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;

int T,N,a,dc, ans;
int par[1010], son[1010], dep[1010], vis[1010];
vector<ii> ps;
vector<int> vs, ds;

void dfs(int i){
	vis[i] = dc;
	ds.push_back( i );
	if( !vis[ par[i] ] ) dfs( par[i] );
	else if( vis[ par[i] ] == dc ){
		int scc = 1;
		while( !ds.empty() && ds.back() != par[i] ){
			ds.pop_back();
			scc++;
		}
		if( ds.empty() ) assert(0);
		ans = max(ans, scc);
	}
	vs.push_back(i);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin>>T;	
	for(int t=1; t<=T; t++){
		cin>>N;
		dc = ans = 0;
		vector<ii>().swap(ps);
		vector<int>().swap(vs);
		
		for(int i=0; i<N; i++){
			cin>>par[i]; par[i]--;
			son[ par[i] ] = i;
		}
		memset( vis, 0, sizeof vis );
		for(int i=0; i<N; i++){
			if( !vis[i] && i == par[par[i]] ){
				vis[ i ] = vis[ par[i] ] = -1;
				ps.push_back( ii( i, par[i] ) );
			}
		}
		memset( dep, 0, sizeof dep );

		for(int i=0; i<N; i++){
			vector<int>().swap(ds);
			if( !vis[i] ){
				dc++;
				dfs(i);
			}
		}
		reverse( vs.begin(), vs.end() );
		for(auto it : vs ){
			dep[ par[it] ] = max( dep[par[it]], dep[it]+1 );
		}
		int aa = 0;
		for(auto it : ps ){
			aa += 2 + dep[it.first] + dep[it.second] ;
		}
		ans = max( ans, aa );
		cout<<"Case #"<<t<<": "<<ans<<"\n";
	}
	return 0;
}

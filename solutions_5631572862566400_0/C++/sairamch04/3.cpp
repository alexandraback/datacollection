#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long
#define endl "\n"
#define mp make_pair
#define pb push_back
vector<int> adj[1010];
vector<int> revAdj[1010];
bool visited[1010];
int R[1010];
//int rev[1010];
int presRoot;
int dfs(int root,int rank){
	visited[root]=true;
	R[root]=rank;
	int ans;
	for(int i=0;i<adj[root].size();i++){
		if(!visited[adj[root][i]]){
			ans=  dfs(adj[root][i],rank+1);
			visited[root] = false;
			return ans;

		}
		else{
			
			ans=0;

			if(rank - R[adj[root][i]] == 1){
				for(int i=0 ; i< revAdj[presRoot].size(); i++){
					if(!visited[revAdj[presRoot][i]]){
						ans++;
						break;
					}
				}


				if( revAdj[root].size() > 1){

					ans +=  rank+1;
					
				}
				else{
					ans += rank;
				}
								
				
			}
			else{
				ans =rank-R[adj[root][i]]+1;
			}
			visited[root]=false;
			return ans;
		}
	}
	return 0;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T,cnt,tmp;
	cin >> T;
	 cnt=1;
	 int N;
	while(T--){
		cout << "Case #" << cnt++ << ": ";
		cin >> N;
		for(int i=0;i<N;i++){
			cin >> tmp;
			tmp--;
			adj[i].pb(tmp);
			revAdj[tmp].pb(i);
		}
		int ans=0;
		for(int i = 0;i< N;i++){
			if(!visited[i]){
				presRoot = i;
				ans = max(ans, dfs(i,1));
			}
		}
		for(int i = 0;i<N ;i++){
			adj[i].clear();
			revAdj[i].clear();
		}
		cout << ans << endl;




	}
	return 0;
}
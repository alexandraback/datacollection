#include<bits/stdc++.h>
#define M 1000
using namespace std;
map < string , int > mp0 , mp1;
int n0 , n1 , n , match[M + 5];
vector < int > adj[M + 5];
bool visited[M + 5];
int dfs(int u){
	if(visited[u])	return 0;
	visited[u] = true;
	for(int i = 0 ; i < adj[u].size() ; i++){
		int x = adj[u][i];
		if(match[x] == 0){
			match[x] = u;
			return 1;
		}
		if(dfs(match[x]) == 1){
			match[x] = u;
			return 1;
		}
	}
	return 0;
}
void solve(){
	cin>>n;
	for(int i = 1 ; i <= M ; i++) while(!adj[i].empty())	adj[i].pop_back();
	memset(match , 0 , sizeof match);
	n0 = 0 ; n1 = 0;
	mp0.clear(); mp1.clear();
	for(int i = 1 ; i <= n ; i++){
		string x , y;
		cin>>x>>y;
		if(mp0.find(x) == mp0.end()){
			n0++; mp0[x] = n0;
		}
		if(mp1.find(y) == mp1.end()){
			n1++ ; mp1[y] = n1;
		}
		int xx = mp0[x]; int yy = mp1[y];
		adj[xx].push_back(yy);
	}
	int ans = 0;
	for(int i = 1 ; i <= n0 ; i++) {
		memset(visited , 0 , sizeof visited); ans += dfs(i);
	}
	printf("%d\n",n - (n0 + n1 - ans));
}
main(){
	freopen("test.inp","r",stdin);
	freopen("output.txt","w",stdout);
	int tc;
	scanf("%d",&tc);
	for(int i = 1 ; i <= tc ; i++){
		printf("Case #%d: ",i);
		solve();
	}
}

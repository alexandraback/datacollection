#include<bits/stdc++.h>
#define M 1000
using namespace std;
int p[M + 5] , ck[M + 5] , n , vis[M + 5] , c;
vector < int > adj[M + 5];
void dfs(int u,int h){
	c = max(c , h);
	for(int i = 0 ; i < adj[u].size() ; i++){
		int v = adj[u][i];
		if(p[u] == v)	continue;
		dfs(v , h + 1);
	}
}
main(){
	freopen("test.inp","r",stdin);
	freopen("test.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int tc = 1 ; tc <= T ; tc++){
		scanf("%d",&n);
		memset(ck , 0 , sizeof ck); memset(vis , 0 , sizeof vis);
		for(int i = 1 ; i <= n ; i++) while(!adj[i].empty())	adj[i].pop_back();
		for(int i = 1 ; i <= n ; i++){
			scanf("%d",&p[i]);
			adj[p[i]].push_back(i);
		}
		int ans = 0 , ret = 0;
		for(int i = 1 ; i <= n ; i++){
			int start = i , tot = 0;
			while(true){
				if(ck[start] == i){
					if(start == i)	ans = max(ans , tot);
					break;
				}
				ck[start] = i; start = p[start];
				tot++;
			}
		}
		for(int i = 1 ; i <= n ; i++){		
			int x = p[i] , y = p[x];
			if(y != i)	continue;
			if(vis[x] || vis[y])	continue;
			vis[x] = true ; vis[y] = true;
			int tmp = 0;
			c = 0 ; dfs(x , 0) ;  tmp += c;
			c = 0 ; dfs(y , 0) ;  tmp += c;
			ret += (tmp + 2);
		}
		printf("Case #%d: %d\n",tc,max(ans , ret));
	}	
}

#include<stdio.h>
#include<vector>
using namespace std;
vector<int> g[10000];
int n;
int ch[10000];
int res = 0 ;
int dfs(int k){
	ch[k] = 1;
	for(int i = 0 ; i < g[k].size() ; i++ ){
		if( ch[ g[k][i] ] == 0 ){
			dfs( g[k][i] );
		}else{
			res = 1;
		}
	}
}
int main(){
	int t;
	scanf("%d",&t);
	for(int e = 0 ; e < t ; e++ ){
		scanf("%d",&n);
		for(int i = 0 ; i < n; i++ ){
			int m;
			scanf("%d",&m);
			g[i].clear();
			int y;
			for(int j = 0 ; j < m ; j++ ){
				scanf("%d",&y);
				y--;
				g[i].push_back(y);
			}
		}
		printf("Case #%d: ",e+1);
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < n ; j++ ) ch[j] = 0;
			res = 0;
			dfs(i);
			//printf("%d\n",res);
			if( res ){
				printf("Yes\n");
				break;
			}
		}
		if( !res ){
			printf("No\n");
		}
	}
}

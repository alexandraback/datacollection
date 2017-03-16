#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#define MAXN 1200
#define pb push_back

using namespace std;
int n;
int ar[MAXN];
int G[MAXN];
int used[MAXN];
int res;
int first;
vector <int> T[MAXN];
int f(int x){
	int ret = 1;
	used[x] = 1;
	for(int i = 0 ;i < T[x].size(); i++){
		if(!used[T[x][i]]){
			ret = max(ret, 1 + f(T[x][i]));
		}
	}
	return ret;
}
void dfs(int x,int cnt){
	used[x] = 1;
	if(used[G[x]]){	
		if(first == G[x]){
			res = max(res,cnt);
		}
	}
	else{
		dfs(G[x],cnt+1);
	}
}
int main(){
	int Test=1,tt;
	scanf(" %d",&Test);
	for(tt=1;tt<=Test;tt++){
		res = 2;
		printf("Case #%d: ",tt);
		scanf(" %d",&n);
		for(int i = 1 ; i <= n ; i++) T[i].clear();
		for(int i = 1 ; i <= n ; i++){
			int x;
			scanf(" %d",&x);
			G[i] = x;
			T[x].pb(i);
		}
		for(int i = 1 ; i <= n ;i++){
			for(int j = 1 ; j <= n ; j++) used[j] = 0;
			first = i;
			dfs(i,1);
		}
		for(int i = 1 ; i <= n ; i++) used[i] = 0;
		int sum = 0;
		for(int i = 1 ; i <= n ; i++){
			if(!used[i] && G[G[i]] == i){
				used[G[i]] = 1;
				used[i] = 1;
				sum += f(i)+f(G[i]) ;
			}
		}
		res = max(res,sum);
		printf("%d\n",res);
	}
	return 0;
}
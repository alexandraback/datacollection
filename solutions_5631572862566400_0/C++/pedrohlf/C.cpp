#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <stdlib.h>
#include <set>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <stack>
#include <sstream>
#include <list>
#include <bitset>
#define ff first
#define ss second

using namespace std;

typedef long long ll;

int f[1005],ans,n, vis[1005],first;

int dfs(int a, int pai, int cont){
	vis[a] = 1;
	
	if(vis[f[a]]){
		if(pai == f[a]){
			ans = max(cont,ans);
			for(int i = 1; i <= n; i++){
				if(vis[i]) continue;
				dfs(i,a,cont+1);
			}
		}
		else if(f[a] == first){
			ans = max(cont,ans);
		}
	}
	else{
		dfs(f[a],a,cont+1);
	}
	vis[a] = 0;
}

int main() {
	int t,tc=1,x,i;

	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(i = 1; i <= n; i++){
			scanf("%d", &f[i]);
		}
		ans = 0;
		for(i = 1; i <= n; i++){
			memset(vis,0,sizeof(vis));
			first = i;
			int x = dfs(i,i,1);
		}
		printf("Case #%d: %d\n", tc++, ans);
	}

	return 0;
}

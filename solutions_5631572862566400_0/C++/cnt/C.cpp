#include <bits/stdc++.h>

using namespace std;
const int N = 1005;

int n,b[N],res,L,cnt;
bool vis[N];
set <int> st[N];
int exist;

void dfs(int u){
	if(vis[u]) return;
	vis[u] = 1;
	exist += 2 - st[u].size();
	for(set <int> :: iterator it = st[u].begin(); it != st[u].end(); it++){
		dfs(*it);
	}
}

void init(){
	int T;
	scanf("%d",&T);
	for(int t=1; t<=T; t++){
		res = 0;
		scanf("%d",&n);
		for(int i = 0; i < n; i++){
			scanf("%d",&b[i]);
		}
		L = 1 << n;
		for(int i = 0; i < L; i++){
			bool bol = 1;
			for(int j = 0; j < n; j++){
				st[j].clear();
			}
			for(int j = 0; j < n; j++){
				if((i >> j) & 1){
					if((i >> (b[j] - 1)) & 1){
						st[j].insert(b[j] - 1);
						st[b[j] - 1].insert(j);
					}
					else bol = 0;
				}
			}
			if(!bol) continue;
			for(int j = 0; j < n; j++){
				if((i >> j) & 1){
					if(st[j].size() > 2) bol = 0;
				}
			}
			if(!bol) continue;
			memset(vis,0,sizeof(vis));
			cnt = 0;
			for(int j = 0; j < n; j++){
				if(((i >> j) & 1) and !vis[j]){
					cnt++;
					exist = 0;
					dfs(j);
					if(exist < 2) bol = 0;
				}
			}
			if(bol or (cnt == 1)) res = max(res,__builtin_popcount(i));
		}
		printf("Case #%d: %d\n",t,res);
	}
}

void fread(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

int main(){
	fread();
	init();
	return 0;
}
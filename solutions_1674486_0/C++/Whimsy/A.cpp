#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

bool G[1100][1100];
bool vis[1100];
int num[1100];

int node,edge,n,tmp,tot,Test;

void dfs(int u){
	vis[u] = 1;
	++node;
	edge += num[u];
	for (int v = 1;v<=1100;++v)
	if (vis[v] == 0 && G[u][v] == 1){
		dfs(v);
	}
}

void work(){
	cin >> n;
	for (int i = 1;i<=n;++i) 
	for (int j = 1;j<=n;++j){
		G[i][j] = 0;
	
	}
	for (int i = 1;i<=n;++i) vis[i] = 0;
	for (int i = 1;i<=n;++i){
		cin >> tot;
		num[i] = tot;
		for (int j = 1;j<=tot;++j){
			cin >> tmp;
			G[i][tmp] = 1;
			G[tmp][i] = 1;
		}
	}
	for (int i = 1;i<=n;++i)
	if (vis[i] == 0){
		node = 0; edge = 0;
		dfs(i);
		if (edge > node-1) {
			printf("Yes\n");
			return;
		}
	}
	printf("No\n");

}

int main(){
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	cin >> Test;
	for (int ii = 1;ii<=Test;++ii){
		printf("Case #%d: ",ii);
		work();
	}
	return 0;
}

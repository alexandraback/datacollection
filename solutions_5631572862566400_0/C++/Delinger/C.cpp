#include <bits/stdc++.h>

using namespace std;


vector <int> dfs_num, dfs_low, S, visited;
int numSCC=0;
int dfsNumberCounter=0;
vector <int> AdjList[1001];
vector <int> SCCadj[1001];
int degree[1001];
int n,k;
vector <int> cual,tam;
vector <int> disponible;
bool ya[1001];
int memo[1001];
bool mark[1001];
vector <int> reverso[1001];
bool adj[1001][1001];

void SCC(int u){
	dfs_low[u]= dfs_num[u] = dfsNumberCounter++;
	S.push_back(u);
	visited[u]=1;
	for (int j=0; j < AdjList[u].size();++j){
		int v= AdjList[u][j];
		if (dfs_num[v] == -1) {
			SCC(v);	
		}
		
		if (visited[v]){
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}
	}
	
	if (dfs_low[u] == dfs_num[u]){
		numSCC++;
		while(1){
			int v= S.back(); S.pop_back(); visited[v]=0;
			cual[v] = numSCC-1;
			tam[numSCC-1]++;
			if (u==v) break;
		}
	}
}

int DFS (int x, int root,bool inv){

	mark[x]=true;
	vector <int> v;
	int cant=0;
	

	for (int i=0;i<AdjList[x].size();++i){

		int y = AdjList[x][i];

		if (mark[y]) continue;
		
		if (degree[y]==2) return 0;
		degree[y]++;
		degree[x]++;
		cant = DFS(y,root,inv);
	}
	
	if (!inv){
		for (int i=0;i<reverso[x].size();++i){
			int y = reverso[x][i];
			if (mark[y]) continue; 
			
			cant = max(cant,DFS(y,root,true));
		}
	}

	return 1+cant;
	
	
}

int main(){
	
	int t;
	scanf("%d",&t);
	int casos=1;
	while (t--){
	printf("Case #%d: ",casos++);
	scanf("%d",&n);
	for (int i=0;i<n;++i){
		AdjList[i].clear();
		SCCadj[i].clear();
		reverso[i].clear();
	}
	for (int i=0;i<n;++i){
		int cual; scanf("%d",&cual);
		AdjList[i].push_back(cual-1);
		reverso[cual-1].push_back(i);
	}
	memset(mark,0,sizeof(mark));
	memset(adj,0,sizeof(adj));
	dfs_num.assign(n,-1); dfs_low.assign(n,0); visited.assign(n,0);
	cual.assign(n,0); tam.assign(n,0);
	memset(ya,0,sizeof(ya));
	memset(degree,0,sizeof(degree));
	dfsNumberCounter = numSCC = 0;
	

	
	int maximo=0;
	for (int i=0;i<n;++i){
		memset(mark,0,sizeof(mark));
		maximo=max(DFS(i,i,false),maximo);
	}
	
	printf("%d\n",maximo);
	
	}
	return 0;	
}

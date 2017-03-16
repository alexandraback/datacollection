#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
const int MAXN = 1010;
vector<int>  edge[MAXN];
int visit[MAXN];
bool ans ;
int d[MAXN];
int n;
int col ;
void dfs(int cur){
	if(visit[cur]==col){
		ans = true;
		return ;
	}
	visit[cur] = col;
	for(int i = 0;i<edge[cur].size() && !ans;i++){
		dfs(edge[cur][i]);
	}
}
int main(){
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	int t;
	scanf("%d",&t);
	int casenum = 0;
	while(t--){
		ans = 0;
		scanf("%d",&n);
		for(int i = 0;i<=n;i++)edge[i].clear();
			memset(visit,false,sizeof(visit));
			col = 1;
		memset(d,0,sizeof(d));
		int u,v,num;
		for(int i = 1;i<=n;i++){
			scanf("%d",&num);
			for(int j = 0;j<num;j++){
				scanf("%d",&v);
				edge[i].push_back(v);
				d[v]++;
			}
		}
		for(int i = 1;!ans && i<=n;i++)if(d[i]==0){
			dfs(i);
			col++;
		}
		printf("Case #%d: %s\n",++casenum,ans?"Yes":"No");
	}
	return 0;
}
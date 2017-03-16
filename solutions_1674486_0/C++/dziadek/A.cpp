#include<cstdio>
#include<vector>
#define MAX 1005
using namespace std;

int t,n,m,a,i,j,k;
vector<int> graph[MAX];
bool vis[MAX],f;

void DFS(int x){
    vis[x]=true;
    
    for(int i=0; i<graph[x].size(); ++i)
	if(!vis[graph[x][i]]) DFS(graph[x][i]);
	else
	    f=true;
}

int main(){
    scanf("%d",&t);
    for(i=0; i<t; ++i){
	printf("Case #%d: ",i+1);
	scanf("%d",&n);
	
	for(j=1; j<=n; ++j){
	    graph[j].clear();
	    scanf("%d",&m);
	    for(k=0; k<m; ++k){
		scanf("%d",&a);
		graph[j].push_back(a);
	    }
	}
	
	f=false;
	for(j=1; j<=n; ++j){
	    for(k=1; k<=n; ++k) vis[k]=false;
	    DFS(j);
	    if(f){
		printf("Yes\n");
		break;
	    }
	}
	
	if(!f) printf("No\n");
    }
}
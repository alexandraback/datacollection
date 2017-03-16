#include<stdio.h>
#include<vector>
using namespace std;

int M[1005];
vector<int> Y[1005];
int vis[1005];

int flag;

int dfs(int k){
	//printf("visitando %d\n", k);
	vis[k]=1;
	for(int i=0; i<Y[k].size(); i++){
		if(vis[Y[k][i]]==1){
			//printf("vizinho do %d eh %d e cabou!\n", k, Y[k][i]);
			flag=1;		
		}
		else
			dfs(Y[k][i]);
	}
	return 0;
}

int main(){
	int T, N;
	scanf("%d ", &T);
	for(int g=0; g<T; g++){
		scanf("%d ", &N);
		for(int r=0; r<N; r++){
			scanf("%d ", &M[r]);
			Y[r].clear();
			for(int e=0; e<M[r]; e++){
				int a;
				scanf("%d ", &a);
				Y[r].push_back(a-1);
			}	
		}
	
	printf("Case #%d: ", g+1);
	int cc=0;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			vis[j]=0;
		}	
		flag=0;
		//printf("Chamando dfs no %d\n", i);	
		dfs(i);
		if(flag==1) break;
	}			
	
	if(flag==1) printf("Yes\n");
	else printf("No\n");
}
	return 0;
}

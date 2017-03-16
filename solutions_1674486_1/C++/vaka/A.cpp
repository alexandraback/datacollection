#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<set>
#include<vector>

using namespace std;

int N,adj[1005][15];

set<int> unV;
vector<set<int> > Ex;
set<int>::iterator it;
bool flag = false;

void dfs(int n){
	int i,j,k,z,x;
	//printf("Visited: %d\n",n);
	unV.erase (unV.find(n));
	for(i=1;!flag && i<=adj[n][0];i++){
		z = adj[n][i];
		if(unV.find(z) != unV.end())dfs(z);
		for(it=(Ex[z]).begin(); it!=(Ex[z]).end(); it++){
			x = *it;
			//printf("	%d\n",x);
			if((Ex[n]).find(x) != (Ex[n]).end()){
				flag = true;
				break;
			}else{
				(Ex[n]).insert(x);
			}
		}
	}
}


void solve(){
	int i,j,k;
	Ex.clear();
	unV.clear();
	flag = false;
	set<int> S;
	Ex.push_back(S);
	for(i=1;i<=N;i++){
		unV.insert(i);
		set<int> S;
		S.insert(i);
		Ex.push_back(S);
	}
	while(!flag && !unV.empty()){
		//printf("Starting dfs from: %d\n",*(unV.begin()));
		dfs(*(unV.begin()));
	}
	printf("%s",flag?"Yes":"No");
}


int main(){
	int i,j,k,t;
    scanf("%d\n",&t);
    for(i=1;i<=t;i++){
		scanf("%d",&N);
		for(j=1;j<=N;j++){
			scanf("%d",&adj[j][0]);
			for(k=1;k<=adj[j][0];k++){
				scanf("%d",&adj[j][k]);
			}
		}
        printf("Case #%d: ",i);
        solve();
        printf("\n");
    }
}

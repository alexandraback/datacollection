#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;


vector <int> v[100];

bool visit[100],flag;


void dfs(int r){

	int l,i,u;

	visit[r]=true;

	l=v[r].size();

	for(i=0;i<l;i++){
		u=v[r][i];

		if(!visit[u])
			dfs(u);
		else{

			flag=true;break;
		}

		if(flag)
			break;
	}
}




int main(){
//	freopen("i.txt","r",stdin);
//	freopen("w.txt","w",stdout);

	int T,cas,i,j,a,n,k;
	
	scanf("%d",&T);

	for(cas=1;cas<=T;cas++){


		for(i=0;i<100;i++) v[i].clear();
		
		scanf("%d",&n);

		for(i=1;i<=n;i++){
			scanf("%d",&k);
			for(j=0;j<k;j++){
				scanf("%d",&a);
				v[a].push_back(i);	
			}
		}

		for(i=1;i<=n;i++){

			memset(visit,false,sizeof(visit));
			flag=false;
			dfs(i);
			if(flag)
				break;
		}


		
		if(flag)
			printf("Case #%d: Yes\n",cas);
		else
			printf("Case #%d: No\n",cas);
		flag=false;


	}



  return 0;
}
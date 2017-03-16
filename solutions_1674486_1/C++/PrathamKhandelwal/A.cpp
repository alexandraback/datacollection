#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;
int main(){
	int T,N,M;
	int i,j,k,t;
	bool flag,visit[1010];
	
	t = 1;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		vector<vector<int> > vv(N);
		
		for(i=0;i<N;i++){
			scanf("%d",&M);
			for(j=0;j<M;j++){
				scanf("%d",&k);
				vv[i].push_back(k-1);
			}
		}
		
		printf("Case #%d: ",t++);
		flag = false;
		for(i=0;i<N && !flag;i++){
			memset(visit,false,sizeof(visit));
			queue<int> q;
			
			q.push(i);
			visit[i] = true;
			while(!q.empty() && !flag){
				j = q.front(); q.pop();
							
				for(k=0;k<vv[j].size();k++){
					if(visit[vv[j][k]]){
						printf("Yes\n");
						flag = true;
						break;
					}
					visit[vv[j][k]] = true;
					q.push(vv[j][k]);
				}
			}
		}
		if(!flag) printf("No\n");
	}
	return 0;
}

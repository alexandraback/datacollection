#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){
	int T,t,i,M,j,c,p,N;
	int i_from_ct[1008];
	bool isVisited[1008],found_ans;
	queue<int> q,dq;
	scanf("%d",&T);
	for(t=1;t<=T;t++){
		scanf("%d",&N);
		vector<int> i_from[N+1];
		for(i=0;i<N;i++) {
			i_from_ct[i] = 0;
			isVisited[i] = false;
		}
		for(i=0;i<N;i++){
			scanf("%d",&M);
			for(j=0;j<M;j++){
				scanf("%d",&c);
				i_from[i].push_back(c-1);
				i_from_ct[c-1]++;
			}
		}
		
		found_ans = false;
		for(i=0;i<N;i++){
			if(i_from_ct[i] == 0){
				q.push(i);
				isVisited[i] = true;
				while(!q.empty()){
					p = q.front();
					if(!found_ans){
						for(j=0;j<i_from[p].size();j++){
							if(isVisited[i_from[p][j]]){
								found_ans = true;
								break;
							} else {
								isVisited[i_from[p][j]] = true;
								q.push(i_from[p][j]);
							}
						}
					}
					dq.push(p);
					q.pop();
				}
				
				while(!dq.empty()){
					p = dq.front();
					isVisited[p] = false;
					dq.pop();
				}
				
				if(found_ans)
					break;
			}
		}
		printf("Case #%d: ",t);
		if(found_ans){
			printf("Yes");
		} else
			printf("No");
		printf("\n");
	}
}
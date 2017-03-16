#include<iostream>
#include<cstdio>

using namespace std;

int scores[101][2];

int main(){
	int t,kase=1,n,s,p,i,val,count=0;
	scanf("%d",&t);
	while(t--){
		count=0;
		scanf("%d %d %d",&n,&s,&p);
		for(i=0;i<n;i++){
			scanf("%d",&val);
			scores[i][0]=val/3;
			scores[i][1]=val%3;
			if(val==0){
				if(p==0)
					count++;
				continue;
			}
			if(scores[i][1]==0){
				if(p<=scores[i][0]){
					count++;
				}else if(p==scores[i][0]+1 && s>0){
					count++;
					s--;
				}
			}else if(scores[i][1]==1){
				if(p<=scores[i][0]+1){
					count++;
				}
			}else if(scores[i][1]==2){
				if(p<=scores[i][0]+1){
					count++;
				}else if(p==scores[i][0]+2 && s>0){
					count++;
					s--;
				}
			}
			//printf("%d %d: %d %d\n",scores[i][0],scores[i][1],count,s);
		}
	printf("Case #%d: %d\n",kase,count);
	kase++;
	}
}

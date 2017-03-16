#include "stdio.h"
#include "string.h"
#include <algorithm>
#include <queue>
#include <map>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
void Process(){
}
void Solve(){
	printf("\n");
	int possible[]={2,3,5,7};
	
	int R,N,M,K;
	scanf("%d %d %d %d",&R,&N,&M,&K);
	while(R--){
		int cnt[10],cnt2[10];
		memset(cnt,0,sizeof(cnt));
		memset(cnt2,0,sizeof(cnt2));
		for(int i=0;i<K;i++){
			int num;
			scanf("%d",&num);
			for(int j=0;j<4;j++){
				int tmp=0;
				while(num%possible[j]==0) {
					cnt2[possible[j]]++;
					tmp++;
					num/=possible[j];
				}
				cnt[possible[j]]=max(cnt[possible[j]],tmp);
			}
		}
		cnt[7]=max(cnt[7],(int)(((double)cnt2[7]*2)/K+0.5));
		cnt[5]=max(cnt[5],(int)(((double)cnt2[5]*2)/K+0.5));
		cnt[3]=max(cnt[3],(int)(((double)cnt2[3]*2)/K+0.5));
		int left=N-cnt[3]-cnt[5]-cnt[7];
		cnt[2]=(int)((double)(2*left*K-2*cnt2[2])/K+0.5);
		cnt[4]=left-cnt[2];

		int n=N;
		for(int i=M;i>=2;i--){
			if(n==0) break;
			for(int j=0;j<cnt[i];j++){
				if(n==0) break;
				printf("%d",i);
				n--;				
			}
		}
		while(n>0){
			printf("2");
			n--;
		}
		printf("\n");
	}
}
int main(){
	freopen("D:\\Test\\in.txt","r",stdin);
	freopen("D:\\Test\\out.txt","w",stdout);
	Process();
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++){			
		printf("Case #%d: ",t);
		Solve();
	}
    return 0;
}
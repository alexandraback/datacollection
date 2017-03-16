#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
	int T;scanf("%d",&T);
	for(int t=1;t<=T;t++){
		int K,C,S;
		scanf("%d%d%d",&K,&C,&S);
		int pr=(K+C-1)/C;
		printf("Case #%d: ",t);
		if(pr>S){
			printf("IMPOSSIBLE\n");continue;
		}
		for(int i=0;i<pr;i++){
			if(i)printf(" ");
			long long now=0;
			for(int j=0;j<C;j++){
				now*=K;
				if(i*C+j<K)now+=i*C+j;
			}
			printf("%lld",now+1);
		}
		printf("\n");
	}
}
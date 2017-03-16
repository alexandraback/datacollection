#include <cstdio>

int main(){
	int T,K,C,S;
	int cs=0;
	long long num[110];
	scanf("%d",&T);
	while(T--){
		scanf("%d %d %d",&K,&C,&S);
		if( (K-C+1)>S ){
			printf("Case #%d: IMPOSSIBLE\n",++cs);
			continue;
		}
		for(int i=1;i<=K;++i){
			num[i]=i;
		}
		for(int i=1;i<C;++i){
			num[0]=(num[1]-1)*K;
			for(int j=1;j<=K-i;++j){
				num[j]=num[0]+((num[j+1]-1)%K)+1;
			}
		}
		printf("Case #%d:",++cs);
		if(K-C+1>1){
			for(int i=1;i<=K-C+1;++i){
				printf(" %lld",num[i]);
			}
			printf("\n");
		}
		else{
			printf(" %lld\n",num[1]);
		}
	}
	return 0;
} 

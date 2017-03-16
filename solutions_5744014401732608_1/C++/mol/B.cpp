#include <stdio.h>
#include <string.h>

int main(){
	int T;
	scanf("%d",&T);
	for(int tt=0; tt<T; tt++){
		long long int B,M;
		scanf("%lld%lld",&B,&M);
		if(M > 1<<(B-2)){
			printf("Case #%d: IMPOSSIBLE\n",tt+1);
			continue;
		}
		printf("Case #%d: POSSIBLE\n",tt+1);
		if(M == 1<<(B-2)){
			printf("0");
			for(int j=1; j<B; j++)
				printf("1");
		}else{
			for(int j=0; j<B-1; j++)
				printf("%d",(M>>(B-2-j))%2);
			printf("0");
		}
		printf("\n");
		for(int i=1; i<B-1; i++){
			for(int j=0; j<=i; j++)
				printf("0");
			for(int j=i+1; j<B; j++)
				printf("1");
			printf("\n");
		}
		for(int j=0; j<B; j++)
			printf("0");
		printf("\n");
	}
	return 0;
}

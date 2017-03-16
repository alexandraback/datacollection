#include <stdio.h>
#include <math.h>

long long int pow(int a, int b){
	long long int ans = 1;
	for(int i=0; i<b; i++)
		ans *= a;
	return ans;
}

int main(){
	int T;
	scanf("%d",&T);
	for(int i=0; i<T; i++){
		int K,C,S;
		scanf("%d%d%d",&K,&C,&S);
        if(K>S*C){
            printf("Case #%d: IMPOSSIBLE\n",i+1);
            continue;
        }
        printf("Case #%d: ",i+1);
        int cnt = ceil((double)K/C);
        for(int j=0; j<cnt; j++){
            long long int student = 1;
            for(int k=0; k<C && k<K-j*C; k++)
            	student += pow(K,k)*(j*C+k);
            printf("%lld ",student);
        }
        printf("\n");
	}
	return 0;
}

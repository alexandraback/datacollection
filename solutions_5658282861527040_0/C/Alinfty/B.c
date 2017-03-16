#include <stdio.h>

int main(){
	int t,T;
	int i,j;
	int A,B,K;
	int ans;
	
	scanf("%d", &T);
	for(t=1;t<=T;t++){
		scanf("%d %d %d", &A, &B, &K);
		ans=0;
		for(i=0;i<A;i++){
			for(j=0;j<B;j++){
				if((i&j)<K) ans++;
			}
		}
		printf("Case #%d: %d\n",t,ans);
	}
	return 0;
}

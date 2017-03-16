#include <stdio.h>

int t,n,k;

int main(){
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%d %d",&n,&k);
		printf("Case #%d:\n",i);
		for(int j=0;j<k;j++){
			printf("1");
			for(int l=0;l<(n-2)/2;l++){
				printf("%d",((1<<l)&j)!=0);
			}
			for(int l=(n-2)/2-1;l>=0;l--){
				printf("%d",((1<<l)&j)!=0);
			}
			printf("1 3 4 5 6 7 8 9 10 11\n");
		}
	}
	return 0;
}

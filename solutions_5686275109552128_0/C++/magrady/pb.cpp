#include <stdio.h>
int P[1001];
int main(){
	int i,j,k;
	int D,T,TN;
	scanf("%d",&TN);
	for(T=1;T<=TN;T++){
		scanf("%d",&D);
		for(i=0;i<D;i++){
			scanf("%d",&P[i]);
		}
		int sum, min=1000000;
		for(i=1;i<=1000;i++){
			sum=i;
			for(j=0;j<D;j++){
				sum+=(P[j]-1)/i;
			}
			if(min>sum){
				min=sum;
			}
		}
		printf("Case #%d: %d\n",T,min);
	}
}
	

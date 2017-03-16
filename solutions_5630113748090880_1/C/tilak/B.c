#include<stdio.h>
int n[2501];
int main(){
	int t,i,j,k,len,l,r;
	scanf("%d",&t);
	for(i=0;i<t;i++){
		for(j=0;j<2501;j++){
			n[j] = 0;
		}
		scanf("%d",&k);
		r = (2*k*k) - k;
		for(j=0;j<r;j++){
			scanf("%d",&l);
			if(n[l]>0)
				n[l]--;
			else
				n[l]++;
		}
		
		printf("Case #%d:",i+1);
		for(j=0;j<2501;j++){
			if(n[j]>0)
				printf(" %d",j);
		}
		printf("\n");
	}
	return 0;
}

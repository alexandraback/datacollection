#include<stdio.h>
int main(){
	int t;
	int i,j,k,l,n;
	int a[2501];
	for(scanf("%d",&t),i=1;i<=t;i++){
		for(j=0;j<2501;j++)
			a[j]=0;
		scanf("%d",&n);
		for(j=0;j<2*n-1;j++)
			for(k=0;k<n;k++){
				scanf("%d",&l);
				a[l]++;
			}
		printf("Case #%d: ",i);
		for(j=0;j<2501;j++)
			if(a[j]%2!=0)
				printf("%d ",j);
		printf("\n");		
	}
}

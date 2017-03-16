#include<stdio.h>

int main(){
	int t;
	scanf("%d",&t);
	int q=t;
	while(t--){
		int n;
		printf("Case #%d: ",q-t);
		int count[2501]={0};
		scanf("%d",&n);
		int i;
		for(i=0;i<n*(2*n-1);i++){
			int k;
			scanf("%d",&k);
			count[k]++;
		}
		int c=0;
		int b[51]={0};
		for(i=1;i<=2500;i++){
			if(count[i]%2==1){
				b[c]=i;
				c++;
			}
		}
		for(i=0;i<c;i++){
			printf("%d ",b[i]);
		}
		printf("\n");
	}
}

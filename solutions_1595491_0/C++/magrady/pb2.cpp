#include<stdio.h>
main(){
	int i,j,k;
	int T,TN=0;
	int n,s,p;
	scanf("%d",&TN);
	for(T=1;T<=TN;T++){
		scanf("%d%d%d",&n,&s,&p);
		j=0;
		while(n--){
			scanf("%d",&k);
			j+=(k+2)/3>=p||k&&k%3!=1&&(k+5)/3>=p&&s-->0;
		}
		printf("Case #%d: %d\n",T,j);
	}
}

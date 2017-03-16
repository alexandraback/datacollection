#include <stdio.h>

int main(){
	int a,b,k,i,j,t,tt,res;
	scanf("%d",&t);
	for(tt=1;tt<=t;tt++){
		res=0;
		scanf("%d%d%d",&a,&b,&k);
		for(i=0;i<a;i++)for(j=0;j<b;j++){
			if((i&j)<k)res++;
		}
		printf("Case #%d: %d\n",tt,res);
	}
	return 0;
}

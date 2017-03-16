#include <stdio.h>

int main(){
	int cases,casecnt,i;
	char inp[30];
	long long p,q,temp;
	long double P,Q,frac,partfrac;
	scanf("%d",&cases);
	for(casecnt=1;casecnt<=cases;casecnt++){
		scanf("%s",inp);
		sscanf(inp,"%I64d/%I64d",&p,&q);
		temp=1;
		for(i=0;i<11;i++){
			if(q==temp) break;
			temp<<=1;
		}
		if(i<11){
			P=p;Q=q;frac=P/Q;
			partfrac=1;
			for(i=0;i<11;i++){
				if(frac>=partfrac) break;
				partfrac/=2.0;
			}
			printf("Case #%d: %d\n",casecnt,i);
		}else{
			printf("Case #%d: impossible\n",casecnt);
		}
	}
	return 0;
}

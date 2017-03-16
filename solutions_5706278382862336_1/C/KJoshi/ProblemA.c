#include <stdio.h>

int main(){
	int cases,casecnt,i,maxi;
	char inp[30];
	long long p,q;
	long double P,Q,frac,partfrac;
	scanf("%d",&cases);
	for(casecnt=1;casecnt<=cases;casecnt++){
		scanf("%s",inp);
		sscanf(inp,"%I64d/%I64d",&p,&q);
		P=p;
		Q=q;
		frac=P/Q;
		partfrac=1;
		maxi=-1;
		for(i=0;i<41;i++){
			if(frac>=partfrac){
				if(maxi==-1) maxi=i;
				frac-=partfrac;
			}
			partfrac/=2.0;
			if(frac==0) break;
		}
		if(frac==0 && maxi!=-1){
			printf("Case #%d: %d\n",casecnt,maxi);
		}else{
			printf("Case #%d: impossible\n",casecnt);
		}
	}
	return 0;
}

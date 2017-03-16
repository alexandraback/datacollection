#include<stdio.h>
int main(){
	int i,j,k,T,ID=0;
	double C,F,X,nC,Rate,Best,Now;
	scanf("%d",&T);
	while(T--){
		ID++;
		scanf("%lf%lf%lf",&C,&F,&X);
		for(Best=1.e100,Rate=2,nC=.0,i=0;nC<Best;i++,nC+=C/Rate,Rate+=F){
			Now=nC+X/Rate;
			if(Best>Now)
				Best=Now;
		}
		printf("Case #%d: %.7lf\n",ID,Best);
	}
}

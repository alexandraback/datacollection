#include<stdio.h>
int main(){
	int T,t=0;
	scanf("%d",&T);
	while(++t<=T){
		double ans=0;
		double now=0;
		double rate=2;
		bool tmp=true;
		double C, F, X;
		scanf("%lf%lf%lf",&C,&F,&X);
		while(tmp){
			if(now >= X)
				tmp=false;
			else if((X-now)/rate <= (X-0)/(rate+F)+(C-now)/rate){
				ans+=(X-now)/rate;
				tmp=false;
			}
			else{
				ans+=(C-now)/rate;
				rate+=F;
				now=0;
			}
		}
		printf("Case #%d: %.7lf\n",t,ans);
	}
}

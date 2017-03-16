#include<stdio.h>
int T,tot;
int main(){
	double c,f,x,rate,ansT,time;
	freopen("sample.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&T);
	for(tot=1;tot<=T;tot++){
		scanf("%lf%lf%lf",&c,&f,&x);
		rate = 2.0;
		ansT = x / rate;
		time = c / rate;
		while(true){
			double T0 = x / rate;
			double T3 = c / rate;
			rate += f;
			double T1 = x / rate;
			double T2 = c / rate;
			if(ansT > T1 + time+1e-7)ansT = T1 + time;
			if(T0-T1 > T3+1e-7){
				time += T2;
			}else break;
		}
		printf("Case #%d: %0.7lf\n",tot,ansT);
	}
}

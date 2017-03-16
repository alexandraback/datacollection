#include <cstdio>

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t,ti;
	double C,F,X,rate,elapsed;
	scanf("%d",&t);
	for(ti=1;ti<=t;ti++){
		scanf("%lf%lf%lf",&C,&F,&X);

		elapsed=0;
		rate=2;
		while(1){
			if(X/rate <= C/rate + X/(rate+F)){
				printf("Case #%d: %.7lf\n",ti,elapsed+X/rate);
				break;
			}else{
				elapsed+=C/rate;
				rate+=F;
			}
		}
	}
}
#include<stdio.h>

int main(){
	freopen("in.in","r",stdin);
	freopen("out.out","w", stdout);
	int n;
	scanf("%d",&n);
	for(int l = 1; l <= n;l++){
		double c, f, x, rate = 2.0;
		scanf("%lf %lf %lf", &c, &f, &x);
		double total_time = 0.0;
		while(true){
			double time_not_buy = (x / rate) + total_time;
			double time_buy = (c / rate) + (x / (rate + f)) + total_time;
			if (time_not_buy <= time_buy){
				total_time = time_not_buy;
				break;
			}
			else{
				total_time += (c / rate);
				rate += f;
			}
		}
		printf("Case #%d: %0.7lf\n", l, total_time);
	}
}
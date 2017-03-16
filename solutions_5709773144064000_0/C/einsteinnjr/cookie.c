#include <stdio.h>

int main(){
	int n, test=1, changes;
	scanf("%d", &n);
	double c, f, x, actualRate, timeElapsed, spent, rest, min;

	while(n--){
		scanf("%lf %lf %lf", &c, &f, &x);
		//printf("c %lf f %lf x %lf\n", c, f, x);
		timeElapsed=0;
		actualRate=2;
		min = x/actualRate;
		//printf("timeElapsed %.7lf actualRate %.7lf min %.7lf\n", timeElapsed, actualRate, min);

		while(c/actualRate+x/(actualRate+f)< x/actualRate){
			timeElapsed+=c/actualRate;
			min=timeElapsed+x/(actualRate+f);
			actualRate+=f;
			//printf("timeElapsed %.7lf actualRate %.7lf min %.7lf\n", timeElapsed, actualRate, min);
		} 
		//printf("out of while: %.7lf and %.7lf", c/actualRate+x/(actualRate+f), x/actualRate);
		printf("Case #%d: %.7lf\n", test++, min);
	}
	return 1;
}

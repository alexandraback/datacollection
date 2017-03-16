#include<stdio.h>      
#include<stdlib.h>      
#include<math.h>  

int main() { 
	
	int T,i;
	scanf("%d",&T);
	double time=0;
	
	for (i=1; i<=T; i++)
	{
		double C, F, X;
		scanf("%lf", &C);
		scanf("%lf", &F);
		scanf("%lf", &X);
		
		time=0;
		
		double cps=2;
		
		if (X/cps <= C/cps) {
			time = time + X/cps;
		}
		else {
			time = time + C/cps; 
			while ((X-C)/cps > X/(cps+F)) {
				cps = cps + F;
				time = time + C/cps;
			}
			time = time + (X-C)/cps;
		}
		
		printf("Case #%d: %.7lf\n",i,time);
	}
	
	return 0;
}
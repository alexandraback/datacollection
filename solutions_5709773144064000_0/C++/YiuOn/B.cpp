#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B out.txt", "w", stdout);

	int T,count;
	double C,F,X,rate,min;
	
	scanf("%d", &T);
	
	count = 1;
	while(T--){
		rate = 2;
		min = 0;
		scanf("%lf %lf %lf", &C, &F, &X);

		double buy = C/rate + X/(rate+F);
		double nbuy = X/rate;
		while(buy < nbuy){
			min += C/rate;
			rate += F;
			buy = C/rate + X/(rate+F);
			nbuy = X/rate;
		}

		printf("Case #%d: %.7lf\n", count++, min+nbuy);
	}
	

	return 0;
}
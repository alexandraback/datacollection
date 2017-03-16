#include <iostream>
#include <stdio.h>
using namespace std;
#define exp 1e-6

bool equal(double x, double y){

	bool absolute, relative;
	absolute = x-y >= -exp && x-y <= exp;
	relative = ((-exp <= (x - y) / x && (x - y) / x <= exp) || (-exp <= (x - y) / y && (x - y) / y <= exp));

	return absolute || relative;
}

int main(){
	freopen("B-large.in", "r", stdin);
	freopen("B-large out.txt", "w", stdout);

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
		while(nbuy > buy){
			min += C/rate;
			rate += F;
			buy = C/rate + X/(rate+F);
			nbuy = X/rate;
		}

		printf("Case #%d: %.7lf\n", count++, min+nbuy);
	}

	return 0;
}
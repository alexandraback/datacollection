#include <cstdio>

double min(double a, double b){
	if(a<b) return a;
	return b;
}

double test(){
	int a, b;
	scanf("%d %d", &a, &b);
	double res = b+2;
	double px = 1.0;
	for(int i=a-1; i>=0; i--){
		double t;
		scanf("%lf", &t);
		px *= t;
		res = min(res, px*(2*i+b-a+1)+(1-px)*(2*i+b-a+1+b+1));
	}

	return res;
}

int main(){
	int t;
	scanf("%d", &t);
	for(int i=1; i<=t; i++){
		printf("Case #%d: %.7lf\n", i, test());
	}	
}

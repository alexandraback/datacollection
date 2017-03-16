
#include <cstdio>

int main(){
	
	int testcase; scanf("%d", &testcase);
	double C, F, X;

	for(int t=1; t<=testcase; ++t){
		scanf("%lf %lf %lf", &C, &F, &X);
		double rate = 2.0;
		double best = X/rate;
		double base = 0;
		for(int i=1; ; ++i){
			if(base+C/rate+X/(rate+F) < best){
				best = base+C/rate+X/(rate+F);
				base = base+C/rate;
				rate = rate+F;
			}else{
				break;
			}
		}
		printf("Case #%d: %.7lf\n", t, best);
	}
	return 0;
}

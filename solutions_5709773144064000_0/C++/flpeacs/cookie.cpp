#include <cstdio>

int main(){
	long int t, cases, i;
	double c, f, x, persecond, total = 0.0;

	scanf("%d", &t);

	for(cases = 1; cases <= t; cases++){
		persecond = 2.0;
		total = 0.0;
		scanf("%lf %lf %lf", &c, &f, &x);

		while(1){
			if(x / persecond > c / persecond + x / (persecond + f)){
				total += c / persecond;
				persecond += f;
			} else{
				total += x / persecond;
				break;
			}
		}

		printf("Case #%d: %.7lf\n", total, cases);
	}
}

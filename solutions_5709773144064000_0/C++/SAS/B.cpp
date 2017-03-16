#include<stdio.h>
#include<stdlib.h>
inline double min(double a, double b){
	return a > b ? b : a;
}
int main(){
	int T;
	double C,F,X;
	scanf("%d", &T);
	for(int ca = 1; ca <= T; ca++){
		scanf("%lf %lf %lf", & C, &F , &X);
		double rate = 2.0;
		double ans = X / rate;
		double build_time = 0.0;
		while(build_time < X){
			build_time += C / rate;
			rate += F;
			double now_ans = build_time + X / rate;
			if(ans > now_ans)ans = now_ans;
			else break;
		}
		printf("Case #%d: %.10lf\n", ca, ans);
		
	}
	return 0;
}

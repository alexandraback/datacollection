
#include <cstdio>

double minima(double X, double Y){
	return (X < Y) ? X : Y;
}

int main(){
	
	int t; scanf("%d", &t);

	double s[100002];
	double r[100002];
	double sum[100002];

	for(int testcase=1; testcase<=t; ++testcase){
		
		int a, b; scanf("%d %d", &a, &b);

		for(int i=0; i<a; ++i){
			scanf("%lf", &s[i]);
		}

		double p = 1;

		for(int i=0; i<a; ++i){
			r[i] = p * (1-s[i]);
			p *= s[i];
		}

		sum[0] = p*(b-a+1)+(1-p)*(b-a+1+b+1);

		for(int i=1; i<=a; ++i){
			double wrong = 0;
			for(int j=0; j<a-i; ++j){
				wrong += r[j];
			}
			sum[i] = 2*i + wrong*(b-a+1+b+1) + (1-wrong)*(b-a+1);
		}

		sum[a+1] = 1+b+1;

		double ans = sum[0];

		for(int i=1; i<=a+1; ++i){
			ans = minima(sum[i], ans);
		}

		printf("Case #%d: %.6lf\n", testcase, ans);
	}
	return 0;
}

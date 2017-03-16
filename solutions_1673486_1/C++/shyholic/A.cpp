#include<stdio.h>

double pr[100000];
double cpr[100000];

double minval(double a, double b){
	return a > b ? b : a;
}

int main(void){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int t,T;
	double ans=0;
	int A,B;
	double ac = 1.0;
	scanf("%d\n",&T);
	for(t=0;t<T;t++){
		scanf("%d %d", &A, &B);
		for(int i=0;i<A;i++){
			scanf("%lf",&pr[i]);
			ac *= pr[i];
		}
		cpr[0] = 1.0-pr[0];
		for(int i=1;i<A;i++){
			cpr[i] = cpr[i-1] * (1.0 - pr[i]);
		}
		ans = minval(1+B+1, ac*double(B-A+1)+(1-ac)*double(B-A+1+B+1)); // Enter - retype - enter
		double pc = 0;
		for(int i=0;i<A;i++){
			double temp;
			pc = (1.0-pc)*pr[i];
			pc = 1.0 - pc;
			temp = (1.0-pc) * double(A-i-1 + B-i-1 + 1) + pc * double(A-i-1 + B-i-1 + 1 + B + 1);
			if(temp < ans){
				ans = temp;
			}
		}

		printf("Case #%d: %lf\n",t+1,ans);
	}
	return 0;
}
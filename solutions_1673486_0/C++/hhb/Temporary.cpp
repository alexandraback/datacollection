#include<stdio.h>

double poss[100000];
double solve() {
	int A, B;
	scanf("%d%d", &A, &B);
	double mn=B+2;
	for(int i=0;i<A;i++) {
		scanf("%lf", &poss[i]);
	}
	double p=1;
	for(int i=0;i<=A;i++) {
		double cur=p*(A-i+B-i+1)+(1-p)*(A-i+B-i+1+B+1);
		if(cur<mn) mn=cur;
		p*=poss[i];
	}
	return mn;
}

int main() {
	int T;
	scanf("%d", &T);
	for(int c=1;c<=T;c++) {
		printf("Case #%d: %.10lf\n", c, solve());
	}
}
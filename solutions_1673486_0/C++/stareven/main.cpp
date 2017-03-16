#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int MAXN=100000;
int A,B;
double p[MAXN+10];
double P[3];
int main() {
	int cases;
	scanf("%d",&cases);
	for (int c=1;c<=cases;c++) {
		scanf("%d%d",&A,&B);
		P[0]=B+2;
		double rate=1.0;
		for (int i=1;i<=A;i++) {
			scanf("%lf",&p[i]);
			rate*=p[i];
		}
		P[1]=(B-A+1)*rate+(B-A+1+B+1)*(1.0-rate);
		rate=1.0;
		P[2]=P[0];
		for (int i=0;i<=A;i++) {
			P[2]=min(P[2],rate*(A-i+B-i+1)+(1-rate)*(A-i+B-i+1+B+1));
			rate*=p[i+1];
		}
		printf("Case #%d: %.6f\n",c,min(P[0],min(P[1],P[2])));
	}
	return 0;
}

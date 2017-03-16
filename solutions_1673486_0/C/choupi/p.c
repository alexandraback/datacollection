#include <stdio.h>

int main()
{
	int t,T,A,B,i;
	double P[100001];
	double expT,tT,sP,tP;

	scanf("%d", &T);
	for(t=0;t<T;t++) {
		scanf("%d %d", &A, &B);
		for(i=0;i<A;i++) {
			scanf("%lf", &P[i]);
		}
//		printf("%d %d\n", A,B);
		tP=1;expT=B+2;
		for(i=-1;i<A;i++) {
			if(i>=0) tP*=P[i];
			tT=(A-i+B-i-1)+(1.0-tP)*(B+1);
//		printf("%d: %.2lf ", i,tT);
			if(tT<expT) expT=tT;
		}
		printf("Case #%d: %.6lf\n", t+1, expT);
	}
}

		

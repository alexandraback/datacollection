#include <cstdio>
#include <cmath>

double wp[100001];

int main(){
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;++t){
		int A,B;
		scanf("%d%d",&A,&B);
		wp[0] = 0;
		for(int i=0;i<A;++i){
			double prob;
			scanf("%lf",&prob);
			wp[i+1] = wp[i] + (1-wp[i])*(1 - prob);
			//printf("%d : %lf\n",i+1,wp[i+1]);
		}
		double minexp = 1e8;
		double exp;
		exp = (1-wp[A])*(B-A+1) + wp[A]*(B-A+1 + B+1);
		//printf("continue : %lf\n",exp);
		if(minexp > exp)	minexp = exp;
		exp = (1+B+1) ;
		//printf("enter : %lf\n",exp);
		if(minexp > exp)	minexp = exp;
		for(int i=1;i<=A;++i){
			exp = wp[A-i]*(i+B-(A-i)+1+B+1) + (1-wp[A-i])*(i+B-(A-i)+1);
			//printf("backspace %d : %lf\n",i,exp);
			if(minexp > exp)	minexp = exp;
		}
		printf("Case #%d: %lf\n",t,minexp);
	}
}

#include <stdio.h>

double p[100000];
double pacc[100000];

int main(){
	int T;
	scanf("%d", &T);
	for (int ttt = 1; ttt <= T; ttt++){
		int A, B;
		scanf("%d%d", &A, &B);
		for (int i = 0; i <A; i++){
			scanf("%lf", p+i);
			if (i == 0)
				pacc[i] = p[i];
			else
				pacc[i] = pacc[i - 1] * p[i];
		}
		double res;
		//keep typing
		double R1 = pacc[A-1] * (B-A+1) + (1-pacc[A-1]) * (B-A+1+B+1);
		//press enter now
		double R2 = B+2;
		res = R1<R2?R1:R2;
		//backspace
		for (int bs = 1; bs <= A; bs++){
			double R3;
			if (bs < A)
				R3 = pacc[A-1-bs] * (bs+bs+B-A+1) + (1-pacc[A-1-bs]) * (bs+bs+B-A+1+B+1);
			else
				R3 = A+B+1;
			if (R3 < res) res = R3;
		}
		printf("Case #%d: %lf\n", ttt, res);
	}
	return 0;
}
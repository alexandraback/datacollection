#include <stdio.h>

#define MAX 100000

int main(){
	
	double ppi[MAX+1];
	long T, A, B, t, a, i;
	double p, min, exp;
	 
	scanf("%ld",&T);
	t = 0;
	
	while(t < T){
		scanf("%ld%ld",&A,&B);
		a = 0;
		ppi[0] = 1;
		while(a < A){
			scanf("%lf",&p);
			ppi[a+1] = ppi[a] * p;	//ppi denote p1 * p2 * p3 ... 
			a++;
		}
		//if press enter now and do again
		min = B + 2;
		// if press backspace i time and proceed 0 <= i <= A
		i = 0;
		while(i < A){
			exp = (B - A + 2 * i + 1) * ppi[A - i] + (2 * B - A + 2*i +2) * (1 - ppi[A - i]);
			if (exp < min)
				min = exp;
			i++;
		}
		
		printf("Case #%ld: %lf",t+1, min);
		
		if(t != T-1)
			printf("\n");
		t++;
	}
	
	return 0;
}
		
		

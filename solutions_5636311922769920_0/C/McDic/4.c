#include <stdio.h>

long long int pow_(long long int a, long long int b){
	long long int c=1;
	while(b>0){
		c*=a;
		b--;
	}
	return c;
}

long long int location_calc(long long int num, long long int degree, long long int basiclength){
	
	long long int s=1;
	long long int i;
	for(i=0; i<degree; i++){
		s+= (num-1)*pow_(basiclength,i);
	}
	return s;
}

int main(void){
	
	long long int testcase, tt;
	long long int i;
	long long int K, C, S;
	
	freopen("D-small-attempt1.in", "r", stdin);
	freopen("output_4_small.txt", "w", stdout);
	
	scanf("%lld", &testcase);
	
	for(tt=1; tt<=testcase; tt++){
		
		scanf("%lld %lld %lld", &K, &C, &S);
		printf("Case #%lld:", tt);
		for(i=1; i<=S; i++){
			printf(" %lld", location_calc(i,C,K));
		} printf("\n");
		
	}
	
	return 0;
}

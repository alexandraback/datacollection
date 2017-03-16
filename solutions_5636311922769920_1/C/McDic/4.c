#include <stdio.h>

long long int pow(long long int a, long long int b){
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
		s+= (num-1)*pow(basiclength,i);
	}
	return s;
}

int main(void){
	
	long long int testcase, tt;
	long long int i, j, tempselected;
	long long int K, C, S; // original length, depth, can clean
	
	long long int minrequired, tempK;
	
	freopen("D-large.in", "r", stdin);
	freopen("output_4_large.txt", "w", stdout);
	
	scanf("%lld", &testcase);
	
	for(tt=1; tt<=testcase; tt++){
		
		scanf("%lld %lld %lld", &K, &C, &S);
		printf("Case #%lld:", tt);
		/*for(i=1; i<=S; i++){
			printf(" %lld", location_calc(i,C,K));
		} printf("\n");*/
		
		minrequired=0;
		tempK = K;
		while(tempK>0){
			tempK -= C;
			minrequired++;
		}
		
		if(minrequired > S){
			printf(" IMPOSSIBLE\n");
		}
		else{
			i=0;
			while(minrequired>0){
				minrequired--;
				tempselected=1;
				for(j=0; j<C && i*C+j<K; j++){
					tempselected += (i*C+j)*pow(K,C-j-1);
					//printf("<TURN %lld - (C=%lld),%lld,%lld>", j, C, i*C+j,pow(K,C-j-1));
				}
				printf(" %lld", tempselected);
				i++;
			} printf("\n");
		}
	}
	
	return 0;
}

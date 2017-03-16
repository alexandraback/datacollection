#include <stdio.h>

void print2jin(long long int n){
	long long int i=0, norigin = n;
	while(n>0){
		n/=2;
		i++;
	}
	while(i>0){
		printf("%1d", (norigin/(1<<(i-1)))%2);
		i--;
	}
	return;
}

long long int pow_(long long int a, long long int b){ // a^b
	long long int c=1;
	while(b>0){
		c *= a;
		b--;
	}
	return c;
}

long long int jamcoinvalue(long long int jam, long long int n){
	long long int s=0, i=0;
	while(jam>0){
		s += (jam%2)*pow_(n,i);
		i++;
		jam/=2;
	}
	return s;
}

long long int isprime(long long int a){ // nontrivial divisors
	long long int i, max=-1;
	for(i=2; i*i<=a; i++){
		if(a%i==0 && max<i){
			max = i;
		}
	}
	return max;
}

long long int main(void){
	
	freopen("C-large.in", "r", stdin);
	freopen("output_3_large.txt", "w", stdout);
	
	long long int n, j, jj;
	long long int temp, max;
	
	long long int status=0;
	long long int i, k;
	long long int jam, jamchanger;
	
	long long int testcase, tt;
	scanf("%lld", &testcase);
	
	for(tt=1; tt<=testcase; tt++){
		
		scanf("%lld %lld", &n, &j); // N length, J jamcoins
		jj = 0;
		
		if(n==1) jam=1;
		else jam = (1<<(n-1)) + 1;
		
		max = (1<<n) - 1;
		
	//f	printf("JAM %d MAX %d\n", jam, max);
		
		printf("Case #%lld:\n", tt);
			
		while(jam<=max && jj<j){
			
			status=1;
			for(k=2; k<=10; k++){
				if(isprime(jamcoinvalue(jam,k))==-1){
					status=0; break;
				}
			}	
			if(status==1){
				print2jin(jam);
//				printf(" ");
				for(k=2; k<=10; k++){
					temp = jamcoinvalue(jam,k);
					printf(" %lld", isprime(temp));
					//printf(" (%lld*%lld=%lld)", isprime(temp), temp/isprime(temp), temp);
				} printf("\n");
				jj++;
			}
			
			jam += 2;
		}
	}
	
	
	return 0;
}

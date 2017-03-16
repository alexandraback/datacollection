
#include <cstdio>

long long pow(long long a, int b){
	
	long long r = 1;

	for(int i=1; i<=b; ++i){
		r = r*a;
	}
	return r;
}

int eval(long long x){
	for(int i=0; i<=40; ++i){
		if(x == pow(2, i)){
			return i;
		}
	}
	return -1;
}

long long gcd(long long a, long long b){
	
	while(a!=0 && b!=0){
		if(a > b){
			a%=b;
		}else{
			b%=a;
		}
	}
	return a+b;
}

int main(){
	
	int testcase; scanf("%d", &testcase);
	long long a, b;
	char c;

	for(int t=1; t<=testcase; ++t){
		scanf("%lld%c%lld", &a, &c, &b);
		printf("Case #%d: ", t);
		long long c = gcd(a, b);
		a /= c;
		b /= c;
		//printf("(%lld,%lld)\n", a, b);
		
		if(eval(b) == -1){
			printf("impossible\n");
		}else{
			long long k = a*pow(2, 40-eval(b));
			
			int found = 0;
			for(int i=39; i>=0; --i){
				if(k >= pow(2, i)){
					printf("%d\n", 40-i);
					found = 1;
					break;
				}
			}
			if(!found){
				printf("impossible\n");
			}
		}
		
	}
	return 0;
}

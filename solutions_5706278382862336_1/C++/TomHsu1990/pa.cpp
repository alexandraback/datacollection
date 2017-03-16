#include <stdio.h>
long long int GCD(long long int a, long long int b){
	if(b == 0) return a;
	else	   return GCD(b, a%b);
}
int main(){
	int t;
	scanf("%d", &t);
	long long int table[41];
	table[0] = 1;
	for(int i=1;i<41;++i){
		table[i] = table[i-1]*2;
		//printf("%lld\n", table[i]);
	}
	for(int c=1;c<=t;++c){
		long long int a, b;
		scanf("%lld/%lld", &a, &b);
		int gen = 0;
		while(a < b){
			long long int gcd;
			gcd = GCD(a, b);
			a = a/gcd;
			b = b/gcd;
			int find = -1;
			for(int i=0;i<41;++i){
				if(b == table[i]){
					find = 1;
					break;
				}
			}
			if(find < 0) break;
			a = a*2;
			++gen;
		}
		printf("Case #%d: ", c);
		if(a < b){
			printf("impossible\n");
		}
		else{
			printf("%d\n", gen);
		}
	}
}

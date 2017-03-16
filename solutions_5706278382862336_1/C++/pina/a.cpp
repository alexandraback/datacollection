#include<stdio.h>
#include<stdlib.h>
#include<math.h>
long long int gcd(long long int a, long long int b) {
	return a==0? b : gcd(b%a, a);
}
int main(){
	int t, tc = 1;
	long long int p, q;
	for(scanf("%d", &t); tc <= t; tc++) {
		scanf("%lld/%lld", &p, &q);
		long long int g = gcd(p, q);
		p /= g;q /= g;
		if((q&(-q)) != q) {
			printf("Case #%d: impossible\n", tc);
			continue;
		}
		long long int k = 2;
		for(int i = 1; i < 41; i++, k*=2) {
			if(p >= q / k) {
				printf("Case #%d: %d\n", tc, i);
				break;
			}
		}
	}
	return 0;
}

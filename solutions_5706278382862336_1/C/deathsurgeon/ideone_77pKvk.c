#include <stdio.h>

int main() {
	long long t, i, j, k, a, b, s;
	char c[30];
	
	scanf("%lld", &t);
	
	for (i=1; i<=t; i++) {
		printf("Case #%lld: ", i);
		scanf("%s", c);
		a=0;
		j=0;
		while (c[j]!='/') {
			a = 10*a + c[j]-'0';
			j++;
		}
		j++;
		b=0;
		while (c[j]) {
			b = 10*b + c[j]-'0';
			j++;
		}
		j=a; k=b;
		while (k != 0) {
    	s = k;
    	k = j % k;
    	j = s;
  		}
  		
		a/=j;
		b/=j;
		j=b;
		
		while (j!=1) {
			if (j%2==1) {
				printf("impossible\n");
				goto HELL;
			}
			j>>=1;
		}
		
		k=0;
		while (a!=1) {
			a>>=1;
			b>>=1;
		}
		
		while (b!=1) {
			b>>=1;
			k++;
		}
		
		printf("%lld\n", k);
		
		HELL:;
	}
	return 0;
}

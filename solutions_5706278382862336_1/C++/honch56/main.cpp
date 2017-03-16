#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

long long gcd(long long a, long long b){
	if(a < b) return gcd(b, a);
	if(b == 0) return a;
	return gcd(b, a % b);
}

int main(){
	long long i, j, k, n, len;
	int ti, tc;
	long long p, q;
	char str[100];

	scanf("%d", &tc);
	

	for(ti = 1 ; ti <= tc; ti ++){
		scanf("%s", str);
		for(j=0;str[j];j++) if(str[j] == '/') str[j] = ' ';
		sscanf(str, "%lld %lld", &p, &q);

		long long g = gcd(p,q);
		p /= g;
		q /= g;

		for(i=1;i<=40;i++) if(q == (long long)1 << i) i = 42;
		if(i != 43){
			printf("Case #%d: impossible\n", ti);
			continue;
		}

		long long f = ((long long) 1<<40) / q;
		p *= f;
		q *= f;

		for(i = 1; ((long long) 1 << i) <= p; i++){}
		printf("Case #%d: %lld\n", ti, 41 - i);	
	}

	return 0;
}
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
#define f1(i,n) for (int i=1; i<=n; i++)
#define f0(i,n) for (int i=0; i<n; i++)

main(){
	int t; scanf("%d", &t);
	f1(i,t) {
		long A, B;
		scanf("%lld%*c%lld", &A, &B);
		long GCD = __gcd(A, B);
		A/=GCD, B/=GCD;
		if (B&B-1) printf("Case #%d: impossible\n", i);
		else {
			int x = 0;
			while (A<B) { B/=2; x++; }
			printf("Case #%d: %d\n", i, x);
		}
	}
}


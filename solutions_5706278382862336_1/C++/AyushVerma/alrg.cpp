#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define lli long long int
using namespace std;

long long int gcd (long long int a, long long int b)
{
	if (b % a == 0)
		return a;
	else
		return(gcd(b%a, a));
}

int main() {
	// your code goes here
	lli tcase,i,i1,j,k,l,p,q,r,t,s,u,ans;
	char z;
	double a,b,c;
	
	scanf("%lld", &tcase);
	
	i1 = 1;
	
	while (i1 <= tcase) {
		printf("Case #%lld: ", i1);
		
		scanf("%lld%c%lld", &p, &z, &q);
		
		t = gcd(p,q);
		
		p = p / t;
		q = q / t;
		
		r = p / q;
		
		t = q & -q;
		
		if ((r > 1) || ((r == 1) && (p != q)) || (t != q)) {
			printf("impossible\n");
			++i1;
			continue;
		}
		
		a = (double)q/(double)p;
		
		ans = (lli)ceil(log2(a));
		
		printf("%lld\n", ans);
		++i1;
	}
	return 0;
}
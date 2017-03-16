#include<stdio.h>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<iostream>

using namespace std;

inline long long GCD ( long long a , long long b ){
	
	long long r;
	while ( b ){
		r = a % b;
		a = b;
		b = r;
	}
	
	return a;
}

int main () {
	
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	
	int tests;
	scanf("%d",&tests);
	
	for ( int t = 1 ; t <= tests ; ++t) {
		
		long long A,B;
		scanf("%lld/%lld",&A,&B);
		
		long long gcd = GCD(A,B);
		A /= gcd , B /= gcd;
		
		if ( B & (B-1) ){
			printf("Case #%d: impossible\n",t);
			continue ;
		}
		
		int sol = 0;
		while ( B > A ){
			B >>= 1;
			++sol;
		}
		
		printf("Case #%d: %d\n",t,sol);
	}
	
	return 0;
}
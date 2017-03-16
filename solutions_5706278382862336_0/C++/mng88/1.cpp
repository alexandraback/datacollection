#include <cstdio>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;
#define INF 2000000000
#define INFLL (1LL<<62)
#define SS ({int x;scanf("%d", &x);x;})
#define SSL ({lint x;scanf("%lld", &x);x;})
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i,m,n) for(int i=(m);i<(n);i++)
#define ull unsigned long long
#define lint long long
#define MX 10000001

lint pow2[42];

void precalc() {

	pow2[0] = 1;
	rept(i,1,41) {
		pow2[i] = 2ll*pow2[i-1];
		// cout<<i<<" : "<<pow2[i]<<endl;
	}
}

lint gcd(lint a, lint b){

	if(b==0)
		return a;

	return gcd(b,a%b);

}

bool ispow2(lint n) {

	while(n>1 && n%2==0)
		n/=2;

	return n==1;
}

int solve (lint p, lint q) {

	lint div = gcd(p,q);
	p/=div;
	q/=div;

	if(!ispow2(q))
		return -1;

	rep(i,41) {
		if(p*pow2[i]/q >= 1)
			return i;
	}

	return -1;
}

int main() {
	
	int t;
	precalc();
	t=SS;	
	rept(testCase, 1, t+1) {

		lint p,q;
		scanf("%lld/%lld", &p, &q);

		int ans = solve(p,q);

		printf("Case #%d: ",testCase);

		if (ans == -1) {
			cout<<"impossible\n";
		} else {
			cout<<ans<<endl;
		}
	}
	return 0;
}





#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
LL R,P;

double F(double m) {
    return m*(2*R-3) + 2*m*(m+1);
}
LL X(LL m) {
    return m*(2*R-3) + 2*m*(m+1);
}
int main() {
    int T;
    scanf("%d", &T);
    for (int tc=1; tc<=T; tc++) {
	scanf("%lld%lld", &R, &P);

	LL lo=0, hi=1LL<<30, m;
	for (;hi-lo>1;) {
	    m=(hi-lo)/2+lo;
	    if (P<=F(m)) hi=m;
	    else lo=m;
	}

	LL ans=max(lo-1, 0LL);
	for (;X(ans+1)<=P; ) ans++;
	printf("Case #%d: %lld\n", tc, ans);
    }
    return 0;
}

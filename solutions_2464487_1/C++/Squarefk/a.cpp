#include <cstdio>
#include <iostream>
#define LL long long
#define LD long double
using namespace std;

const LD PI=3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679;
LD r,t;
LL ans;
int T;

LD Js(LL n) {
	LD ret=(LD)n*2.0*(LD)r;
	return ret+(LD)n+(LD)n*(LD)(n-1)*2ll;
}

int main() {
	freopen("A-large.in","r",stdin);
	freopen("1.txt","w",stdout);
	scanf("%d",&T);
	for (int T_T=1;T_T<=T;++T_T) {
		cin>>r>>t;
		ans=0;
		for (LL i=1ll<<62ll;i;i>>=1ll)
			if (Js(ans+i)<=t) ans+=i;
		printf("Case #%d: %I64d\n",T_T,ans);
	}
	return 0;
}

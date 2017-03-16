#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#define int64 long long
#define For(i,x,y) for (i=x;i<=y;i++)
using namespace std;
int i,j,k,n,m,te,test;
int64 P,Q,A,h[50];
int main() {
	freopen("fat.in","r",stdin);
	freopen("fat.out","w",stdout);
	scanf("%d",&test);
	h[0]=1; For(i,1,40) h[i]=h[i-1]*2;
	For(te,1,test) {
		scanf("%lld/%lld\n",&P,&Q);
		int64 A=__gcd(P,Q);
		P/=A; Q/=A;
		for (;;) {
			For(i,1,40) if (Q==h[i]) break;
			if (i>40) {
				if (Q>h[40]) {
					printf("Case #%d: impossible\n",te);
					goto yy1;
				}
				Q<<=1;
			} else break;
		}
		for (;P>1;P/=2) i--;
		printf("Case #%d: %d\n",te,i);
		yy1:;
	}
	return 0;
}

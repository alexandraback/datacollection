#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

ll P,Q,G;

void doit()
{
	scanf("%lld/%lld",&P,&Q),G=__gcd(P,Q),P/=G,Q/=G;
	if ((Q&-Q)!=Q) {puts("impossible"); return;}
	ll x=1;
	for (;P; P>>=1,x<<=1);
	Q/=x;
	int ans=0;
	for (;Q; Q>>=1) ans++;
	printf("%d\n",ans);
}

int main()
{
	int T;
	freopen("A.in","r",stdin);
	freopen("aa.out","w",stdout);
	scanf("%d",&T);
	for (int i=1; i<=T; i++) printf("Case #%d: ",i),doit();
	return 0;
}


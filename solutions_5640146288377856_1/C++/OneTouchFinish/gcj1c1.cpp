#include<bits/stdc++.h>
#define rep(i,s,n) for((i)=(s);(i)<=(n);(i)++)
#define getint(x) scanf("%d",&x)
#define getlong(x) scanf("%lld",&x)
#define putint(x) printf("%d",x)
#define putintln(x) printf("%d\n",x)
#define putlong(x) printf("%lld",x)
#define putlongln(x) printf("%lld\n",x)
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
int main()
{
	int t,ind,r,c,w;
	getint(t);
	rep(ind,1,t)
	{
		getint(r);
		getint(c);
		getint(w);
		int ans=(c-1)/w+w;
		int lx=2*w-1;
		int dr=c/lx;
		dr=max(dr,1);
		ans=ans+(r-1)*dr;
		printf("Case #%d: %d\n",ind,ans);
	}
}
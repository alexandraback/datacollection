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
	int t,d,i,j,ind;
	getint(t);
	int p[1005];
	rep(ind,1,t)
	{
		printf("Case #%d: ", ind);
		getint(d);
		int maxval=0;
		rep(i,0,d-1)
		{
			getint(p[i]);
			if(p[i]>maxval)
				maxval=p[i];
		}
		int minval=maxval;
		rep(i,1,maxval)
		{
			int cr=i;
			rep(j,0,d-1)
				cr=cr+(p[j]-1)/i;
			if(cr<minval)
				minval=cr;
		}
		putintln(minval);	
	}
}
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
const int V=100100;
double p[V],cr[V];
int ca,_,i,n,m;
int main()
{
	freopen("Al.in","r",stdin);
	freopen("A.out","w",stdout);
	scanf("%d",&_);
	for(ca=1;ca<=_;ca++)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)
		scanf("%lf",&p[i]);
		cr[0]=1.0;
		for(i=0;i<n;i++)
		cr[i+1]=cr[i]*p[i];
		double ret=2.0+m;
		for(i=0;i<=n;i++)
		{
			ret=min(ret,cr[i]*(m-i+n-i+1.0)+(1.0-cr[i])*(2*m-i+n-i+2.0));
		//	printf("%d %d %d\n",i,m-i+n-i+1,2*m-i+n-i+2);
		}
		printf("Case #%d: %.6f\n",ca,ret);
	}
}

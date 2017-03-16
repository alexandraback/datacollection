#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
double a[100005],c[100005];
int main()
{
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	int t,n,m,Case=0; scanf("%d",&t);
	while (t--){
		scanf("%d%d",&n,&m); double ans=m+2;
		for (int i=1;i<=n;i++) scanf("%lf",&a[i]);
		c[0]=1; for (int i=1;i<=n;i++) c[i]=c[i-1]*a[i];
		double res=c[n]*(m-n+1)+(1-c[n])*(m-n+2+m); ans=min(ans,res);
		for (int i=1;i<=n;i++)
			res=c[n-i]*(i+i+m-n+1)+(1-c[n-i])*(i+i+m-n+m+2),ans=min(ans,res);
		printf("Case #%d: %lf\n",++Case,ans);
		}
	return 0;
}

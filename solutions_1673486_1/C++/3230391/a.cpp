# include <cstring>
# include <cstdlib>
# include <cstdio>
# include <iostream>
using namespace std;
# define N 100500
double p[N],a[N],b[N];
int main (void)
{
	int t,ys=0;
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	cin>>t;
	while (t--)
	{
		int n,m;
		cin>>m>>n;
		for (int i=1;i<=m;i++)
			scanf("%lf",&p[i]);
		a[0]=1;
		b[0]=0;
		for (int i=1;i<=m;i++)
		{
			a[i]=a[i-1]*p[i];
			b[i]=1-a[i];
		}

		double ans=(double)(2+n),now;
		now=a[m]*(n-m+1)+(1-a[m])*(n-m+2+n);
		ans=min(ans,now);
		for (int i=1;i<=m;i++)
		{
			int va=m-i+1;
			now=(va+1+n-i+1)*a[i-1]+(va+n-i+1+2+n)*b[i-1];
			ans=min(ans,now);
		}
		printf("Case #%d: ",++ys);
		printf("%.6f\n",ans);
	}
	return 0;
}

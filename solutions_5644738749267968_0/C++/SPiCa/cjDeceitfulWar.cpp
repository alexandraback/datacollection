#include <cstdio>
#include <algorithm>
int CAS,cas,l,r,i,tag,v[1011],n,ans,t,j;
double a[1011],b[1011];

int main()
{
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	scanf("%d",&CAS);
	for (cas=1; cas<=CAS; ++cas)
	{
		scanf("%d",&n);
		for (i=1; i<=n; ++i) scanf("%lf",&a[i]);
		for (i=1; i<=n; ++i) scanf("%lf",&b[i]);
		std::sort(a+1,a+n+1);
		std::sort(b+1,b+n+1);
		l=1; r=n;
		ans=0;
		for (i=1; i<=n; ++i)
		if (a[i]<b[l]) --r; else ++l,++ans;
		printf("Case #%d: %d ",cas,ans);
		ans=0;
		++tag;
		for (i=n; i>=1; --i)
		{
			t=-1;
			for (j=n; j>=1; --j)
			if (v[j]!=tag && b[j]>a[i]) t=j;
			if (t==-1)
			{
				for (j=1; j<=n; ++j)
				if (v[j]!=tag)
				{
					v[j]=tag;
					break;
				}
				++ans;
			} else v[t]=tag;
		}
		printf("%d\n",ans);
	}
	return 0;
}

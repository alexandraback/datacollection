#include<cstdio>
#include<algorithm>
using namespace std;
int T,n,m,ans,x,a[111];

int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d",&T);
	for (int tt=1; tt<=T; tt++)
	{
		scanf("%d%d",&m,&n);
		for (int i=0; i<n; i++)
			scanf("%d",&a[i]);
		sort(a,a+n);
		ans=n; x=0;
		for (int i=0; i<n; i++)
		{
			if (m>a[i])
				m+=a[i];
			else
			{
				for (;m<=a[i] && x<=111; m+=(m-1),x++);
				if (m>a[i])
					m+=a[i];
			}
			ans=min(ans,x+(n-i-1));
		}
		printf("Case #%d: %d\n",tt,ans);
	}
	return 0;
}

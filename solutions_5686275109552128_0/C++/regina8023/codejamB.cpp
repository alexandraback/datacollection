#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
using namespace std;
int T,n,a[1005];
int main()
{
	//freopen("t.in","r",stdin);freopen("t.out","w",stdout);
    scanf("%d",&T);
	for (int t=1;t<=T;t++)
	{
		printf("Case #%d: ",t);
		scanf("%d",&n);
		int ma=0;
		for (int i=1;i<=n;i++)
			scanf("%d",&a[i]),ma=max(ma,a[i]);
		int ans=ma;
		for (int i=1;i<=ma;i++)
		{
			int now=i;
			for (int j=1;j<=n;j++)
				if (a[j]>i)
					now=now+(a[j]/i)-(a[j]%i==0);
			ans=min(ans,now);
		}
		printf("%d\n",ans);
	}
	return 0;
}

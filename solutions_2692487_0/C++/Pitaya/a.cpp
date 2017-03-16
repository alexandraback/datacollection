#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int T;
	scanf("%d", &T);
	for (int ii = 1; ii <= T; ++ii)
	{
		int n,o;
		int a[1000];
		memset(a,0,sizeof(a));
		scanf("%d%d", &o,&n);
		int ans=100000,tans=0;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d",&a[i]);
		}
		sort(&a[0],&a[n]);
		int pos=0;
		while(pos<n)
		{
			int sum=0;
			for (;pos < n; ++pos)
			{
				if(a[pos]>=o)break;
				else sum+=a[pos];
			}
			if(sum==0)
			{
				ans=min(ans,tans+n-pos);
				if(o==1)break;
				tans++;
				o=o+o-1;
			}
			else
				o+=sum;
			//printf("%d %d %d\n", o, tans, ans);
		}
		if(o!=1)ans=min(ans,tans);
		printf("Case #%d: %d\n", ii, ans);
	}
	return 0;
}
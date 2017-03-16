#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
const int N=10012;
int t,ans,now,k,n;
int a[N];
int main()
{
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%d",&t);
	for(int o=1;o<=t;++o)
	{
		scanf("%d%d",&k,&n);
		for(int i=1;i<=n;++i)
			scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		int j;
		for(j=1;j<=n;++j)
		if (a[j]<k) k+=a[j];
		else break;
		printf("Case #%d: ",o);
		if (k==1) printf("%d\n",n);
		else
		{
			now=0;
			ans=(n-j)+1;
			while (j<=n)
			{
				++now;
				k=k*2-1;
				while(a[j]<k && j<=n) k+=a[j],++j;
				ans=min(ans,now+(n-j)+1);
			}
			printf("%d\n",ans);
		}
	}
}
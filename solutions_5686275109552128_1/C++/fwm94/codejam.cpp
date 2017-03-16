#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <iostream>
#define maxn 1009
#define maxm
using namespace std;
int a[maxn];
int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	int tt,n,cot=1;
	scanf("%d",&tt);
	while(tt--)
	{
		int mx=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			mx=max(mx,a[i]);
		}
		int ans=mx;
		for(int i=1;i<=mx;i++)
		{
			int tot=0;
			for(int j=0;j<n;j++)
			{
				if(a[j]<=i)
					continue;
				int num=(a[j]+i-1)/i;
				tot=tot+num-1;
			}
			ans=min(ans,tot+i);
		}
		printf("Case #%d: %d\n",cot++,ans);
	}
	//system("pause");
	return 0;
}

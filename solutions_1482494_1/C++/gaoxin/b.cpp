#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

#define debug(x) cout << #x << "=" << x << endl

int tests,test,n,a[1100],b[1100],c[1100],x,ans;


int main()
{
	freopen("b2.in","r",stdin);
	freopen("b2.out","w",stdout);
	scanf("%d",&tests);
	for (test=1;test<=tests;test++)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
		{
			scanf("%d%d",a+i,b+i);
		}
		memset(c,0,sizeof c);
		for (int i=1;i<n;i++) for (int j=i+1;j<=n;j++)
			if (b[i]>b[j])
			{
				swap(b[i],b[j]);
				swap(a[i],a[j]);
			}
		x = 0;
		ans = 0;
		while (x<n*2)
		{
			int findit = 0;
			for (int i=1;i<=n;i++) if (c[i]<2 && x>=b[i])
			{
				if (c[i]==0)
				{
				//debug(i);
					c[i] = 2;
					x += 2;
					ans++;
					findit = 1;
					break;
				}
				else if (c[i]==1)
				{
				//debug(i);
					c[i] = 2;
					x += 1;
					ans++;
					findit = 1;
					break;
				}
			}
			if (!findit)
			for (int i=n;i;i--) if (c[i]==0 && x>=a[i])
			{
				//debug(i);
				c[i] = 1;
				x += 1;
				ans++;
				findit = 1;
				break;
			}
			if (findit==0) break;
		}
		if (x==n*2)
			printf("Case #%d: %d\n",test,ans);
		else printf("Case #%d: Too Bad\n",test);
	}
	return 0;
}

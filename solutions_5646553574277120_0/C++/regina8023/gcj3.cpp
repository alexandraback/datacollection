#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int T,c,d,m,tot,a[100],v[100],h[1000];
void dfs(int x,int now)
{
	if (x==d+1)
	{
		if (!h[now]&&now<=m) tot++,h[now]=1;
		return;
	}
	dfs(x+1,now);
	dfs(x+1,now+a[x]);
}
int main()
{
	freopen("t.in","r",stdin),freopen("t.out","w",stdout);
	cin>>T;
	for (int t=1;t<=T;t++)
	{
		printf("Case #%d: ",t);
		scanf("%d%d%d",&c,&d,&m);
		h[0]=1;
		for (int i=1;i<=m;i++)
			v[i]=h[i]=0;
		for (int i=1;i<=d;i++)
		{
			scanf("%d",&a[i]);
			v[a[i]]=1;
		}
		tot=0;
		dfs(1,0);
		if (tot==m)
		{
			cout<<0<<endl;
			continue;
		}
		int ans=0;
		for (int i=1;i<=m;i++)
		{
			if (tot==m) break;
			if (!v[i])
			{
				v[i]=1;
				for (int j=m;j>=0;j--)
					if (h[j]&&j+i<=m&&!h[j+i])
					{
						h[j+i]=1;
						tot++;
					}
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

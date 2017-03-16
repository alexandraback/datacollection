# include <cstring>
# include <cstdlib>
# include <cstdio>
# include <iostream>
using namespace std;
# define N 1050
int a[N],b[N],vis[N],vis1[N];
int main (void)
{
	int t,n,ys=0;
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	cin>>t;
	while (t--)
	{
		cin>>n;
		for (int i=1;i<=n;i++)
			scanf("%d%d",&a[i],&b[i]);
		int tot=0,now=0,ans=0;
		memset(vis,0,sizeof(vis));
		memset(vis1,0,sizeof(vis1));
		while (tot<n)
		{
			int x=0;
			for (int i=1;i<=n;i++)
				if (now>=b[i] && !vis[i])
				{
					x=i;
					break;
				}
			if (x)
			{
				ans+=1;
				if (vis1[x])
					now+=1;
				else now+=2;
				vis[x]=1;
				tot++;
			}
			else
			{
				int max=-1;
				for (int i=1;i<=n;i++)
					if (!vis[i] && !vis1[i] && now>=a[i] && max<b[i])
					{
						max=b[i];
						x=i;
					}
				if (x)
				{
					ans+=1;
					vis1[x]=1;
					now++;
				}
				else break;
			}
		}
		printf("Case #%d: ",++ys);
		if (tot<n)
			cout<<"Too Bad"<<endl;
		else cout<<ans<<endl;
	}
	
	return 0;
}

#define N (1<<5)
#include <bits/stdc++.h>
using namespace std;

bool vis[N];
int T,n,cas,a[N],p[N],f[N][N];

int main()
{
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	for(cin>>T;T--;)
	{
		cin>>n;
		int res=1;
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++)
			scanf("%d",a+i);
		for(int i=1;i<=n;i++)
		{
			memset(vis,0,sizeof(vis));

			int cnt=0,j=i;
			for(;!vis[j];j=a[j])
				vis[j]=1,p[cnt++]=j;
			if(j==i)
				res=max(res,cnt);
			if(j==p[cnt-2])
				f[j][a[j]]=max(f[j][a[j]],cnt);
		}
		int sum=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				sum+=max(f[i][j]+f[j][i]-2,0);
		printf("Case #%d: %d\n",++cas,max(res,sum));
	}
	return 0;
}

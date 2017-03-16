#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int e,r,n,f[100][100],v[100];
int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	int tt,ans;
	scanf("%d",&tt);
	for(int T=1;T<=tt;T++)
	{
		ans=0;
		memset(f,0x80,sizeof(f));
		scanf("%d%d%d",&e,&r,&n);
		f[0][e]=0;
		for(int i=1;i<=n;i++)scanf("%d",&v[i]);
		for(int i=0;i<=n;i++)
			for(int j=0;j<=e;j++)
				if(f[i][j]!=(int)0x80808080)
				for(int k=0;k<=j;k++)
				{
					f[i+1][min(e,j-k+r)]=max(f[i+1][min(e,j-k+r)],f[i][j]+k*v[i]);
				}
		for(int i=0;i<=e;i++)ans=max(ans,f[n][i]+v[n]*i);
		printf("Case #%d: %d\n",T,ans);
	}
}

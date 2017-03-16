#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;
const int N=100;
int v[N],f[N][N];

int main()
{
	int o,e,r,n,i,j,x,k,cas=0;
	scanf("%d",&o);
	while (o--)
	{
		scanf("%d%d%d",&e,&r,&n);
		for (i=1; i<=n; i++) scanf("%d",&v[i]);
		memset(f,-1,sizeof(f));
		f[0][max(0,e-r)]=0;
		for (i=0; i<n; i++)
		 for (j=0; j<=e; j++)
		 if (f[i][j]!=-1)
		 {
		 	x=min(j+r,e);
		 	for (k=0; k<=x; k++)
		 	 f[i+1][x-k]=max(f[i+1][x-k],f[i][j]+k*v[i+1]);
		 }
		int ans=-1;
		for (j=0; j<=e; j++) ans=max(ans,f[n][j]);
		printf("Case #%d: %d\n",++cas,ans);
	}
}

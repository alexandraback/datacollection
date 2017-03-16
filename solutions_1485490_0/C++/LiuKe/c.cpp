#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
int T;
long long anum[111],at[111],bnum[111],bt[111],sb[111][111],sa[111][111],f[111][111];

void init()
{
	cin>>n>>m;
	
	memset(sa,0,sizeof(sa));
	for (int i=1;i<=n;i++)
	{
		cin>>anum[i]>>at[i];
		sa[i][at[i]]+=anum[i];
	}

	for(int i=2;i<=n;i++)
		for (int j=1;j<=100;j++)
			sa[i][j]+=sa[i-1][j];

	memset(sb,0,sizeof(sb));
	for (int i=1;i<=m;i++)
	{
		cin>>bnum[i]>>bt[i];
		sb[i][bt[i]]+=bnum[i];
	}

	for (int i=2;i<=m;i++)
		for (int j=1;j<=100;j++)
			sb[i][j]+=sb[i-1][j];
}

void dp()
{
	memset(f,0,sizeof(f));
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			f[i][j]=f[i-1][j];
			for (int l=1;l<=i;l++)
				if (at[i]==at[l])
					for (int k=0;k<j;k++)
						f[i][j]=max(f[i][j],f[l-1][k]+min(sa[i][at[i]]-sa[l-1][at[i]],sb[j][at[i]]-sb[k][at[i]]));
		}
}

int main()
{
	scanf("%d",&T);
	for (int t=1;t<=T;t++)
	{
		init();
		dp();
		long long ans=0;
		for (int i=1;i<=m;i++)
			ans=max(ans,f[n][i]);
		//cout<<f[1][1]<<" "<<f[2][2]<<" "<<f[2][4]<<" "<<f[3][5]<<endl;
		printf("Case #%d: ",t);	cout<<ans<<endl;
	}
	return 0;
}
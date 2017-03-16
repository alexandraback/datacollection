#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#define maxn 55
using namespace std;
int a[maxn][maxn];
int b[maxn*2][maxn];
int c[2][maxn];
bool used[maxn*2],sure[maxn];
int n;
bool Check(int x)
{
	bool f=false;
	for(int i=1;i<=n;++i)
		if(sure[i]&&b[c[0][x]][i]!=b[c[1][x]][i])
		{
			f=true;
			if(a[x][i]!=b[c[0][x]][i]) swap(c[0][x],c[1][x]);
			for(int j=1;j<=n;++j)
			{
				a[x][j]=b[c[0][x]][j];
				a[j][x]=b[c[1][x]][j];
			}
			break;
		}
	return f;
}
int main()
{
	int T;
	cin>>T;
	for(int ii=1;ii<=T;++ii)
	{
		scanf("%d",&n);
		for(int i=1;i<=2*n-1;++i)
			for(int j=1;j<=n;++j)
				scanf("%d",b[i]+j);
		printf("Case #%d: ",ii);
		int unsure=0;
		for(int i=1;i<=n;++i)
		{
			int Min=200000,sum;
			for(int j=1;j<=2*n-1;++j)
				if(!used[j])
				{
					if(b[j][i]<Min)
					{
						Min=b[j][i];
						c[0][i]=j;
						c[1][i]=0;
					}
					else if(b[j][i]==Min)
						c[1][i]=j;
				}
			if(!c[1][i]) unsure=i;
			used[c[0][i]]=used[c[1][i]]=true;
		}
		for(int i=1;i<n;++i)
		{
			bool flag=false;
			for(int j=1;j<=n;++j)
				if(j!=unsure&&!sure[j]&&Check(j))
				{
					flag=true;
					sure[j]=true;
					break;
				}
			if(!flag)
			{
				for(int x=1;x<=n;++x)
					if(x!=unsure&&!sure[x])
					{
						sure[x]=true;
						for(int j=1;j<=n;++j)
						{
							a[x][j]=b[c[0][x]][j];
							a[j][x]=b[c[1][x]][j];
						}
						break;
					}
			}
		}
		bool flag=false;
		for(int i=1;i<=n;++i)
			if(i!=unsure&&a[unsure][i]!=b[c[0][unsure]][i])
			{
				flag=true;
				break;
			}
		if(1==unsure)
			printf("%d",b[c[0][unsure]][1]);
		else if(flag) printf("%d",a[unsure][1]);
		else printf("%d",a[1][unsure]);
		for(int i=2;i<=n;++i)
		{
			if(i==unsure)
				printf(" %d",b[c[0][unsure]][i]);
			else if(flag) printf(" %d",a[unsure][i]);
			else printf(" %d",a[i][unsure]);
		}
		printf("\n");
		memset(used,0,sizeof used);
		memset(sure,0,sizeof sure);
		memset(c,0,sizeof c);
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
	}
	return 0;
}
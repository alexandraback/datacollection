#include<stdio.h>
#include<algorithm>

using namespace std;

struct dat
{
	int zip;
	int pos;
};

bool operator < (dat a, dat b)
{
	return a.zip<b.zip;
}

dat a[51];
bool u[51][51];
bool use[51];
int cur[51];
bool can[51];
bool curcan[51];
int f[51];

int find(int x)
{
	if (f[x]==x) return x;
	else
	{
		f[x]=find(f[x]);
		return f[x];
	}
}

int main()
{
	int t,p;
	int n,m;
	int i,j,k,r,q;
	int b,c;
	int l;
	freopen("C-large.in","r",stdin);
	freopen("C-large.out","w",stdout);
	scanf("%d",&t);
	for (p=1;p<=t;p++)
	{
		scanf("%d%d",&n,&m);
		for (i=1;i<=n;i++)
		{
			scanf("%d",&a[i].zip);
			a[i].pos=i;
		}		
		memset(u,false,sizeof(u));
		for (i=1;i<=m;i++)
		{
			scanf("%d%d",&b,&c);
			u[b][c]=true;
			u[c][b]=true;
		}
		sort(a+1,a+n+1);
		printf("Case #%d: ",p);
		printf("%d",a[1].zip);
		l=1;
		cur[1]=a[1].pos;
		memset(use,true,sizeof(use));
		use[1]=false;
		memset(can,true,sizeof(can));
		for (i=2;i<=n;i++)
		{
			for (j=1;j<=n;j++)
				if (use[j])
				{
					for (k=l;k>=1;k--)
						if (u[cur[k]][a[j].pos]) break;
					if (k>=1)
					{
						for (r=1;r<=n;r++)
							curcan[r]=can[r];
						for (r=k+1;r<=l;r++)
							curcan[cur[r]]=false;
						for (r=1;r<=n;r++)
							if (!curcan[r]) f[r]=a[1].pos;
							else f[r]=r;
						for (r=1;r<=n;r++)
							if (curcan[r])
							{
								for (q=1;q<=n;q++)
									if (curcan[q]&&u[r][q])
									{
										int rr=find(r);
										int qq=find(q);
										if (rr!=qq) f[rr]=qq;
									}
							}
						int tt=find(a[1].pos);
						for (r=1;r<=n;r++)
							if (find(r)!=tt) break;
						if (r==n+1) break;
					}
				}
			printf("%d",a[j].zip);
			use[j]=false;
			for (r=k+1;r<=l;r++)
				can[cur[r]]=false;
			l=k+1;
			cur[l]=a[j].pos;
		}
		printf("\n");
	}
	return 0;
}




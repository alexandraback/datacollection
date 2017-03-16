#include<cstdio>
#include<cstring>
int T,a[111][111],u[111],v[111],n,m;
bool ok;

int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%d",&T);
	for (int tt=1; tt<=T; tt++)
	{
		printf("Case #%d: ",tt);
		scanf("%d%d",&n,&m);
		for (int i=1; i<=n; i++)
			for (int j=1; j<=m; j++)
				scanf("%d",&a[i][j]);
		ok=true;
		for (int x=1; x<=100; x++)
		{
			memset(u,0,sizeof u);
			memset(v,0,sizeof v);
			for (int i=1; i<=n; i++)
				for (int j=1; j<=m; j++)
					u[i]+=(a[i][j]<=x),v[j]+=(a[i][j]<=x);
			for (int i=1; i<=n; i++)
				for (int j=1; j<=m; j++)
					if (a[i][j]<=x && u[i]!=m && v[j]!=n)
						ok=false;
			if (!ok)
				break;
		}
		if (ok)
			printf("YES\n");
		else
			printf("NO\n");
	}
}
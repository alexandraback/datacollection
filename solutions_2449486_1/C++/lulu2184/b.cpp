#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m,a[110][110],T;
bool flag;

int main()
{
	freopen("b.in","r",stdin);
	
	scanf("%d",&T);
	int TT=0;
	while (T--)
	{
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++) 
			{
				scanf("%d",&a[i][j]);
			}
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=m;j++)
			{
				flag=true;
				for (int k=1;k<=n;k++)
				{
					if (a[k][j]>a[i][j]) { flag=false;break; }
				}
				if (!flag)
				{
					flag=true;
					for (int k=1;k<=m;k++)
						if (a[i][k]>a[i][j]) { flag=false;break; }
				}
				if (!flag) break;
			}
			if (!flag) break;
		}
		printf("Case #%d: ",++TT);
		if (flag) printf("YES\n");
		else printf("NO\n");
	}
		
	return 0;
}
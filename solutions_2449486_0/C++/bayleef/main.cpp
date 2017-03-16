#include <stdio.h>
#include <algorithm>

using namespace std;

int n,m,i,j,T,ok,a[200][200],x[200],y[200],ts;

int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)
			x[i]=0;
		for(j=0;j<m;j++)
			y[j]=0;
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
			{
				scanf("%d",&a[i][j]);
				x[i]=max(x[i],a[i][j]);
				y[j]=max(y[j],a[i][j]);
			}
		ok=0;
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				if(a[i][j]!=min(x[i],y[j]))
					ok=1;
		printf("Case #%d: %s\n",++ts,ok?"NO":"YES");
	}
	return 0;
}
#include <stdio.h>
#include <algorithm>
using namespace std;

const int mx=110;

struct X
{
	int x,y;
	int h;
};

int n,m,p;
X a[mx*mx];
int hx[mx],hy[mx];

bool cmp(X a,X b)
{
	return a.h > b.h;
}

int main()
{
	int T,ca=1;
	scanf("%d",&T);
	while(T--)
	{
		int i,j;
		p = 0;
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				a[p].x = i;
				a[p].y = j;
				scanf("%d",&a[p].h);
				p++;
			}
		}
		memset(hx,0,sizeof(hx));
		memset(hy,0,sizeof(hy));
		sort(a,a+p,cmp);
		bool can = true;
		for(i=0;i<p;)
		{
			for(j=i;j<p;j++)
			{
				if( a[j].h != a[i].h ) break;
				//printf("%d %d %d %d %d %d %d\n",i,j,a[j].x,a[j].y,a[j].h,hx[a[j].x],hy[a[j].y]);
				bool canx = ( 0 == hx[a[j].x] || hx[a[j].x] == a[j].h );
				bool cany = ( 0 == hy[a[j].y] || hy[a[j].y] == a[j].h );
				hx[a[j].x] = hx[a[j].x]>0 ? hx[a[j].x] : a[j].h;
				hy[a[j].y] = hy[a[j].y]>0 ? hy[a[j].y] : a[j].h;
				can = canx || cany;
				if(!can) break;
			}
			if(!can) break;
			i = j;
		}
		printf("Case #%d: %s\n",ca++,(can?"YES":"NO"));
	}
	return 0;
}


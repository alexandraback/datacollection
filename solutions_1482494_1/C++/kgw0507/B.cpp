#include <stdio.h>
#include <algorithm>
using namespace std;

const int N=1010;
struct Level
{
	int a,b,s;
	bool friend operator<(const Level &p,const Level &q)
	{
		return (p.b>q.b);
	}
};
int TC,tc,n;
Level x[N+1];
int t,s[N+1],r,t0;

int main()
{
	int i;
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);
	for(scanf("%d",&TC),tc=1;tc<=TC;++tc)
	{
		r=0; t=0;
		for(scanf("%d",&n),i=1;i<=n;++i)
		{
			scanf("%d%d",&x[i].a,&x[i].b);
			x[i].s=0;
		}
		sort(x+1,x+n+1);
		for(;;)
		{
			t0=t;
			for(i=1;i<=n;++i)
				if(x[i].s<2 && t>=x[i].b)
				{
					t+=2-x[i].s; ++r; x[i].s=2;
				}
			if(t>t0) continue;
			for(i=1;i<=n;++i)
				if(x[i].s==0 && t>=x[i].a)
				{
					t+=1; ++r; x[i].s=1;
					break;
				}
			if(t==t0) break;
		}
		printf("Case #%d: ",tc);
		if(t<2*n) printf("Too Bad\n");
		else printf("%d\n",r);
	}
}
#include <cstdio>
#include <algorithm>
using namespace std;

int q,t,n,sum,ans,i,j,k,l;
struct f
{
	int a,b,y;
}g[1002],h[1002];

int cmp1(const f &c,const f &d)
{
	if(c.a<d.a)return 1;	if(c.a>d.a)return 0;
	if(c.b>d.b)return 1;	return 0;
}
int cmp2(const f &c,const f &d)
{
	if(c.b<d.b)return 1;	if(c.b>d.b)return 0;
	if(c.a<d.a)return 1;	return 0;
}

int main ()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%d",&t);
	for(q=1;q<=t;q++)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&g[i].a,&g[i].b);
			g[i].y=1;
			h[i]=g[i];
			h[i].y=2;
		}
		sort(g,g+n,cmp1);	sort(h,h+n,cmp2);
		if(g[0].a>0)
		{
			printf("Case #%d: Too Bad\n",q);
			continue;
		}
		i=sum=ans=0;
		int flag=1;
		while(i<n)
		{
			if(h[i].b<=sum)
			{
				ans++;
				sum+=h[i].y;
				h[i].y=0;
				i++;
			}
			else
			{
				int maxx=0;
				for(j=0;j<n;j++)
					if(g[j].a<=sum && g[j].y>0)
					if(maxx<g[j].b)
					{
						maxx=g[j].b;
						k=j;
					}
				if(maxx==0)
				{
					flag=0;
					break;
				}
				sum+=1;
				ans++;
				g[k].y=0;
				for(l=0;l<n;l++)
				if(g[k].a==h[l].a && g[k].b==h[l].b && h[l].y==2)
				{
					h[l].y=1;
					break;
				}
			}
		}
		if(flag)printf("Case #%d: %d\n",q,ans);
		else printf("Case #%d: Too Bad\n",q);
	}
	
	return 0;
}


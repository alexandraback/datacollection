#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;

struct node
{
	int a,b,k;
}x[N];
bool cmp(const node &a,const node b)
{
	return a.b>b.b;
}
int main(void)
{
	int t,n;
	scanf("%d",&t);
	for(int cas=1;cas<=t;cas++)
	{
		scanf("%d",&n);
		memset(x,0,sizeof(x));
		for(int i=1;i<=n;i++)	scanf("%d%d",&x[i].a,&x[i].b);
		int cur=0,stp=0,pre=0;
		while(1)
		{
			pre=cur;
			sort(x+1,x+n+1,cmp);
			int p=0;
			for(int i=1;i<=n;i++)
				if(x[i].k==0 && x[i].b<=cur)
				{
					p=i;
					x[p].k=2;
					cur+=2;
					stp++;
				}
			if(p)	continue;
			p=0;
			for(int i=1;i<=n;i++)
				if(x[i].k==1 && x[i].b<=cur)
				{
					p=i;
					x[p].k=2;
					cur++;
					stp++;
				}
			if(p)	continue;
			p=0;
			for(int i=1;i<=n;i++)
				if(x[i].k==0 && x[i].a<=cur)
				{
					if(p==0 || x[p].b<x[i].b)	p=i;
				}
			if(p)
			{
				x[p].k=1;
				cur++;
				stp++;
			}
			if(cur==(n<<1) || cur==pre)	break;
		}
		printf("Case #%d: ",cas);
		if(cur!=(n<<1))	puts("Too Bad");
		else	printf("%d\n",stp);
	}
	return 0;
}

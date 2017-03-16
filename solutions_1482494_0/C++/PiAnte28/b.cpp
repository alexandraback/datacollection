#include<cmath>
#include<cstring>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn=1005;
int rec[maxn],req[maxn][2],pd[maxn];
int n,tt,hehe,ans(0),now(0);

int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%d\n",&tt);hehe=tt;
	while (tt--)
	{
		ans=now=0;
		memset(pd,0,sizeof(pd));
		scanf("%d\n",&n);
		int jl(0),maxx(-1),cj(0);
		for (int i=1;i<=n;i++)
		{
			scanf("%d%d\n",&req[i][0],&req[i][1]);
		}
		bool flag(false);
		while (now!=n*2)
		{
			maxx=0;jl=0;cj=0;
			for (int i=1;i<=n;i++)
			if (pd[i]!=2)
			{
				if (pd[i]==0 && req[i][1]<=now)
				{maxx=2;jl=i;cj=req[i][1]-now;break;}
				if (pd[i]==0 && maxx<1 && req[i][0]<=now)
				{maxx=1;jl=i;cj=req[i][1]-now;}
				if (pd[i]==1 && maxx<1 && req[i][1]<=now)
				{maxx=1;jl=i;cj=req[i][1]-now;}
				if (jl!=0 && maxx==1)
				if (pd[i]==0 && maxx==1 && req[i][0]<=now && req[i][1]-now>cj && pd[jl]==0)
				{maxx=1;jl=i;cj=req[i][1]-now;}  //qiang
			}
			if (maxx==0) {flag=true;break;}
			pd[jl]+=maxx;
			ans++;
			now+=maxx;
		}
		if (flag) printf("Case #%d: Too Bad\n",hehe-tt);
		else printf("Case #%d: %d\n",hehe-tt,ans);
	}
	return 0;
}

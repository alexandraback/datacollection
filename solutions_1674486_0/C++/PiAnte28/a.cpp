#include<cmath>
#include<cstring>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn=1000*10+5;
const int maxnn=1005;

int sta[maxn],pd[maxnn];
int rec[maxn][15];
int tt,hehe,n;

int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d\n",&tt);hehe=tt;
	while (tt--)
	{
		scanf("%d\n",&n);
		for (int i=1;i<=n;i++)
		{
			scanf("%d\n",&rec[i][0]);
			for (int j=1;j<=rec[i][0];j++)
			{
				scanf("%d\n",&rec[i][j]);
			}
		}
		memset(pd,0,sizeof(pd));
		int poi(1),head(1),toil(0);
		int jl[maxnn];
		bool flag(false);
		while (poi<=n)
		{
			if (pd[poi]) {poi++;continue;}
			pd[poi]=1;
			memset(sta,0,sizeof(sta));
			memset(jl,0,sizeof(jl));
			head=1;toil=0;
			for (int i=1;i<=rec[poi][0];i++) {sta[++toil]=rec[poi][i];jl[rec[poi][i]]=1;}
			while (head<=toil)
			{
				int now=sta[head];
				for (int i=1;i<=rec[now][0];i++)
				{
					if (jl[rec[now][i]]) {flag=true;break;}
					if (pd[rec[now][i]]==0) pd[rec[now][i]]=1;
					sta[++toil]=rec[now][i];
					jl[rec[now][i]]=1;
				}
				if (flag) break;
				head++;
			}
			if (flag) break;
		}
		if (flag) printf("Case #%d: Yes\n",hehe-tt);else printf("Case #%d: No\n",hehe-tt);
	}
	return 0;
}

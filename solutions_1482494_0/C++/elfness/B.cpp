#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
const int V=1200;
int st[V],x[V],y[V],n,_,ca,i;
int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	scanf("%d",&_);
	for(ca=1;ca<=_;ca++)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		scanf("%d%d",&x[i],&y[i]);
		memset(st,0,sizeof(st));
		int now=0,ret=0;
		while(1)
		{
			int id=-1;
			for(i=0;i<n;i++)
			if(st[i]!=2&&y[i]<=now)
			{id=i;break;}
			if(id==-1)
			{
				int pos=-1;
				for(i=0;i<n;i++)
				if(st[i]==0&&x[i]<=now&&(pos==-1||y[pos]<y[i]))
				pos=i;
				if(pos==-1)break;
				st[pos]=1;now++;ret++;
			}
			else
			{
				now+=2-st[id];
				st[id]=2;ret++;
			}
		}
		printf("Case #%d: ",ca);
		if(now!=2*n)puts("Too Bad");
		else printf("%d\n",ret);
	}
}

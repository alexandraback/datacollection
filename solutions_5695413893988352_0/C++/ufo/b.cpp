#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
char x[100],y[100];
char in[100];
int lx,ly;
long long ansx,ansy;
long long ans;
long long p10[1000];
long long ab(long long e)
{
	if(e>0)
		return e;
	return -e;
}
void tryy(int now)
{
	int i,j,k;
	long long xx=0,yy=0,xxx,yyy;
	for(i=now+1;i<=lx||i<=ly;++i)
	{
		if(i>lx&&y[i]!='0'&&y[i]!='?')
			return;
		if(i>ly&&x[i]!='0'&&x[i]!='?')
			return;
		if(i<=lx&&i<=ly&&x[i]!=y[i]&&x[i]!='?'&&y[i]!='?')
			return;
	}
	for(i=now+1;i<=lx&&i<=ly;++i)
	{
		if(x[i]=='?'&&y[i]=='?')
			xx+=0;
		else
		if(x[i]!='?')
			xx+=p10[i]*(x[i]-'0');
		else
			xx+=p10[i]*(y[i]-'0');
	}
	yy=xx;
	if(now==0)
	{
		ansx=xx;
		ansy=yy;
		ans=0;
		return;
	}
	for(i=0;i<=9;++i)
		for(j=0;j<=9;++j)
		{
		//	printf("kkkk%d %c %c %d %d %d\n",now,x[now],y[now],i,j,(x[now]=='?'||x[now]-'0'==i)&&(y[now]=='?'||y[now]-'0'==j));
			if(i!=j&&(x[now]=='?'||x[now]-'0'==i||(lx<now&&i==0))&&(y[now]=='?'||y[now]-'0'==j||(ly<now&&j==0)))
			{
			//	printf("%d %d\n",i,j);
				xxx=xx+p10[now]*i;
				yyy=yy+p10[now]*j;
			//	printf("%d %lld %lld\n",now,xxx,yyy);
				if(xxx>yyy)
				{
					for(k=1;k<now;++k)
					{
						if(x[k]=='?')
							xxx+=p10[k]*0;
						else
							xxx+=p10[k]*(x[k]-'0');
						if(y[k]=='?')
							yyy+=p10[k]*9;
						else
							yyy+=p10[k]*(y[k]-'0');
					}
				}
				else
				{
					for(k=1;k<now;++k)
					{
						if(x[k]=='?')
							xxx+=p10[k]*9;
						else
							xxx+=p10[k]*(x[k]-'0');
						if(y[k]=='?')
							yyy+=p10[k]*0;
						else
							yyy+=p10[k]*(y[k]-'0');
					}
					
				}
				if(ab(xxx-yyy)<ans||(ab(xxx-yyy)==ans&&xxx<ansx)||(ab(xxx-yyy)==ans&&xxx==ansx&&yyy<ansy))
				{
					ansx=xxx;
					ansy=yyy;
					ans=ab(xxx-yyy);
				}
			}
		}
}
int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
	int t,tt;
	int i,w;
	p10[1]=1;
	for(i=2;i<=18;++i)
		p10[i]=p10[i-1]*10;
	scanf("%d",&tt);
	for(t=1;t<=tt;++t)
	{
		ans=1e18;
		scanf("%s",in);
		lx=strlen(in);
		for(i=1;i<=lx;++i)
			x[i]=in[lx-i];
		scanf("%s",in);
		ly=strlen(in);
		for(i=1;i<=ly;++i)
			y[i]=in[ly-i];
		w=lx;
		if(w<ly)
			w=ly;
		for(i=w;i>=0;--i)
			tryy(i);
		printf("Case #%d: ",t);
		for(i=lx;i>1&&ansx<p10[i];--i)
			printf("0");
		printf("%lld ",ansx);
		for(i=ly;i>1&&ansy<p10[i];--i)
			printf("0");
		printf("%lld\n",ansy);
	}
	return 0;
}


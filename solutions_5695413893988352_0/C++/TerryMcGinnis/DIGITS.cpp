#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define FILL(a,x) memset(a,x,sizeof(a))
#define foreach( gg,ii ) for( typeof(gg.begin()) ii=gg.begin();ii!=gg.end();ii++)
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define sz(a) int((a).size())
#define N 2010
#define MAX 30
#define mod 1000000007
#define REP(i,a) for(int i=0;i<a;++i)
#define REPP(i,a,b) for(int i=a;i<b;++i)
#define all(a) a.begin(),a.end()
const ll INF = 1e18+1;

inline ll input(void)
{
	char t;
	ll x=0;
	int neg=0;
	t=getchar();
	while((t<48 || t>57) && t!='-')
		t=getchar();
	if(t=='-')
		{neg=1; t=getchar();}
	while(t>=48 && t<=57)
	{
		x=(x<<3)+(x<<1)+t-48;
		t=getchar();
	}
	if (neg) x=-x;
	return x;
}

inline void output(ll x)
{
	char a[20];
	int i=0,j;
	a[0]='0';
	if (x<0) {putchar('-'); x=-x;}
	if (x==0) putchar('0');
	while(x)
	{
		a[i++]=x%10+48;
		x/=10;
	}
	for(j=i-1;j>=0;j--)
	{
		putchar(a[j]);
	}
	putchar('\n');
}

char c[20],j[20];
int cl,jl;

inline int verify(int val, int mode)
{
	int x;
	if (mode==0)
	{
		x=cl;
		if (cl==1&&val>=10||cl==2&&val>=100) return 0;
		while(x--)
		{
			if (c[x]!='?'&&c[x]-'0'!=val%10) return 0;
			val/=10;
		}
	}
	else
	{
		x=jl;
		if (jl==1&&val>=10||jl==2&&val>=100) return 0;
		while(x--)
		{
			if (j[x]!='?'&&j[x]-'0'!=val%10) return 0;
			val/=10;
		}
	}
	return 1;
}

int main()
{
	ll t,n,val[1001],x,y,minv;
	t=input();
	REP(kase,t)
	{
		scanf("%s",c);
		scanf("%s",j);
		cl=strlen(c);
		jl=strlen(j);
		REP(j1,1000) val[j1]=verify(j1,1);
		minv=INF;
		REP(i,1000)
		{
			if (!verify(i,0)) continue;
			REP(j1,1000)
			{
				if (val[j1])
				{
					if (abs(i-j1)<minv)
					{
						x=i;
						y=j1;
						minv=abs(i-j1);
					}
				}
			}
		}
		minv=strlen(c);
		while(minv--)
		{
			c[minv]=x%10+'0';
			x/=10;
		}
		minv=strlen(j);
		while(minv--)
		{
			j[minv]=y%10+'0';
			y/=10;
		}
		printf("Case #%d: %s %s",kase+1,c,j);
		putchar('\n');
	}
return 0;
}

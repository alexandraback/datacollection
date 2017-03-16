#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
struct T
{
	int v,idx,type;
	bool operator <(const T &o)const
	{
		return v<o.v||(v==o.v&&type<o.type);
	}
}x;
priority_queue<T> q;
int ans,cnt,n,s,p,tim;
int sup[108],nsup[108];
bool vis[108];
int v[108];
void Init()
{
	memset(sup,0,sizeof sup);
	memset(nsup,0,sizeof nsup);
	memset(vis,0,sizeof vis);
	scanf("%d%d%d",&n,&s,&p);
	int a,b;
	rep(i,1,n)
	{
		scanf("%d",&v[i]);
		b=v[i]%3;
		if(b==0)
		{
			a=v[i]/3;
			nsup[i]=a;
			if(a)
			{
				a++;
				sup[i]=a;
			}
		}
		else if(b==1)
		{
			a=v[i]/3;a++;
			nsup[i]=sup[i]=a;
		}
		else
		{
			a=v[i]/3;a++;
			nsup[i]=a;
			a++;
			sup[i]=a;
		}
	}
}
void Work()
{
	cnt=ans=0;
	rep(i,1,n)
	{
		if(sup[i]>=p&&nsup[i]<p&&cnt<s)
		{
			cnt++;ans++;
			vis[i]=true;
		}
	}
	rep(i,1,n)if(!vis[i])
	{
		if(nsup[i]>=p)
		{
			ans++;
		}
		else if(sup[i]>=p&&cnt<s)
		{
			ans++;
			cnt++;
		}
	}
}
int main()
{
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	scanf("%d",&tim);
	rep(i,1,tim)
	{
//		scanf("%d%d%d",&n,&)
		Init();
		Work();
		printf("Case #%d: %d\n",i,ans);
	}
}
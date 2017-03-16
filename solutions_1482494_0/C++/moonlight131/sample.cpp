#include<iostream>
#include<cstdio>
#include<vector>
#include<list>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<cmath>

using namespace std;

#define maxn 2100
#define maxm 1100000
#define eps 1e-10
#define inf 1000000000
struct In
{
	int a,b;
}s[maxn],st[maxn],a[maxn];
int ans,top,n;
bool cmp(In a,In b)
{
	return a.a<b.a;
}
void dfs(int x)
{
	In s1;
	int i,now;
	if(x==n+1)
	{
		for(i=0;i<top;i++)
		{
			a[i]=st[i];
		}
		sort(st,st+top,cmp);
		now=0;
		for(i=0;i<top;i++)
		{
			if(now<st[i].a)break;
			now+=st[i].b;
		}
		if(top<ans&&i==top)
		{
			ans=top;
		}
		for(i=0;i<top;i++)
		{
			st[i]=a[i];
		}
		return ;
	}
	dfs(x+1);
	s1.a=s[x].a;
	s1.b=1;
	st[x-1].b=1;
	st[top++]=s1;
	dfs(x+1);
	st[x-1].b=2;
	top--;
}
int main()
{
	In s1;
	int i,j,x,ca,t,temp;
	scanf("%d",&t);
	for(ca=1;ca<=t;ca++)
	{
		printf("Case #%d: ",ca);
		scanf("%d",&n);
		top=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&s[i].a,&s[i].b);
			s1.a=s[i].b;
			s1.b=2;
			st[top++]=s1;
		}
		ans=inf;
		temp=n;
		dfs(1);
		if(ans==inf)
		{
			printf("Too Bad\n");
		}
		else
		{
			printf("%d\n",ans);
		}
	}
}


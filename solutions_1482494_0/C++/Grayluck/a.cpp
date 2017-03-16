#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <set>
#include <ctime>
#include <algorithm>
#define min(a,b)	((a)<(b)?(a):(b))
#define max(a,b)	((a)>(b)?(a):(b))
#define abs(a)	((a)<0?-(a):(a))
#define inf 214748364
#define pi 3.141592653589793
using namespace std;
typedef long long ll;

const int maxn = 10001;
struct tinfo
{
	int a,b,p;
}	g[maxn];
int now;
bool fail;
int tim,n;

bool cmp(const tinfo a,const tinfo b)
{
	return a.b<b.b;
}

bool find()
{
	int res=0,resn=0;
	for(int i=1;i<=n;++i)
	if(!g[i].p && g[i].a<=now)
	{
		if(!res || g[i].b>resn)
			res=i,resn=g[i].b;
	}
	if(res)
	{
		g[res].p=1,now++;
		return 1;
	}
	return 0;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	#endif
	scanf("%d",&tim);
	for(int tt=1;tt<=tim;++tt)
	{
		printf("Case #%d: ",tt);
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
			scanf("%d%d",&g[i].a,&g[i].b),g[i].p=0;
		sort(g+1,g+n+1,cmp);
		now=0;
		fail=0;
		int res=0;
		for(int i=1;i<=n;++i)
		{
			while(g[i].b>now)
			{
				if(!find())
				{
					fail=1;
					break;
				}
				res++;
			}
			if(fail)
				break;
			now+=2-g[i].p;
			g[i].p=2;
			res++;
		}
		if(fail)
			printf("Too Bad\n");else
			printf("%d\n",res);
	}
	return 0;
}


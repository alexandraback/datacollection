#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstring>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

#define SIZE(x) (int((x).size()))
#define rep(i,l,r) for (int i=(l); i<=(r); i++)
#define repd(i,r,l) for (int i=(r); i>=(l); i--)
#define rept(i,c) for (typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)

#ifndef ONLINE_JUDGE
#define debug(x) { cerr<<#x<<" = "<<(x)<<endl; }
#else
#define debug(x) {}
#endif

int multab[4][4]={{1,2,3,4},{2,-1,4,-3},{3,-4,-1,2},{4,3,-2,-1}};

int mul(int x, int y)
{
	int sign;
	if (x*y>0) sign=1; else sign=-1;
	return sign*multab[abs(x)-1][abs(y)-1];
}

int trans(char c)
{
	if (c=='i') return 2;
	if (c=='j') return 3;
	if (c=='k') return 4;
}

int inv(int x)
{
	if (x==1) return 1;
	return -x;
}

int w[1000010], p[1000010];
char s[1000010];

void lemon()
{
	int n; LL m; scanf("%d%lld",&n,&m);
	scanf("%s",s+1);
	if (m>96) m=96+m%4;
	rep(i,1,n) w[i]=trans(s[i]);
	rep(i,n+1,n*m) w[i]=w[i-n];
	p[0]=1; int stage=0;
	rep(i,1,n*m) 
	{
		p[i]=mul(p[i-1],w[i]);
		if (stage==0)
		{
			if (p[i]==2) stage++;
		}
		else  if (stage==1)
		{
			if (p[i]==4) stage++;
		}
		else  if (stage==2 && i==n*m)
		{
			if (p[i]==-1) stage++;
		}
	}
	if (stage==3) printf("YES\n"); else printf("NO\n");
		
}

int main()
{
	ios::sync_with_stdio(true);
	#ifndef ONLINE_JUDGE
		freopen("C.in","r",stdin);
	#endif
	int tcase; scanf("%d",&tcase);
	rep(nowcase,1,tcase)
	{
		printf("Case #%d: ",nowcase);
		lemon();
	}
	return 0;
}


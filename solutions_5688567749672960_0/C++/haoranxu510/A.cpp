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

int dp[1000010];

void lemon()
{
	int x; scanf("%d",&x);
	printf("%d\n",dp[x]);
}

int rev(int x)
{
	int y=0;
	while (x) y=y*10+x%10, x/=10;
	return y;
}

void su(int &a, int b)
{
	a=min(a,b);
}

#define INF 1000000000

void prework()
{
	dp[1]=1; rep(i,2,1000000) dp[i]=INF;
	rep(i,1,1000000)
	{
		su(dp[i+1],dp[i]+1);
		su(dp[rev(i)],dp[i]+1);
	}
}

int main()
{
	ios::sync_with_stdio(true);
	#ifndef ONLINE_JUDGE
		freopen("A.in","r",stdin);
	#endif
	prework();
	int tcase; scanf("%d",&tcase);
	rep(nowcase,1,tcase) 
	{
		printf("Case #%d: ",nowcase);
		lemon();
	}
	return 0;
}


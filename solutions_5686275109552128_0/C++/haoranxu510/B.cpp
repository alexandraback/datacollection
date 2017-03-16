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

int dp[1010][1010];
int a[1010];

void lemon()
{
	int n; scanf("%d",&n);
	rep(i,1,n) scanf("%d",&a[i]);
	int ans=10000;
	rep(i,1,1000)
	{
		int s=0;
		rep(j,1,n) s+=dp[i][a[j]];
		s+=i;
		if (s<ans) ans=s;
	}
	printf("%d\n",ans);
}

void prework()
{
	rep(tar,1,1000)
	{
		dp[tar][tar]=0;
		rep(i,tar+1,1000)
		{
			dp[tar][i]=dp[tar][i-1]+1;
			rep(j,1,i-1)
				dp[tar][i]=min(dp[tar][i],dp[tar][j]+dp[tar][i-j]+1);
		}
	}
}

int main()
{
	ios::sync_with_stdio(true);
	#ifndef ONLINE_JUDGE
		freopen("B.in","r",stdin);
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


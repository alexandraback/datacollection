#include<vector>
#include<list>
#include<map>
#include<set>
#include<deque>
#include<queue>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<iostream>
#include<sstream>
#include<iomanip>
#include<cmath>
#include<cstdlib>
#include<cctype>
#include<string>
#include<cstring>
#include<cstdio>
#include<ctime>
#include<climits>
#include<complex>
#include<cassert>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)((x).size())
#define all(x) x.begin(),x.end()
#define clr(x) memset((x),0,sizeof(x))
#define cdp(x) memset((x),-1,sizeof(x))
#define rep(i,n) for (i=0;i<n;i++)
#define Rep(i,a,b) for (i=a;i<=b;i++)
#define ff(i,x) for (i=start[x];i!=-1;i=a[i].next)
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
using namespace std;
const double eps=1e-8;
const double pi=acos(-1.0);
int dblcmp(double d){if (fabs(d)<eps)return 0;return d>eps?1:-1;}
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef vector<pii> vpi;
int dp[12][12],v[12];
int e,r,n;
int main()
{
	freopen("C:\\Users\\daizhy\\Downloads\\B-small-attempt0 (9).in","r",stdin);
	freopen("C:\\2013¸öÈËÈü\\gcj\\r1\\b1.txt","w",stdout);
	int i,j,k,cas,cc=0;
	scanf("%d",&cas);
	while (cas--)
	{
		scanf("%d%d%d",&e,&r,&n);
		for (i=0;i<n;i++)scanf("%d",v+i);
		memset(dp,200,sizeof(dp));
		dp[0][e]=0;
		for (i=0;i<n;i++)
		{
			for (j=0;j<=e;j++)if (dp[i][j]>=0)
			{
				for (k=0;k<=j;k++)
				{
					dp[i+1][min(j-k+r,e)]=max(dp[i+1][min(j-k+r,e)],dp[i][j]+k*v[i]);
				}
			}
		}
		int ans=0;
		for (i=0;i<=e;i++)ans=max(ans,dp[n][i]);
		printf("Case #%d: %d\n",++cc,ans);
	}
	return 0;
}
		

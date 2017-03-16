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
typedef __int64 ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef vector<pii> vpi;
ll r,t;
int main()
{
	freopen("C:\\Users\\daizhy\\Downloads\\A-large (8).in","r",stdin);
	freopen("C:\\2013¸öÈËÈü\\gcj\\r1\\a1.txt","w",stdout);
	int i,j,k,cas,cc=0;
	scanf("%d",&cas);
	while (cas--)
	{
		scanf("%I64d%I64d",&r,&t);
		ll low=0,high=10000000000000LL,ans,mid;
		while (low<=high)
		{
			mid=(low+high)/2LL;
			ll x=mid;
			ll y=2*mid-1+2*r;
			if (x<=t/y)
			{
				low=mid+1;
				ans=mid;
			}
			else 
			{
				high=mid-1;
			}
		}
		printf("Case #%d: %I64d\n",++cc,ans);
	}
	return 0;
}

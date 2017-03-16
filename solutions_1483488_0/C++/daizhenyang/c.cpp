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
int dig[2222222],p[8];
vi v[2222222];
void init()
{
	int i,j,k,l;
	for (i=1;i<=9;i++)dig[i]=1;
	for (i=10;i<=2000000;i++)dig[i]=dig[i/10]+1;
	p[0]=1;for (i=1;i<8;i++)p[i]=p[i-1]*10;
	for (i=1;i<=2222;i++)
	{
		for (j=10;j<=i;j*=10)
		{
			//12345
			k=i/j;//12
			l=i%j;//345
			l*=p[dig[i]-dig[j]+1];
			l+=k;
			if (i<l)v[i].pb(l);
			//if (i<l)printf("%d %d\n",i,l);
		}
	}
}
int main()
{
	freopen("C:\\Users\\daizhy\\Documents\\output.txt","w",stdout);
	init();
	int i,j,k,cas,cc=0;
	scanf("%d",&cas);
	while (cas--)
	{
		int l,r,ans=0;scanf("%d%d",&l,&r);
		for (i=l;i<=r;i++)
		{
			foreach(e,v[i])
			{
				if (*e<=r)
				{
					ans++;
					//printf("%d %d\n",i,*e);
				}
			}
		}
		printf("Case #%d: %d\n",++cc,ans);
	}
	return 0;
}
	
			
			

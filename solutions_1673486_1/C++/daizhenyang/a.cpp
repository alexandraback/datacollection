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
double p[111111],c[111111];
int main()
{
	freopen("C:\\Users\\daizhy\\Downloads\\A-large (5).in","r",stdin);
	freopen("C:\\Users\\daizhy\\Documents\\output.txt","w",stdout);
	int i,j,k,cas,cc=0;
	scanf("%d",&cas);
	while (cas--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for (i=0;i<n;i++)scanf("%lf",p+i);
		//keep typing
		double ans,sum=0;
		double pro=1;
		for (i=0;i<n;i++)
		{
			c[i]=pro;
			//sum+=pro*(1-p[i])*(m-n+1+m+1);
			pro*=p[i];
		}
		sum=pro*(m-n+1)+(1-pro)*(m-n+1+m+1);
		//printf("%lf\n",sum);
		ans=sum;
		int b;
		for (b=1;b<=n;b++)
		{
			sum=0;
			sum+=c[n-b]*(b+m-(n-b)+1)+(1-c[n-b])*(b+m-(n-b)+1+m+1);
			ans=min(ans,sum);
		}
		ans=min(ans,m+2.0);
		printf("Case #%d: %lf\n",++cc,ans);
	}
	return 0;
}

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
int a[111][111],b[111][111],n,m;
pii p[11111];
bool cmp(const pii &x,const pii &y)
{
	return a[x.fi][x.se]<a[y.fi][y.se];
}
bool v[111][111];
int main()
{
	freopen("C:\\Users\\daizhy\\Downloads\\B-large (7).in","r",stdin);
	freopen("C:\\2013¸öÈËÈü\\gcj\\ob.txt","w",stdout);
	int i,j,k,cas,cc=0;	
	scanf("%d",&cas);
	while (cas--)
	{
		scanf("%d%d",&n,&m);
		int cnt=0;
		for (i=0;i<n;i++)
		{
			for (j=0;j<m;j++)
			{
				scanf("%d",&a[i][j]);p[cnt++]=mp(i,j);
			}
		}
		//printf("cnt=%d\n",cnt);
		memcpy(b,a,sizeof(a));
		sort(p,p+cnt,cmp);
		clr(v);
		int it;
		for (it=0;it<cnt;it++)
		{
			int x=p[it].fi,y=p[it].se,z=a[x][y];
			//printf("%d %d %d\n",x,y,z);
			bool r=1,c=1;
			for (i=0;i<n;i++)
			{
				if (a[i][y]>a[x][y])
				{
					r=0;break;
				}
			}
			for (i=0;i<m;i++)
			{
				if (a[x][i]>a[x][y])
				{
					c=0;break;
				}
			}
			if (!r&&!c)break;
			if (r)
			{
				for (i=0;i<n;i++)
				{
					if (a[i][y]>z)a[i][y]=z;
				}
			}
			if (c)
			{
				for (i=0;i<m;i++)
				{
					if (a[x][i]>z)a[x][i]=z;
				}
			}
		}
		bool x=1;
		for (i=0;i<n;i++)
		{
			for (j=0;j<m;j++)
			{
				if (a[i][j]!=b[i][j])
				{
					x=0;
				}
			}
		}
		if (it<cnt)x=0;
		printf("Case #%d: %s\n",++cc,x?"YES":"NO");
	}
	return 0;
}


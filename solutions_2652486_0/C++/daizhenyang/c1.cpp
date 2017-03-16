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
int r,n,m,d;
int a[111];
int c[111];
string s;
bool ok;
void dfs(int x)
{
	if (ok)return;
	if (x==n)
	{
		int i,j;
		bool g=1;
		set<int>t;
		//for (i=0;i<n;i++)printf("%d",a[i]);
		//	puts("");
		for (i=0;i<(1<<n);i++)
		{
			int pro=1;
			for (j=0;j<n;j++)if (i&(1<<j))
			{
				pro*=a[j];
			}
			t.insert(pro);
		}
		for (i=0;i<d;i++)
		{
			if (t.find(c[i])==t.end())break;
		}
		if (i==d)
		{
			ok=1;
			for (i=0;i<n;i++)printf("%d",a[i]);
			puts("");
		}
		return;
	}
	for (int i=2;i<=m;i++)
	{
		a[x]=i;
		dfs(x+1);
	}
}
int main()
{
	freopen("C:\\Users\\daizhy\\Downloads\\C-small-1-attempt0.in","r",stdin);
	freopen("C:\\2013¸öÈËÈü\\gcj\\r1\\c1.txt","w",stdout);
	int i,j,k,cas,cc=0;
	scanf("%d",&cas);
	while (cas--)
	{
		scanf("%d%d%d%d",&r,&n,&m,&d);
		printf("Case #%d:\n",++cc);
		while (r--)
		{
			for (i=0;i<d;i++)
			{
				scanf("%d",&k);
				c[i]=k;
			}
			ok=0;
			dfs(0);
		}
	}
	return 0;
}

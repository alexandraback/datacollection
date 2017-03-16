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
int a[1111],b[1111],e[1111],n;
int main()
{
	freopen("C:\\Users\\daizhy\\Downloads\\B-small-attempt1 (4).in","r",stdin);
	freopen("C:\\Users\\daizhy\\Documents\\output.txt","w",stdout);
	int i,j,k,cas,cc=0;
	scanf("%d",&cas);
	while (cas--)
	{
		scanf("%d",&n);
		for (i=0;i<n;i++)scanf("%d%d",a+i,b+i);
		for (i=0;i<n;i++)
		{
			for (j=0;j<n-1;j++)
			{
				if (b[j]<b[j+1])
				{
					swap(a[j],a[j+1]);
					swap(b[j],b[j+1]);
				}
			}
		}
		clr(e);
		int now=0,ans=0;
		while (1)
		{
			int p=-1;
			for (i=0;i<n;i++)if (e[i]==0)
			{
				if (b[i]<=now)
				{
					p=i;break;
				}
			}
			if (p!=-1)
			{
				e[p]=2;
				now+=2;
				ans++;
				continue;
			}
			for (i=0;i<n;i++)if (e[i]==1)
			{
				if (b[i]<=now)
				{
					p=i;break;
				}
			}
			if (p!=-1)
			{
				e[p]=2;
				now++;
				ans++;
				continue;
			}
			for (i=0;i<n;i++)if (e[i]==0)
			{
				if (a[i]<=now)
				{
					p=i;break;
				}
			}
			if (p!=-1)
			{
				e[p]=1;
				now++;
				ans++;
				continue;
			}
			break;
		}
		printf("Case #%d: ",++cc);
		if (count(e,e+n,2)!=n)
		{
			puts("Too Bad");
		}
		else 
		{
			printf("%d\n",ans);
		}
	}
	return 0;
}
				

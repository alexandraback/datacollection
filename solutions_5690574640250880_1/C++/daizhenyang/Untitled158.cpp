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
int dx[]={-1,-1,-1,0,0,1,1,1};
int dy[]={-1,1,0,-1,1,-1,0,1};
char s[55][55];
vi gao(int num,int mx,int sum)
{
	vi a;
	if (num*mx<sum||sum<0)
	{
		a.pb(-1);
		return a;
	}
	int i,j,k;
	for (i=0;i<num;i++)a.pb(mx);
	int t=num*mx;i=0;
	while (t>sum)
	{
		if (t-mx>sum)
		{
			t-=mx;
			a[i]=0;
			i++;
		}
		else 
		{
			t-=sum;
			a[i]-=t;
			break;
		}
	}
	reverse(all(a));
	return a;
}
	
int main()
{
	freopen("C:\\competition\\gcj\\C-large.in","r",stdin);
	freopen("C:\\competition\\gcj\\C1.out","w",stdout);
	int i,j,k,cas,cc=0;
	scanf("%d",&cas);
	while (cas--)
	{
		int n,m,b;
		scanf("%d%d%d",&n,&m,&b);
		//printf("%d %d %d\n",n,m,b);
		for (i=0;i<n;i++)
		{
			for (j=0;j<m;j++)
			{
				s[i][j]='*';
			}
		}
		int c=n*m-b,f=0;
		printf("Case #%d:\n",++cc);
		if (c==1)
		{
			s[0][0]='c';
			for (i=0;i<n;i++)
			{
				for (j=0;j<m;j++)
				{
					putchar(s[i][j]);
				}
				puts("");
			}
			continue;
		}
		if (n==1)
		{
			for (i=0;i<c;i++)s[0][i]='.';
			s[0][0]='c';
			for (i=0;i<n;i++)
			{
				for (j=0;j<m;j++)
				{
					putchar(s[i][j]);
				}
				puts("");
			}
			continue;
		}
		if (m==1)
		{
			for (i=0;i<c;i++)s[i][0]='.';
			s[0][0]='c';
			for (i=0;i<n;i++)
			{
				for (j=0;j<m;j++)
				{
					putchar(s[i][j]);
				}
				puts("");
			}
			continue;
		}
		vi a;
		//a=gao(2,5,7);
		//printf("%d %d\n",a[0],a[1]);
		for (i=2;i<=n;i++)
		{
			int sc=c-2*i;
			for (j=0;j<=m-2;j++)
			{
				int sum=sc-2*j;
								//printf("%d %d %d\n",i-2,j,sum);
								a.clear();
				if (i-2==0&&sum==0)
				{
					;
				}
				else 
				{
					a=gao(i-2,j,sum);
					if (a[0]==-1)continue;
				}
//printf("%d %d %d\n",i-2,j,sum);
				f=1;
				a.insert(a.begin(),2+j);
				a.insert(a.begin(),2+j);
				for (k=2;k<sz(a);k++)
				{
					a[k]+=2;
				}
				goto ed;
			}
		}
		ed:
		if (!f)
		{
			puts("Impossible");
			continue;
		}
		while (sz(a)<n)a.pb(0);
		for (i=0;i<n;i++)
		{
			for (j=0;j<a[i];j++)s[i][j]='.';
		}
		s[0][0]='c';
		for (i=0;i<n;i++)
			{
				for (j=0;j<m;j++)
				{
					putchar(s[i][j]);
				}
				puts("");
			}
			
	}
	return 0;
}
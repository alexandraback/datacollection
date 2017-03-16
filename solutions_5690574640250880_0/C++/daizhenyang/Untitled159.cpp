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
char s[11][11];
int n,m,fd;
void cc1(int c,int f)
{
	if (fd)return;
	int i,j,k;
	if (!c)
	{
		for (i=0;i<n;i++)
			{
				for (j=0;j<m;j++)
				{
					putchar(s[i][j]);
				}
				puts("");
			}
			fd=1;
			return;
	}
	if (c)
	{
		if (f)
		{
			for (i=0;i<n;i++)
			{
				for (j=0;j<m;j++)
				{
					int cnt=1;
					for (k=0;k<8;k++)
					{
						int x=i+dx[k],y=j+dy[k];
						if (x>=0&&x<n&&y>=0&&y<m)
						{
							++cnt;
						}
					}
					if (c>=cnt)
					{
						char st[11][11];
						memcpy(st,s,sizeof(s));
							s[i][j]='c';
							for (k=0;k<8;k++)
							{
								int x=i+dx[k],y=j+dy[k],cnt=0;
								if (x>=0&&x<n&&y>=0&&y<m)
								{
									s[x][y]='.';
								}
							}
							//if (i==1&&j==1)printf("%d%c\n",cnt,s[i][j]);
							cc1(c-cnt,0);
							memcpy(s,st,sizeof(st));
							//printf("%c\n",s[i][j]);
						}
					}
				}
				return;
			}
			for (i=0;i<n;i++)
			{
				for (j=0;j<m;j++)if (s[i][j]=='.')
				{
					int cnt=0;
					for (k=0;k<8;k++)
					{
						int x=i+dx[k],y=j+dy[k];
						if (x>=0&&x<n&&y>=0&&y<m)
						{
							if (s[x][y]=='*')++cnt;
						}
					}//printf("%d %d %d\n",i,j,cnt);
					if (cnt&&c>=cnt)
					{
						char st[11][11];
							memcpy(st,s,sizeof(s));
							for (k=0;k<8;k++)
							{
								int x=i+dx[k],y=j+dy[k],cnt=0;
								if (x>=0&&x<n&&y>=0&&y<m)
								{
									if (s[x][y]!='c')s[x][y]='.';
								}
							}
							cc1(c-cnt,0);
							memcpy(s,st,sizeof(st));
					}
				}
			}
		}
}
int main()
{
	freopen("C:\\competition\\gcj\\C-small-attempt4.in","r",stdin);
	freopen("C:\\competition\\gcj\\C.out","w",stdout);
	int i,j,k,cas,cc=0;
	scanf("%d",&cas);
	while (cas--)
	{
		int b;
		scanf("%d%d%d",&n,&m,&b);
		for (i=0;i<n;i++)
		{
			for (j=0;j<m;j++)
			{
				s[i][j]='*';
			}
		}
		int c=n*m-b,f=1;
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
		fd=0;
		cc1(c,1);
		if (!fd)puts("Impossible");
		continue;
	}
	return 0;
}
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
int t[133];
int ov[111],sov[111],sv[111];
bool cmp(int x,int y)
{
	if (sov[x]==sov[y])return ov[x]<ov[y];
	return sov[x]>sov[y];
}
int main()
{
	freopen("C:\\Users\\daizhy\\Downloads\\B-large (5).in","r",stdin);
	freopen("C:\\Users\\daizhy\\Documents\\output.txt","w",stdout);
	int i,j,k,cas,cc=0;
	scanf("%d",&cas);
	while (cas--)
	{
		int n;scanf("%d",&n);
		int s,p;scanf("%d%d",&s,&p);
		clr(ov);clr(sov);clr(sv);
		for (int it=0;it<n;it++)
		{
			scanf("%d",t+it);
			for (i=0;i<=10;i++)
			{
				for (j=i;j<=10;j++)
				{
					for (k=j;k<=10;k++)
					{
						if (k-j>2||j-i>2||k-i>2)continue;
						if (i+j+k==t[it])
						{	
							if (k>=p)
							{
								if (k-j==2||j-i==2||k-i==2)sov[t[it]]=1;
								else 
								{
									//if (t[it]==21)printf("%d %d %d\n",i,j,k);
									ov[t[it]]=1;
								}
							}
							if (k-j==2||j-i==2)sv[t[it]]=1;
						}
					}
				}
			}		
		}
		sort(t,t+n,cmp);
		int ans=0;
		for (i=0;i<n;i++)
		{
			//printf("%d %d %d\n",t[i],sov[t[i]],ov[t[i]]);
			if (s)
			{
				if (sov[t[i]])
				{
					s--;
					ans++;
				}
				else 
				{
					s--;
				}
			}
			else 
			{
				if (ov[t[i]])ans++;
			}
		}
		printf("Case #%d: %d\n",++cc,ans);
	}
	return 0;
}
		

#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <complex>
#include <utility>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <climits>

using namespace std;


typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef pair<int,int> PII;

#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
#define REV(i,a,b) for(int i=a-1;i>=b;i--)
#define rev(i,n) REV(i,n,0)
#define TR(i,x) for(typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define GI ({ int x; scanf("%d",&x); x; })
#define GLL ({ LL x; scanf("%lld",&x); x; })
#define ALL(v) v.begin(),v.end()
#define PB push_back
#define MP make_pair
#define PQ priority_queue
#define inf (int)(1e9)
#define linf (LL)(1e18)
#define eps (double)(1e-9)
#define leps (LD)(1e-18)
#define PI (double)(3.141592653589793238)


int dx[]={-1,0,0,1},dy[]={0,-1,1,0};
int n,m,k;
bool s[25][25],vis[25][25];
int dp[25][25][25];

bool valid(int x,int y)
{
	if(x<0||x>=n||y<0||y>=m)
		return 1;
	return s[x][y];
}

void dfs(int x,int y,bool &ans)
{
	if(vis[x][y])
		return;
	vis[x][y]=1;
	if(x==0||x==n-1||y==0||y==m-1)
		ans=1;
	rep(i,4)
		if(!valid(x+dx[i],y+dy[i]))
			dfs(x+dx[i],y+dy[i],ans);
}

int count(int mask)
{
	rep(i,n)
		rep(j,m)
			s[i][j]=mask&(1<<(i*m+j));
	int cnt=__builtin_popcount(mask);
	rep(i,n)
		rep(j,m)
			if(!s[i][j])
			{
				memset(vis,0,sizeof vis);
				bool check=0;
				dfs(i,j,check);
				if(!check)
					cnt++;
			}
	return cnt;
}

int solve(int n,int m)
{
	::n=n,::m=m;
	int &ans=dp[n][m][k];
	if(~ans)
		return ans;
	ans=k;
	rep(i,(1<<(n*m)))
		if(count(i)>=k)
			ans=min(ans,__builtin_popcount(i));
	return ans;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t,n,m;
	cin>>t;
	memset(dp,-1,sizeof dp);
	REP(i,1,t+1)
	{
		cin>>n>>m>>k;
		cout<<"Case #"<<i<<": "<<solve(min(n,m),max(n,m))<<'\n';
	}
	return 0;
}

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
#include <utility> 
#include <sstream> 
#include <memory.h>
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
using namespace std; 

const int inf = 1000*1000*1000; 
#define CL(x,a) memset(x,a,sizeof(x)); 
#define ALL(v) (v).begin(),(v).end() 
#define PII pair<int,int> 
#define PDI pair<double,int> 
#define MP(a,b) make_pair(a,b) 
#define FOR(i,n) for(int i=0;i<n;i++) 
typedef long long LL; 
typedef vector<int> vi; 
typedef vector< vi > vvi; 
typedef vector< vector<PII > > vvpii; 

int n,m;
pair<LL,int> ar[2][128];
vector<int> last[2][128];
LL dp[128][128];
LL DP(int x, int y)
{
	if (x == n)
		return 0;
	if (y == m)
		return 0;
	if (dp[x][y] != -1)
		return dp[x][y];
	LL res = 0;
	res = max(res,DP(x+1,y));
	res = max(res,DP(x,y+1));
	if (ar[0][x].second == ar[1][y].second)
	{
		LL S = 0;
		int tx = x, ty = y;
		LL sX=ar[0][x].first,sY=ar[1][y].first;
		while(tx < n && ty < m)
		{
			if (sX < sY)
			{
				S += sX;
				sY-=sX;
				sX=0;
				res = max(res,DP(tx+1,ty+1) + S);
				tx=last[0][tx][ar[0][x].second];
				if (tx < n)
					sX += ar[0][tx].first;
			}
			else
			{
				S += sY;
				sX-=sY;
				sY=0;
				res = max(res,DP(tx+1,ty+1) + S);
				ty=last[1][ty][ar[1][y].second];
				if (ty < m)
					sY += ar[1][ty].first;
			}
		}
	}
	return dp[x][y] = res;
}
void Solve()
{
	CL(dp,-1);
	scanf("%d%d",&n,&m);
	FOR(i,n)
	{
		scanf("%lld%d",&ar[0][i].first,&ar[0][i].second);
	}
	FOR(i,m)
	{
		scanf("%lld%d",&ar[1][i].first,&ar[1][i].second);
	}
	vector<int> L(128,n);
	for (int i=n-1;i>=0;i--)
	{
		last[0][i] = L;
		L[ar[0][i].second] = i;
	}
	L.assign(128,m);
	for (int i=m-1;i>=0;i--)
	{
		last[1][i] = L;
		L[ar[1][i].second] = i;
	}
	printf("%lld\n",DP(0,0));
}
int main() 
{ 
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	int T;
	scanf("%d",&T);
	FOR(i,T)
	{
		printf("Case #%d: ",i+1);
		Solve();
	}
	return 0; 
}

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
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <string>

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

#define forup(i,a,b) for(int i=a; i<b; ++i)
#define fordn(i,a,b) for(int i=a; i>b; --i)
#define rep(i,a) for(int i=0; i<a; ++i)

#define dforup(i,a,b) for(i=a; i<b; ++i)
#define dfordn(i,a,b) for(i=a; i>b; --i)
#define drep(i,a) for(i=0; i<a; ++i)

#define slenn(s,n) for(n=0; s[n]!='\0'; ++n)

#define gi(x) scanf("%d",&x)
#define gl(x) cin>>x
#define gd(x) scanf("%lf",&x)
#define gs(x) scanf("%s",x)

#define pis(x) printf("%d ",x)
#define pin(x) printf("%d\n",x)
#define pls(x) cout<<x<<" "
#define pln(x) cout<<x<<"\n"
#define pds(x) printf("%.12f ",x)
#define pdn(x) printf("%.12f\n",x)
#define pnl() printf("\n")

#define fs first
#define sc second

#define pb push_back

const int inv=numeric_limits<int>::max();
const int minv=numeric_limits<int>::min();

const int max_n=15;
const int max_e=10;

int T;
int e,r,n;
int v[max_n];
int dp[max_n+1][max_e+1];

int main()
{
	gi(T);
	
	rep(z,T)
	{
		gi(e); gi(r); gi(n);
		
		rep(i,n)
			gi(v[i]);
		
		rep(i,n+1)
			rep(j,e+1)
				dp[i][j]=-1;
		dp[0][e]=0;
		
		rep(i,n)
		{
			for(int j=0; j<=e; ++j)
			{
				if(dp[i][j]!=-1)
				{
					for(int k=0; k<=j; ++k)
					{
						dp[i+1][min(j-k+r,e)] = max ( dp[i+1][min(j-k+r,e)] , dp[i][j] + v[i]*k );
					}
				}
			}
		}
		
		int res=0;
		for(int j=0; j<=e; ++j)
			res=max(res,dp[n][j]);
		
		printf("Case #%d: %d\n",z+1,res);
	}
	
	return 0;
}
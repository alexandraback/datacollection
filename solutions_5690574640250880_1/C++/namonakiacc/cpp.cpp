#include <cstdio>
#include <vector>
#include <cstring>
#include <functional>
#include <algorithm>
#include <math.h>
#include <bitset>
#include <set>
#include <queue>
#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <complex>
#include <numeric>
#include <map>
#include <time.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int,ll> pil;
typedef pair<ll,int> pli;
typedef pair<int,pii> pip;
typedef pair<pii,int> ppi;
typedef pair<ll,ll> pll;
typedef pair<double,int> pdi;
typedef pair<double,double> pdd;
typedef vector<double> vec;
typedef vector<vec> mat;
#define rep(i,n) for (int (i) = 0; (i) < (n); (i)++)
#define repn(i,a,n) for (int (i) = (a); (i) < (n); (i)++)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back
#define SORT(x) sort((x).begin(),(x).end())
#define SORTN(x,n) sort((x),(x)+(n))
#define ERASE(x) (x).erase(unique((x).begin(),(x).end()),(x).end())
#define COUNT(x,c) count((x).begin(),(x).end(),(c))
#define REMOVE(x,c) (x).erase(remove((x).begin(),(x).end(),(c)),(x).end())
#define REVERSE(x) reverse((x).begin(),(x).end())
#define FORIT(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define LB(x,a) lower_bound((x).begin(),(x).end(),(a))-(x).begin()
#define lb(x,a) lower_bound((x).begin(),(x).end(),(a))
#define LBN(x,a,n) lower_bound((x),(x)+(n),(a))-(x)
#define lbN(x,a,n) lower_bound((x),(x)+(n),(a))
#define UB(x,a) upper_bound((x).begin(),(x).end(),(a))-(x).begin()
#define ub(x,a) upper_bound((x).begin(),(x).end(),(a))
#define BS(x,a) binary_search((x).begin(),(x).end(),(a))
#define NB(x) (((x)&~((x)+((x)&-(x))))/((x)&-(x))>>1)|((x)+((x)&-(x)))
#define NP(x) next_permutation((x).begin(),(x).end())
#define MM(x,p) memset((x),(p),sizeof(x))
#define SQ(x) (x)*(x)
#define SC(c1,c2) strcmp(c1,c2)==0
#define mp make_pair
#define INF (1<<30)
#define INFL (1LL<<56)
#define fi first
#define se second
#define MOD 1000000007
#define EPS 1e-9

int T,R,C,M;
bool dp[51][2600][51];
int prv[51][2600][51];
int as[51];

int main()
{
	scanf("%d",&T);
	rep(t,T)
	{
		scanf("%d%d%d",&R,&C,&M);
		printf("Case #%d:\n",t+1);
		if(M==0)
		{
			rep(i,R)
			{
				rep(j,C)
				{
					if(i==R-1&&j==C-1)putchar('c');
					else putchar('.');
				}
				putchar('\n');
			}
			continue;
		}
		else if(R*C-1==M)
		{
			rep(i,R)
			{
				rep(j,C)
				{
					if(i==R-1&&j==C-1)putchar('c');
					else putchar('*');
				}
				putchar('\n');
			}
			continue;
		}
		if(C==1)
		{
			rep(i,M)puts("*");
			repn(i,M,R-1)puts(".");
			puts("c");
			continue;
		}
		if(R==1)
		{
			rep(i,M)putchar('*');
			repn(i,M,C-1)putchar('.');
			putchar('c');
			putchar('\n');
			continue;
		}
		M=R*C-M;
		MM(dp,0);MM(prv,-1);
		dp[0][0][0]=true;
		rep(i,R-1)rep(j,R*C+1)rep(k,C+1)if(dp[i][j][k])repn(l,k,C+1)if(l!=1)
		{
			dp[i+1][j+l][l]=true;
			prv[i+1][j+l][l]=k;
		}
		rep(j,R*C+1)rep(k,C+1)if(dp[R-1][j][k])
		{
			dp[R][j+k][k]=true;
			prv[R][j+k][k]=k;
		}
		int apos=-1;
		rep(k,C+1)if(dp[R][M][k])apos=k;
		if(apos==-1)
		{
			puts("Impossible");
			continue;
		}
		int k=apos;
		as[R-1]=k;
		int m=M;
		for(int i=R-2;i>=0;i--)
		{
			int tm=m;
			m-=k;
			k=prv[i+2][tm][k];
			as[i]=k;
		}
		rep(i,R)
		{
			rep(j,C-as[i])putchar('*');
			repn(j,C-as[i],C)
			{
				if(i+1==R&&j+1==C)putchar('c');
				else putchar('.');
			}
			putchar('\n');
		}
	}
}

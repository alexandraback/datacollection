#include <algorithm>
#include <iostream>
#include <sstream>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <deque>
#include <ctime>
#include <list>
#include <set>
#include <map>
//zlb//

using namespace std;

typedef long long     LL;
typedef pair<int,int> pii;

double PI  = acos(-1);
double EPS = 1e-7;
int INF    = 1000000000;
int MOD    = 1000000007;
int MAXINT = 2147483647;
LL INFLL   = 1000000000000000000LL;
LL MAXLL   = 9223372036854775807LL;

#define fi            first
#define se            second
#define mp            make_pair
#define pb            push_back
#define SIZE(a)       (int)a.size()
#define MIN(a, b)     (a) = min((a), (b))
#define MAX(a, b)     (a) = max((a), (b))
#define input(in)     freopen(in,"r",stdin)
#define output(out)   freopen(out,"w",stdout)
#define RESET(a, b)   memset(a,b,sizeof(a))
#define FOR(a, b, c)  for (int (a)=(b); (a)<=(c); (a)++)
#define FORD(a, b, c) for (int (a)=(b); (a)>=(c); (a)--)
#define FORIT(a, b)   for (__typeof((b).begin()) a=(b).begin(); a!=(b).end(); a++)

int mx[8] = {-1,1,0,0,-1,-1,1,1};
int my[8] = {0,0,-1,1,-1,1,-1,1};

// ------------ //

int lol()
{
	double p;
	scanf("%lf",&p);
	return ceil(p*1000);
}

int x[1005];
int y[1005];

int main()
{
	int T;
	scanf("%d",&T);
	FOR(tc,1,T)
	{
		int n;
		scanf("%d",&n);
		FOR(a,1,n)
		{
			x[a] = lol();
		}
		FOR(a,1,n)
		{
			y[a] = lol();
		}
		sort(x+1,x+n+1);
		sort(y+1,y+n+1);
		int take = 0,take2=0;
		FOR(d,1,n)
		{
			bool valid = 1;
			FOR(a,1,d)
			{
				if (x[a] > y[n-d+a]) valid = 0;
			}
			if (!valid) break;
			else take = d;
		}
		FOR(d,1,n)
		{
			bool valid = 1;
			FOR(a,1,d)
			{
				if (y[a] > x[n-d+a]) valid = 0;
			}
			if (!valid) break;
			else take2 = d;
		}
		printf("Case #%d: %d %d\n",tc,take2,n-take);
	}
}

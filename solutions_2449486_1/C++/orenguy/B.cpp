#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<sstream>
#include<string>
#include<string.h>
#include<deque>
#include<vector>
#include<stack>
#include<queue>
#include<math.h>
#include<map>
#include<set>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

double PI = acos(-1);
double EPS = 1e-7;
int INF = 1000000000;
int MAXINT = 2147483647;
LL INFLL = 1000000000000000000LL;
LL MAXLL = 9223372036854775807LL;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define SIZE(a) (int)a.size()
#define ALL(a) a.begin(),a.end()
#define RESET(a,b) memset(a,b,sizeof(a))
#define FOR(a,b,c) for (int (a)=(b); (a)<=(c); (a)++)
#define FORD(a,b,c) for (int (a)=(b); (a)>=(c); (a)--)
#define FORIT(a,b) for (__typeof((b).begin()) a=(b).begin(); a!=(b).end(); (a)++)
#define MIN(a, b) (a) = min((a), (b))
#define MAX(a, b) (a) = max((a), (b))
#define PAUSE system("pause")

#define input(in) freopen(in,"r",stdin)
#define output(out) freopen(out,"w",stdout)

pii M[8] = {mp(0,1),mp(1,0),mp(-1,0),mp(0,-1),mp(-1,1),mp(-1,-1),mp(1,-1),mp(1,1)};

/*\   \
\   \*/

int v[200];
int h[200];
int ar[200][200];

int main()
{
	int t;
	scanf("%d",&t);
	FOR(tc,1,t)
	{
		RESET(v,0);
		RESET(h,0);
		int n,m;
		scanf("%d%d",&n,&m);
		FOR(a,1,n)
		{
			FOR(b,1,m)
			{
				scanf("%d",&ar[a][b]);
			}
		}
		FOR(a,1,n)
		{
			FOR(b,1,m)
			{
				MAX(h[a],ar[a][b]);
			}
		}
		FOR(a,1,m)
		{
			FOR(b,1,n)
			{
				MAX(v[a],ar[b][a]);
			}
		}
		bool fail = 0;
		FOR(a,1,n)
		{
			FOR(b,1,m)
			{
				if (ar[a][b] != h[a] && ar[a][b] != v[b]) fail = 1;
			}
		}
		if (!fail) printf("Case #%d: YES\n",tc);
		else printf("Case #%d: NO\n",tc);
	}
}

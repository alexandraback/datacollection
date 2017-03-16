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

char val[10][10];
int lol[10][10];
int vis[10];

int main()
{
	int tc,T=0;
	scanf("%d",&tc);
	while(tc--)
	{
		T++;
		RESET(lol,0);
		int n,m;
		scanf("%d%d",&n,&m);
		FOR(a,1,n)
		{
			scanf("%s",val[a]);
		}
		string mins ="";
		FOR(a,1,n)
		{
			mins += "99999";
		}
		FOR(a,1,n)
		{
			vis[a] = a;
		}
		FOR(a,1,m)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			lol[u][v] = 1;
			lol[v][u] = 1;
		}
		do
		{
			vector<int> path;
			path.pb(vis[1]);
			bool fail = 0;
			FOR(a,2,n)
			{
				while(!path.empty() && lol[path.back()][vis[a]] == 0) path.pop_back();
				if (path.empty())
				{
					fail = 1;
					break;
				}
				path.pb(vis[a]);
			}
			if (!fail)
			{
				string cur = "";
				FOR(a,1,n)
				{
					cur += val[vis[a]];
				}
				MIN(mins,cur);
			}
		} while(next_permutation(vis+1,vis+n+1));
		printf("Case #%d: %s\n",T,mins.c_str());
	}
}

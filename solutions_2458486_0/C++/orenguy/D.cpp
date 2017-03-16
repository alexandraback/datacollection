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

int dp[1050000];
pii nx[1050000];
int n,k;


int t_O[500];
vector<int> t_L[500];
vector<int> ans;

int O[500];
vector<int> L[500];

map<int,int> m;

int K[500];
int i[500];

bool go(int bm)
{
	if (dp[bm] != -1) return dp[bm];
	if (bm == (1 << n)-1) return dp[bm] = 1;
	int ls[50];
	RESET(ls,0);
	FOR(a,1,k)
	{
		if (K[a] != -1) ls[K[a]]++;
	}
	FOR(a,1,n)
	{
		if (bm & (1 << (a-1)))
		{
			ls[O[a]]--;
			FOR(b,0,SIZE(L[a])-1)
			{
				ls[L[a][b]]++;
			}
		}
	}
	FOR(a,1,n)
	{
		if (!(bm & (1 << (a-1))))
		{
			if (ls[O[a]] < 0)
			{
				while(1) puts("LOL");
			}
			if (ls[O[a]] > 0)
			{
				if (go(bm+(1 << (a-1))))
				{
					nx[bm] = mp(a,bm+(1 << (a-1)));
					return dp[bm]=1;
				}
			}
		}
	}
	return dp[bm]=0;
}

void track(int bm)
{
	if (bm == (1 << n)-1) return;
	ans.pb(nx[bm].fi);
	track(nx[bm].se);
}

int main()
{
	int t;
	scanf("%d",&t);
	FOR(tc,1,t)
	{

		RESET(dp,-1);
		RESET(nx,-1);
		m.clear();
		FOR(a,0,55)
		{
			t_L[a].clear();
			L[a].clear();
		}
		ans.clear();

		scanf("%d%d",&k,&n);
		FOR(a,1,k)
		{
			scanf("%d",&K[a]);
		}
		FOR(a,1,n)
		{
			int d;
			scanf("%d%d",&O[a],&d);
			m[O[a]] = 0;
			while(d--)
			{
				int u;
				scanf("%d",&u);
				L[a].pb(u);
			}
		}
		/*
		int id = 0;
		FORIT(it,m)
		{
			m[(*it).fi] = ++id;
		}
		FOR(a,1,k)
		{
			if (m.count(K[a])) K[a] = m[K[a]];
			else K[a] = -1;
		}
		FOR(a,1,n)
		{
			O[a] = m[t_O[a]];
			FOR(b,0,SIZE(t_L[a])-1)
			{
				if (m.count(t_L[a][b])) L[a].pb(t_L[a][b]);
			}
		}
		*/
		printf("Case #%d: ",tc);
		if (go(0))
		{
			track(0);
			FOR(a,0,SIZE(ans)-1)
			{
				printf("%d",ans[a]);
				if (a == SIZE(ans)-1) puts("");
				else printf(" ");
			}
		}
		else puts("IMPOSSIBLE");
	}
}

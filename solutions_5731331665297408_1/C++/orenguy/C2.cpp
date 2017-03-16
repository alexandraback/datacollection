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

pii val[55];
int lol[55][55];
int vs[55];
int vis[55];
int rem[55];
vector<int> path;
vector<int> sav;
int n,m;

void dfs(int u)
{
	//cout << u << endl;
	vis[u] = 1;
	FOR(a,1,n)
	{
		if (lol[u][a] && !vis[a] && !rem[a]) dfs(a);
	}
}

int main()
{
	int tc,T=0;
	scanf("%d",&tc);
	while(tc--)
	{
		T++;
		path.clear();
		sav.clear();
		RESET(lol,0);
		RESET(vs,0);
		RESET(rem,0);
		scanf("%d%d",&n,&m);
		FOR(a,1,n)
		{
			scanf("%d",&val[a].fi);
			val[a].se = a;
		}
		sort(val+1,val+n+1);
		FOR(a,1,m)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			lol[u][v] = 1;
			lol[v][u] = 1;
		}
		/*
		FOR(a,1,n)
		{
			cout << val[a].fi << " " << val[a].se << endl;
		}*/
		printf("Case #%d: ",T);
		vector<int> ans;
		FOR(a,1,n)
		{
			FOR(b,1,n)
			{
				if (!vs[val[b].se])
				{
					int v = val[b].se;
					if (a == 1)
					{
						ans.pb(b);
						path.pb(v);
						vs[v] = 1;
						break;
					}
					while(!path.empty() && lol[path.back()][v] == 0)
					{
						int tmp = path.back();
						rem[tmp] = 1;
						sav.pb(tmp);
						path.pop_back();
					}
					/*
					cout << "TRY " << a << " " << b << endl;
					FOR(a,0,SIZE(path)-1)
					{
						cout << path[a] << " ";
					}
					cout << endl; 
					cout << endl;
					*/
					if (!path.empty())
					{
						path.pb(v);
						//cout << "DFS" << endl;
						RESET(vis,0);
						dfs(path[0]);
						bool fail = 0;
						FOR(c,1,n)
						{
							if (!vs[c] && !vis[c]) fail = 1;
						}
						if (!fail)
						{
							//cout << "SUCCEDD" << endl;
							sav.clear();
							ans.pb(b);
							vs[v] = 1;
							break;
						}
						path.pop_back();
					}
					//cout << "FAIL " << endl;
					while(!sav.empty())
					{
						rem[sav.back()] = 0;
						path.pb(sav.back());
						sav.pop_back();
					}
					/*
					FOR(a,0,SIZE(sav)-1)
					{
						cout << sav[a] << " ";
					}
					cout << endl; 
					cout << endl;
					*/
				}
			}
		}
		FOR(a,0,SIZE(ans)-1)
		{
			cout << val[ans[a]].fi;
		}
		puts("");
	}
}

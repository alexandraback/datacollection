#include <cstring>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <list>

using namespace std;

#define FOR(i,a,b) for(int i(a), _b(b); i < _b; ++i)
#define REP(i,n) FOR(i,0,n)
#define FORD(i,a,b) for(int i(a), _b(b); i >= _b; --i)
#define sz(a) (int)((a).size())
#define X first
#define Y second
#define all(a) (a).begin(),(a).end()
#define pb push_back

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<vi> vii;
typedef vector<pii> vpii;

#define N 1005

int n,m,k,x;
vi a[N];
bool reach[N][N];

void dfs(int v, int start)
{
	reach[start][v] = 1;
	REP(i,sz(a[v]))
		if(!reach[start][a[v][i]])
			dfs(a[v][i], start);
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int test;
	scanf("%d",&test);
	REP(t,test)
	{
		scanf("%d", &n);
		REP(i,n)
		{
			a[i].clear();
			scanf("%d",&k);
			REP(j,k)
			{
				scanf("%d", &x);
				--x;
				a[i].pb(x);
			}
		}
		memset(reach,0,sizeof(reach));
		REP(i,n)
			dfs(i,i);
		bool flag = false;
		REP(i,n) if(!flag)
		{
			REP(j,n) if(!flag)
			{
				if(i != j && reach[i][j])
				{
					REP(k, sz(a[i]))
					{
						FOR(l, k+1, sz(a[i]))
						{
							if(reach[a[i][k]][j] && reach[a[i][l]][j])
								flag = true;
						}
					}
				}
			}
		}
		printf("Case #%d: %s\n", t+1, flag ? "Yes" : "No");
	}
	return 0;
}
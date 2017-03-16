#include <vector>
#include <list>
#include <map>
#include <set>
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
#include <climits>
#include <cstring>
#include <cassert>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define SZ(x) ((int)(x).size())
#define FORV(i,x) FOR(i,0,SZ(x))  
#define DBG(x) cout<<(#x)<<" : "<<(x)<<endl
#define PB push_back
#define ALL(x) x.begin(),x.end()

#define ACC(x) accumulate(ALL(x)) 
#define FORE(i,a,b) for(int i=(a);i<=(b);i++)
#define ROFE(i,a,b) for(int i=(b);i>=(a);i--)
#define MP make_pair
#define left(x) (x<<1)
#define right(x) (left(x)+1)
#define PI pair<int,int>
#define PD pair<double,double>
#define F first
#define S second 
#define LL long long
#define ULL unsigned long long
#define MAX 50010

int nc, n; bool vis[1010];
vector < vector <int> > adj(1010);
bool yes = false;

void dfs(int x)
{
	if(yes) return;
	vis[x] = true;
	FORV(i, adj[x])
	{
		if(vis[adj[x][i]]) yes = true;
		dfs(adj[x][i]);
	}
}

int main()
{
	int cases; scanf("%d", &cases); 
	FOR(c, 1, cases + 1)
	{
		scanf("%d", &n);
		adj.resize(0);
		adj.resize(1010);
		yes = false;
		FOR(i, 0, n)
		{
			scanf("%d", &nc); int x;
			FOR(j, 0, nc) scanf("%d", &x), adj[i + 1].PB(x);
		}
		FOR(i, 1, n + 1)
		{
			memset(vis, 0, sizeof vis); dfs(i);
			if(yes) break;
		}
		printf("Case #%d: %s\n", c, yes? "Yes" : "No");
	}
	return 0;
}
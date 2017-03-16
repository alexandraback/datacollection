#include<iostream>
#include<string.h>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<deque>
#include<set>
#include<list>
#include<stack>
#include<sstream>
#include<fstream>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cassert>
#define CLRM(x) memset(x,-1,sizeof(x))
#define CLR(x) memset(x,0,sizeof(x))
#define ALL(x) x.begin(),x.end()
#define GI(x) scanf("%d", &x);
#define FORN(i, n) for(int i = 0; i < n; i++)
#define FOR(i, start, end) for(int i = start; i < end; i++)
#define PB push_back
#define MP make_pair
#define VI vector<int> 
#define VVI vector<vector<int> >
#define PII pair<int,int>
#define SZ(x) (int)x.size()
#define LL long long
#define MIN(a,b) (a)<(b)?(a):(b)
#define MAX(a,b) (a)>(b)?(a):(b)
#define LMAX 1000000000000000000LL
#define IMAX 1000000000
using namespace std;

#define MAXN 1100
int N;
VVI adj;
int vis[MAXN];

int is_dia(int node)
{
	queue<int> q;
	q.push(node);
	while(!q.empty())
	{
		int cur = q.front();
		q.pop();
		if(vis[cur])
			return 1;
		vis[cur] = 1;
		FORN(i, adj[cur].size())
		{
			int nxt = adj[cur][i];
			q.push(nxt);
		}
	}
	return 0;
}
int solve()
{
	FORN(i, N)
	{
		CLR(vis);
		if(is_dia(i))
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	int tes;
	GI(tes);
	FORN(c, tes)
	{
		adj.clear();
		GI(N);
		adj.resize(N);
		FORN(i, N)
		{
			int m, x;
			GI(m);
			FORN(j, m)
			{
				GI(x);
				x--;
				adj[i].PB(x);
			}
		}
		int ans = solve();
		string t = "No";
		if(ans == 1)
			t = "Yes";
		printf("Case #%d: %s\n", c+1, t.c_str());
	}
	return 0;
}

#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <cstdlib>
#include <ctime>
#include <stack>
#include <functional>
using namespace std;

typedef	long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

#define REP(i, n) for(int i = 0; i < (n); ++i)
#define FOR(i, p, k) for(int i = (p); i <= (k); ++i)
#define FOREACH(x,Z) for(__typeof((Z).begin()) x=(Z).begin();x!=(Z).end();++x)

#define PB(x) push_back(x)
#define MP(x) make_pair(x)

int n;
vector<int> G[2001];
int t[2001];

bool dfs(int v)
{
	REP(i, G[v].size())
	{
		if(t[G[v][i]] != 0) return true;
		t[G[v][i]] = v;
		if(dfs(G[v][i])) return true;
	}
	return false;
}

void solve()
{
	FOR(v, 1, n)
	{
		FOR(w, 1, n) t[w] = 0;
		t[v] = -1;
		if(dfs(v))
		{
			printf("Yes\n");
			return;
		}
	}
	printf("No\n");
}

int main()
{
	int Z;
	scanf("%d", &Z);
	for(int a = 1; a <= Z; ++a)
	{
		scanf("%d", &n);
		FOR(c, 1, n)
		{
			G[c].clear();
			int k, b;
			scanf("%d", &k);
			
			while(k--)
			{
				scanf("%d", &b);
				G[c].PB(b);
			}
		}
		printf("Case #%d: ", a);
		solve();
	}
	return 0;
}

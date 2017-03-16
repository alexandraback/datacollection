/* AnilKishore * India */

#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>

#include <iostream>
#include <algorithm>
#include <string>

#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PI;

#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
#define F first
#define S second
#define SET(v,x) memset(v,x,sizeof v)
#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define EACH(it,v) for(typeof((v).begin()) it = (v).begin();it!=(v).end();it++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define SORT(v) sort(ALL(v))
#define SZ(v) int(v.size())
#define SI ({int x;scanf("%d",&x);x;})

#define MX 1005

int n;
VI g[MX];
int id[MX], k;
bool instack[MX];

bool dfs(int u)
{
	instack[u] = true;
	EACH(it,g[u])
	{
		int v = *it;
		if(id[v]==-1){ id[v]=k++; if(dfs(v)) return true; }
		else if(!instack[v]) return true;
	}
	instack[u] = false;
	return false;
}

int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	//freopen("?-large.in","r",stdin);
	//freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	
	for(int kase=1,kases=SI;kase<=kases;kase++)
	{
		printf("Case #%d: ",kase);
		n = SI;
		REP(i,n)
		{
			int m = SI;
			g[i].clear();
			REP(j,m) g[i].PB(SI-1);
		}
		bool yes = false;
		REP(i,n)
		{
			SET(instack,false);
			SET(id,-1);
			if(dfs(i)){ yes = true;	break; }
		}
		puts(yes?"Yes":"No");
	}
	
		
	return 0;
}

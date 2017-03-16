#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker,"/STACK:32000000")
#include <algorithm>
#include <numeric>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <cassert>

using namespace std;

#define REP(i,n) for (int i=0,_n=(n); i < _n; i++)
#define REPD(i,n) for (int i=(n)-1; i >= 0; i--)
#define FOR(i,a,b) for (int _b=(b), i=(a); i <= _b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))

#define CLEAR(x) memset(x,0,sizeof x);
#define CLEARA(x) memset(&x,0,sizeof x);
#define FILL(x,v) memset(x,v,sizeof x);
#define FILLA(x,v) memset(&x,v,sizeof x);

#define VAR(a,b) __typeof(b) a=(b)
#define FOREACH(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)

#define REVERSE(c) reverse(ALL(c))
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())
#define INF 0x7fffffff
#define X first
#define Y second
#define pb push_back
#define SZ(c) (int)(c).size()
#define MP make_pair
#define eps 1.0e-11
const double pi = acos(-1.0);

typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;

#define N 1024
VI back[N];
int fwd[N];
bool mark[N],mm[N];

int dfs(int v, int except=-1) {
	mark[v]=true;
	int r = 0;
	REP(i,SZ(back[v]))
	{
		int vv = back[v][i];
		if (vv==except) continue;
		if (!mark[vv])
			r = max(r,dfs(vv));
	}
	return r+1;
}

int main(int argc, char **argv)
{
	string FN = "C-large";
	if (argc>1) FN = string(argv[1]);
	int shift = 0;
	if (argc>2) sscanf(argv[2],"%d",&shift);
	freopen((FN+".in").c_str(),"r",stdin);
	freopen((FN+".out").c_str(),"w",stdout);

	int tests;
	scanf("%d",&tests);
	for (int test = 1; test<=tests; test++)
	{
		fprintf(stderr,"=== %s : %d\n", FN.c_str(), test+shift);
		printf("Case #%d: ",test+shift);
		////////////////////////////////////////////////////////////
		int n;
		scanf("%d",&n);
		REP(i,n) back[i].clear();
		REP(i,n) {
			int x;
			scanf("%d",&x);
			--x;
			fwd[i]=x;
			back[x].pb(i);
		}

		CLEAR(mark);
		CLEAR(mm);
		//if (test != 21) continue;
		// pairs
		int res = 0;
		REP(i,n) if (fwd[fwd[i]]==i)
		{
			assert(!mark[i]);
			//back[i].erase(find(ALL(back[i]),fwd[i]));
			//back[fwd[i]].erase(find(ALL(back[i]),i));
			mark[i]=true;
			//mark[fwd[i]]=true;
			res += dfs(i, fwd[i]);
			//res += dfs(fwd[i]);
		}
		// loop
		REP(st,n) if (!mark[st])
		{
			int v = st;
			while (!mm[v])
			{
				mm[v] = true;
				v = fwd[v];
			}
			int x = v;
			int len = 0;
			do {
				x = fwd[x];
				++len;
			} while (x != v);
			dfs(v);
			if (len < 3) { fprintf(stderr,"STRANGE\n"); return 0;}
			if (len>res) {
				fprintf(stderr,"Bump from %d to %d\n",res,len);
				res = len;
			}
		}
		printf("%d\n",res);
	}
	fprintf(stderr,"=== %s DONE\n", FN.c_str());
	return 0;
}
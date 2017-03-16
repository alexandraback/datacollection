#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <memory.h>
#include <ctime>
#include <bitset>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define ABS(a) ((a>0)?a:-(a))
#define MIN(a,b) ((a<b)?(a):(b))
#define MAX(a,b) ((a<b)?(b):(a))
#define FOR(i,a,n) for (int i=(a);i<(n);++i)
#define MEMS(a,b) memset((a),(b),sizeof(a))
#define FI(i,n) for (int i=0; i<(n); ++i)
#define pnt pair <int, int>
#define mp make_pair
#define LL long long
#define U unsigned

int n;
string s1[1010];
string s2[1010];
char S1[30];
char S2[30];
int gr[1010][2];

vector<pair<string,int> > all;
vector<vector<int> > g;
int mt[5010];
int was[5010];

bool dfs(int v)
{
	if (was[v])
		return false;
	was[v] = 1;
	FOR(i, 0, g[v].size())
	{
		int to = g[v][i];
		if ((mt[to] == -1) || (dfs(mt[to])))
		{
			mt[v] = to;
			mt[to] = v;
			return true;
		}
	}
	return false;
}


int main()
{
#ifdef Fcdkbear
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
        double beg = clock();
#else
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
#endif

        int tests;
        scanf("%d",&tests);
        FOR(testNumber, 1, tests+1) {
        	cout<<"Case #"<<testNumber<<": ";
        	cin>>n;
        	FOR(i,0,n) {
        		scanf("%s%s",S1,S2);
        		s1[i] = (string)S1;
        		s2[i] = (string)S2;
        	}
        	all.clear();
        	FOR(i,0,n) {
        		all.push_back(mp(s1[i],i));
        	}
        	sort(all.begin(), all.end());
        	gr[all[0].second][0] = 0;
        	int gr1 = 0;
        	FOR(i,1,all.size()) {
        		if (all[i].first != all[i-1].first)
        			gr1++;
        		gr[all[i].second][0] = gr1;
        	}
        	all.clear();
        	FOR(i,0,n) {
				all.push_back(mp(s2[i],i));
			}
			sort(all.begin(), all.end());
			gr[all[0].second][1] = 0;
			int gr2 = 0;
			FOR(i,1,all.size()) {
				if (all[i].first != all[i-1].first)
					gr2++;
				gr[all[i].second][1] = gr2;
			}
			g.clear();
			g.resize(gr1+1);
			FOR(i,0,n)
				g[gr[i][0]].push_back(g.size() + gr[i][1]);
			MEMS(was,0);
			MEMS(mt,-1);
			int res = n;
			res -= (gr1+gr2+2);
			while (1)
			{
				bool good = false;
				MEMS(was, 0);
				FOR(i,0,g.size())
				if ((mt[i] == -1) && (dfs(i)))
					good = true;
				if (!good)
					break;
			}
			FOR(i,0,g.size())
				res += (mt[i] != -1);
			cout<<res<<endl;
        }

#ifdef Fcdkbear
        double end = clock();
        fprintf(stderr, "*** Total time = %.3lf ***\n", (end - beg) / CLOCKS_PER_SEC);
#endif
        return 0;
}

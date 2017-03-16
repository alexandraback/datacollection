#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <bitset>		//UWAGA - w czasie kompilacji musi byc znany rozmiar wektora - nie mozna go zmienic
#include <cassert>
#include <iomanip>		//do setprecision
#include <ctime>
#include <complex>
using namespace std;

#define FOR(i,b,e) for(int i=(b);i<(e);++i)
#define FORQ(i,b,e) for(int i=(b);i<=(e);++i)
#define FORD(i,b,e) for(int i=(b)-1;i>=(e);--i)
#define REP(x, n) for(int x = 0; x < (n); ++x)

#define ST first
#define ND second
#define PB push_back
#define MP make_pair
#define LL long long
#define ULL unsigned LL
#define LD long double

const double pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342;

#define MR 1010

int srt[MR], wsk;
bool done[MR];
vector < int > g[MR];
int ile[MR];

void dfs(int nr)
{
	done[nr] = 1;
	REP(i,(int)g[nr].size())
		if(!done[g[nr][i]])
			dfs(g[nr][i]);
	srt[wsk++] = nr;
}

bool spr(int i)
{
	ile[srt[i]] = 1;			
	REP(j,(int)g[srt[i]].size())
		ile[g[srt[i]][j]] = 1;
	FORD(j,i,0)
		REP(k,(int)g[srt[j]].size())
		if(ile[g[srt[j]][k]] + ile[srt[j]] > 1)
			return 1;
		else
			ile[g[srt[j]][k]] += ile[srt[j]];
	return 0;
}//spr

int main()
{
	int T;
	scanf("%d", &T);
	REP(c,T)
	{
		int N;
		scanf("%d", &N);
		REP(i,N)
		{
			int M;
			scanf("%d", &M);
			REP(j,M)
			{
				int a;
				scanf("%d", &a);a--;
				g[i].PB(a);
			}
		}
		REP(i,N)
			if(!done[i])
				dfs(i);
		bool found = 0;
		FORD(i,N,0)
		{
			memset(ile,0,sizeof(ile));			
			if(spr(i))
			{
				found = 1;
				break;
			}
		}		
		printf("Case #%d: ", c+1);
		if(found) printf("Yes\n"); else printf("No\n");
		memset(done,0,sizeof(done));		
		REP(i,N) g[i].clear();
		wsk = 0;
	}
	return 0;
}
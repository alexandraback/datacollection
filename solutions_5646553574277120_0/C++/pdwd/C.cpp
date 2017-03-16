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

#define MR 31

bool done[MR];
bool t[MR];

bool check(const vector<int> &v, int V)
{
	memset(t,0,sizeof(t));
	t[0] = 1;
	REP(i,(int)v.size())FORD(j,V-v[i]+1,0)
		if(t[j]) t[j+v[i]] = 1;

	REP(i,V+1) if(!t[i]) return 0;
	return 1;
}

int main()
{
	int T;
	scanf("%d", &T);
	REP(c,T)
	{
		memset(done,0,sizeof(done));

		int C, D, V;
		scanf("%d%d%d", &C, &D, &V);
		vector < int > v;
		REP(i,D)
		{
			int a;
			scanf("%d", &a);
			v.PB(a);
		}
		int res = V;
		REP(mask,1<<20)
		{
			vector<int> v1 = v;
			REP(j,20)
				if(mask&(1<<j))
				{
					if(!done[j]) v1.PB(j+1);
				}
			if(check(v1, V)) res = min(res, (int)v1.size()-D);
		}
		printf("Case #%d: %d\n", c+1, res);
	}
	return 0;
}
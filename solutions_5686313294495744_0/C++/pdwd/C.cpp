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

#define MR 30

pair < string, string > t[MR];

char s[MR], s1[MR];

int go(int N)
{
	int res = 0;
	REP(mask, 1 << N)
	{
		vector <pair < string, string > > ok, faked;
		REP(i, N)
			if (mask&(1 << i))
				faked.push_back(t[i]);
			else
				ok.push_back(t[i]);
		bool bad = 0;
		REP(i, faked.size())
		{
			bool f = 0, s = 0;
			REP(j, ok.size())
			{
				if (ok[j].first == faked[i].first) f = 1;
				if (ok[j].second == faked[i].second) s = 1;
			}
			if (!f || !s)
			{
				bad = 1;
				break;
			}
		}

		if (!bad) res = max(res, (int)faked.size());
	}

	return res;
}

int main()
{
	int T;
	scanf("%d", &T);
	REP(c, T)
	{
		int N;
		scanf("%d", &N);
		REP(i, N)
		{
			scanf("%s%s", s, s1);
			t[i] = MP(string(s), string(s1));
		}
		printf("Case #%d: %d\n", c + 1, go(N));
	}
	return 0;
}
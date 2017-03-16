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

#define MR 20

char C[MR], J[MR];

pair < string, string > go()
{
	int n = strlen(C);
	string rc = "a", rj = "a";
	int dif = 1e9;
	FORQ(a, '0', '9')FORQ(b, '0', '9')FORQ(c, '0', '9')FORQ(d, '0', '9')FORQ(e, '0', '9')FORQ(f, '0', '9')
	{
		string c1 = ""; c1 += a; c1 += b; c1 += c;
		string j1 = ""; j1 += d; j1 += e; j1 += f;
		c1 = c1.substr(0, n);
		j1 = j1.substr(0, n);
		bool bad = 0;
		REP(i,n)
			if ((C[i] != c1[i] && C[i] != '?')
				|| (J[i] != j1[i] && J[i] != '?'))
			{
				bad = 1;
				break;
			}
		if (bad) continue;
		int pd = abs(atoi(c1.c_str()) - atoi(j1.c_str()));
		if (pd < dif || (pd == dif && c1 < rc) || (pd == dif && c1 == rc && j1 < rj))
		{
			dif = pd;
			rc = c1;
			rj = j1;
		}
	}

	return MP(rc, rj);
}

int main()
{
	int T;
	scanf("%d", &T);
	REP(c, T)
	{
		scanf("%s%s", C, J);
		auto res = go();
		printf("Case #%d: %s %s\n", c + 1, res.first.c_str(), res.second.c_str());
	}
	return 0;
}
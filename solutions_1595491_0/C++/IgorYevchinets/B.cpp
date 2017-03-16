
#define _CRT_SECURE_NO_DEPRECATE 

#include <string> 
#include <vector> 
#include <map> 
#include <list> 
#include <set> 
#include <queue> 
#include <iostream> 
#include <sstream> 
#include <stack> 
#include <deque> 
#include <cmath> 
#include <memory.h> 
#include <cstdlib> 
#include <cstdio> 
#include <cctype> 
#include <algorithm> 
#include <utility> 

using namespace std; 

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, N) FOR(i, 0, N)
#define RREP(i, N) RFOR(i, N, 0)

#define ALL(V) V.begin(), V.end()
#define pb push_back
#define mp make_pair
#define EPS 1e-7
#define Pi 3.14159265358979

typedef long long Long;
typedef unsigned long long ULong;
typedef unsigned int Uint;
typedef unsigned char Uchar;
typedef vector <int> VI;
typedef pair <int, int> PI;


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
		
	int tests;

	scanf("%d", &tests);

	REP(I, tests)
	{
		int n, s, p;

		scanf("%d%d%d", &n, &s, &p);

		int res = 0;

		REP(i, n)
		{
			int x;
			scanf("%d", &x);
			int y = x - p;
			if(y < 0)
				continue;
			int a = y / 2;
			int b = (y + 1) / 2;
			if(p - a > 2)
				continue;
			if(p - a == 2 && s)
				++res, --s;
			if(p - a < 2)
				++res;
		}
		printf("Case #%d: %d\n", I + 1, res);
	}
	return 0;
}
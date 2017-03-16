// Alfonso2 Peterssen
#include <cstdio>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>

using namespace std;

#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define SZ(c) ((int)(c).size())
#define FOR(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)

typedef long long int64;

int main()
{
	int testCount;
	cin >> testCount;
	FOR(test, 1, testCount)
	{
		cin >> X >> Y;
		printf( "Case #%d: ", test );
		REP(i, abs(X))
			if (X > 0) printf( "WE" );
			else printf( "EW" );
		REP(i, abs(Y))
			if (Y > 0) printf( "SN" );
			else printf( "NS" );
		printf( "\n" );
	}

	return 0;
}

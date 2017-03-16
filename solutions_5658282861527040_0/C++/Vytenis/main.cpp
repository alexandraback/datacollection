#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <memory.h>
#include <vector>
#include <sstream>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <complex>
 
using namespace std;
 
 
#define REP(a,b) for (int a=0; a<(int)(b); ++a)
#define FOR(a,b,c) for (int a=(b); a<(int)(c); ++a)
 

int main() {
	int t, a, b, k;

	cin >> t;

	REP(tc,t) {
		cin >> a >> b >> k;
		int res = 0;
		REP(i,a) REP(j,b) if ( (i&j) < k ) ++res;

		cout << "Case #" << tc+1 << ": " << res << endl;
	}

	return 0;
} 
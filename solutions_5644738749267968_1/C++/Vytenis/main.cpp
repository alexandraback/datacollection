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
	int t, n, res1, res2;

	cin >> t;

	REP(tc,t) {
		cin >> n;
		vector <double> a(n), b(n);
		REP(i,n) cin >> a[i];
		REP(i,n) cin >> b[i];
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		res1 = 0;
		int p1 = 0, p2 = 0;
		while (p1 < n) {
			while (p1 < n && a[p1] < b[p2]) ++p1;
			if (p1 < n) { ++p1; ++p2; ++res1; }
		}

		res2 = n; p1 = 0; p2 = 0;
		while (p1 < n) {
			while (p2 < n && b[p2] < a[p1]) ++p2;
			if (p2 < n) { ++p2; --res2; }
			++p1;
		}

		cout << "Case #" << tc+1 << ": " << res1 << " " << res2 << endl;
	}

	return 0;
} 
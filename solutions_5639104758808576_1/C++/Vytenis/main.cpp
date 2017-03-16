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
	int t, n, res, standing;
	string s;

	cin >> t;

	REP(tc, t) {
		cin >> n >> s; ++n;
		res = standing = 0;
		REP(i, n) {
			if (standing < i) {
				res += i - standing;
				standing = i;
			}
			standing += s[i] - '0';
		}

		cout << "Case #" << tc + 1 << ": " << res << endl;
	}
	

	return 0;
}
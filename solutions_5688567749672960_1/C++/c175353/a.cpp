#include <cstdio>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <iostream>
using namespace std;

#define FOR(i,a,b) for(int i=int(a);i<=int(b);++i)
#define REP(i,n) FOR(i,0,(n)-1)
typedef long long int64;

string intToStr(int64 x) {
	string s;
	ostringstream oss(s);
	oss << x;
	return oss.str();
}

int64 strToInt(string s) {
	istringstream iss(s);
	int64 x;
	iss >> x;
	return x;
}

int main() {
	int tN;
	cin >> tN;
	FOR(cN, 1, tN) {
		string s;
		int64 n, ans = 0;
		cin >> n;
		if (n % 10 == 0) {
			--n; ++ans;
		}
		s = intToStr(n);
		int digit = s.size();
		FOR(i, 1, digit-1) {
			// 100 -> 999
			int64 base = 1;
			REP(j, i/2) base *= 10;
			// 109
			ans += base-1;
			// 901
			if (i % 2) base *= 10;
			// 1000
			ans += base;
		}
		// 1000 -> 2015
		string s1;
		if (digit > 1) {
			s1 = s.substr(0, digit/2);
			reverse(s1.begin(), s1.end());
			// 1002
			int64 high = strToInt(s1);
			if (high > 1) ans += high;
		}
		// 2001
		s1 = s.substr(digit/2, digit-digit/2);
		// 2015
		ans += strToInt(s1);
		cout << "Case #" << cN << ": " << ans << endl;
	}
}

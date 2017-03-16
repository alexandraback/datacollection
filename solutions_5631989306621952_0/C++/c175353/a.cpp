#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

#define FOR(i,a,b) for (int i=int(a);i<=int(b);++i)
#define REP(i,n) FOR(i,0,(n)-1)
#define PB push_back

string solve(const string& s) {
	int n = s.size();
	char c;
	for (c = 'Z'; c >= 'A'; --c) if (s.find(c) != std::string::npos) {
		int pos = s.find(c);
		// printf("c = %c, pos = %d\n", c, pos);
		string ans;
		if (pos > 0) ans = solve(s.substr(0, pos));
		FOR(i, pos, n-1) {
			if (s[i] == c) ans = s[i] + ans;
			else ans += s[i];
		}
		return ans;
	}
	return "";
}

int main() {
	int tN;
	string s;
	cin >> tN;
	FOR(cN, 1, tN) {
		cin >> s;
		cout << "Case #" << cN << ": " << solve(s) << endl;
	}
}

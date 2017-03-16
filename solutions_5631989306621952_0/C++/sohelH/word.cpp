#include<cstdio>
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<sstream>
#include<cmath>
#include<cctype>
#include<cassert>
#include<cstring>
#include<cstdlib>

using namespace std;

const int debug = 0;
#define DEBUG(x) cout<<">> "<<#x<<':'<<(x)<<endl
const int inf = 1000000000;

string solve(string s) {
	if (s.size() == 0) return s;

	int idx = 0;
	char c = s[0];
	for (int i = 1; i < s.size(); i++) {
		if (s[i] > c) {
			c = s[i];
			idx = i;
		}
	}

	string ss = solve(s.substr(0, idx));

	for (int i = idx; i < s.size(); i++) {
		if (s[i] == c) {
			string tmp = "";
			tmp += c;
			ss = tmp + ss;
		} else {
			ss += s[i];
		}
	}
	return ss;
}

int main() {
	int test, cases = 1;
	cin >> test;
	for (cases = 1; cases <= test; cases++) {
		string s; cin >> s;
		cout << "Case #" << cases << ": " << solve(s) << endl;
	}
	return 0;
}

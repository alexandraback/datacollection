#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;
string doit(string s) {
	string res = "";
	res += s[0];
	for (int i = 1; i < s.size(); ++i) {
		if (s[i] >= res[0]) res = s[i] + res;
		else res = res + s[i];
	}
	return res;
}
int main() {
	int T;
	cin >> T;
	string s;
	for (int t = 1; t <= T; ++t) {
		cin >> s;
		cout << "Case #" << t << ": " << doit(s) << endl;
	}
	return 0;
}
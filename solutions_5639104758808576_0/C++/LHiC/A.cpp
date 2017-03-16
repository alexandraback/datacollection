#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>


typedef long long ll;
typedef long double ld;

using namespace std;


int solve(string s) {
	int ans = 0;
	int now = 0;
	for (int i = 0; i < (int)s.size(); ++i) {
		if (s[i] == '0')
			continue;
		if (now < i)
			ans -= now - i, now = i;
		now += s[i] - '0';
	}
	return ans;
}


int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int n;
		string s;
		cin >> n >> s;
		cout << "Case #" << i + 1 << ": " << solve(s) << "\n";
	}
	return 0;
}



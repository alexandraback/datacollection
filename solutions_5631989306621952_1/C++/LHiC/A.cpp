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

string slv(string s) {
	char mx = 'A';
	for (int i = 0; i < (int)s.size(); ++i)
		mx = max(mx, s[i]);
	for (int i = (int)s.size() - 1; i >= 0; --i)
		if (s[i] == mx) {
			return s[i] + slv(s.substr(0, i)) + s.substr(i + 1);
		}
	return "";
}

void solve() {
	string s;
	cin >> s;
	cout << slv(s) << "\n";
}

int main() {
	int tt;
	scanf("%d", &tt);
	for (int i = 0; i < tt; ++i) {
		printf("Case #%d: ", i + 1);
		solve();
	}
	return 0;
}



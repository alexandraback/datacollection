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

void solve() {
	string s;
	cin >> s;
	int cnt = 0;
	for (int i = 0; i < (int)s.size() - 1; ++i) {
		if (s[i] != s[i + 1])
			++cnt;
	}
	if (s[s.size() - 1] == '-')
		++cnt;
	cout << cnt << "\n";
}

int main() {
	int tt;
	scanf("%d", &tt);
	for (int i = 1; i <= tt; ++i) {
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}



#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

const int NMAX = 10010;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	for (int test = 1; test <= t; test++) {
		int ans = 0;
		int r, c, w;
		cin >> r >> c >> w;
		int perrow = c / w;
		ans = perrow * r + w - (c % w == 0);
		cout << "Case #" << test << ": " << ans << endl;
	}

	return 0;
}
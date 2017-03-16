#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <cstring>
#include <cassert>
#include <ctime>
#include <climits>
#include <bitset>

using namespace std;

int t, r, c, w;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> t;
	for (int jj = 1; jj <= t; jj++) {
		cin >> r >> c >> w;
		if (w == c) {
			cout << "Case #" << jj << ": " << r - 1 + c / w - 1 + w << endl;
		}
		else if (c / w == 1) {
			cout << "Case #" << jj << ": " << r - 1 + w + 1 << endl;
		}
		else {
			cout << "Case #" << jj << ": " << (r - 1) * c / w + c / w - 1 + w + (c % w == 0 ? 0 : 1) << endl;
		}
	}

	return 0;
}
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <utility>

using namespace std;

void solveSingleCase() {
	int B;
	long long M;
	cin >> B >> M;
	long long M_hold = M;

	if (M > (1ll << (B - 2))) {
		cout << " IMPOSSIBLE" << endl;
		return;
	}

	char grid[B][B];
	memset(grid, '0', sizeof(grid));

	grid[B-2][B-1] = '1';
	long long totalWays = 1;
	int firstIndex = B - 2;

	for (firstIndex = B - 3; firstIndex >= 0 && totalWays*2 < M; --firstIndex) {
		for (int j = firstIndex + 1; j < B; ++j) {
			grid[firstIndex][j] = '1';
		}
		totalWays *= 2;
	}
	for (int i = 0; M > 1; ++i) {
		long long bit = 1ll << i;
		if ((M - 1) & bit) {
			grid[firstIndex][B - i - 2] = '1';
			M -= bit;
		}
	}
	if (M == 1) {
		grid[firstIndex][B - 1] = '1';
	}
	if (firstIndex != 0) {
		grid[0][firstIndex] = '1';
	}

	cout << " POSSIBLE" << endl;
	for (int i = 0; i < B; ++i) {
		for (int j = 0; j < B; ++j) {
			cout << (char)grid[i][j];
		}
		cout << endl;
	}

#if 0
	long long paths = 0;
	long long cached[B];
	cached[B - 1] = 1;
	for (int i = B - 2; i >= 0; --i) {
		cached[i] = 0;
		for (int j = B - 1; j > i; --j) {
			if (grid[i][j] == '1') {
				cached[i] += cached[j];
			}
		}
	}
	printf("%lld %lld\n", cached[0], M_hold);
	assert(cached[0] == M_hold);
#endif
}

int main() {
	int T;
	cin >> T;

	for (int i = 1; i <= T; ++i) {
		cout << "Case #" << i << ":";
		solveSingleCase();
	}
	
	return 0;
}

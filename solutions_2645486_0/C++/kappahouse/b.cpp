#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <numeric>

using namespace std;

// name

int dp[10][6];

int doit(vector <int> &v, int index, int energy, int c, int r)
{
	if (index >= v.size()) {
		return 0;
	}
	if (dp[index][energy] >= 0) {
		return dp[index][energy];
	}
	int ret = 0;
	for (int e = 0; e <= energy; e++) {
		ret = max(ret, e * v[index] + doit(v, index + 1, min(c, energy - e + r), c, r));
	}
	return dp[index][energy] = ret;
}

int main()
{
	string line;

	int cases;
	cin >> cases;
	for (int caseno = 1; caseno <= cases; caseno++) {
		int E, R, N;
		cin >> E >> R >> N;
		vector <int> v(N);
		for (int i = 0; i < N; i++) {
			cin >> v[i];
		}
		memset(dp, -1, sizeof(dp));
		int ret = doit(v, 0, E, E, R);
		cout << "Case #" << caseno << ": " << ret << endl;
	}

	return 0;
}

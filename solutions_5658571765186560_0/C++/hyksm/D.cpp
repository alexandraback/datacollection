#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <ctime>
#include <climits>
#include <cfloat>
#include <memory>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <bitset>
#include <queue>
#include <complex>
#include <utility>
#include <functional>
#include <algorithm>
#include <numeric>

using namespace std;

typedef long long ll;

const double EPS = 0.0000000001;
const long long int INF = 1000000000;

int X, R, C;

void solve()
{
	if (X == 1) {
		printf("GABRIEL\n");
	} else if (X == 2) {
		printf("%s\n", R * C % 2 == 0 ? "GABRIEL" : "RICHARD");
	} else if (X == 3) {
		int t[4][4] = {
			{0}, {0, 0}, {0, 1, 1}, {0, 0, 1, 0}
		};
		if (R > C) swap(R, C);
		printf("%s\n", t[C-1][R-1] == 0 ? "RICHARD" : "GABRIEL");
	} else if (X == 4) {
		int t[4][4] = {
			{0}, {0, 0}, {0, 0, 0}, {0, 0, 1, 1}
		};
		if (R > C) swap(R, C);
		printf("%s\n", t[C-1][R-1] == 0 ? "RICHARD" : "GABRIEL");
	} else {
		printf("Z\n");
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; ++t) {
		scanf("%d%d%d", &X, &R, &C);
		printf("Case #%d: ", t+1);
		solve();
	}

	return 0;
}


#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstring>
#include <cmath>
#include <fstream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

int main () {
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		int X, R, C;
		cin >> X >> R >> C;
		bool ok;
		if (X == 1) ok = true;
		if (X == 2) ok = (R * C % 2 == 0);
		if (X == 3) ok = (R >= 2 && C >= 2 && R * C % 3 == 0);
		if (X == 4) ok = (R >= 3 && C >= 3 && R * C % 4 == 0);
		printf("Case #%d: %s\n", t, ok ? "GABRIEL" : "RICHARD");
	}
}
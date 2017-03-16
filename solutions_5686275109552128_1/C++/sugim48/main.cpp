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
		int D; cin >> D;
		vector<int> P(D);
		for (int i = 0; i < D; i++)
			cin >> P[i];
		int mini = INT_MAX;
		for (int x = 1; x <= 1000; x++) {
			int sum = x;
			for (int i = 0; i < D; i++)
				sum += (P[i] + x - 1) / x - 1;
			mini = min(mini, sum);
		}
		printf("Case #%d: %d\n", t, mini);
	}
}
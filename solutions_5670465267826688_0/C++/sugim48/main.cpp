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

int a[4][4] = {
	{0, 1, 2, 3},
	{1, 4, 3, 6},
	{2, 7, 4, 1},
	{3, 2, 5, 4}
};

int f(int x, int y) {
	return (x & 4) ^ (y & 4) ^ a[x % 4][y % 4];
}

int main () {
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		int L; ll X; cin >> L >> X;
		string s; cin >> s;
		bool yes = false;
		int x = 0;
		for (int i = 0; i < L; i++)
			x = f(x, s[i] - 'h');
		int y = 0;
		for (int j = 0; j < X % 4; j++)
			y = f(y, x);
		if (y == 4) {
			x = 0; ll l = LLONG_MAX;
			for (int i = 0; i < L * 4; i++) {
				if (x == 1) {
					l = i;
					break;
				}
				x = f(x, s[i % L] - 'h');
			}
			reverse(s.begin(), s.end());
			x = 0; ll r = LLONG_MIN;
			for (int i = 0; i < L * 4; i++) {
				if (x == 3) {
					r = X * L - i;
					break;
				}
				x = f(s[i % L] - 'h', x);
			}
			if (l < r) yes = true;
		}
		printf("Case #%d: %s\n", t, yes ? "YES" : "NO");
	}
}
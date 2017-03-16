#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
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

int main() {
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		int N, J; cin >> N >> J;
		int n = N / 2;
		printf("Case #%d:\n", t);
		for (ll S = 0; S < J; S++) {
			string s(n, '0');
			s[0] = s[n - 1] = '1';
			for (int i = 0; i < n - 2; i++)
				if ((S>>i) & 1)
					s[i + 1] = '1';
			cout << s + s;
			for (int k = 2; k <= 10; k++) {
				ll x = 1;
				for (int i = 0; i < n; i++)
					x = x * k;
				cout << ' ' << x + 1;
			}
			cout << endl;
		}
	}
}

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
		int K, C, S; cin >> K >> C >> S;
		vector<ll> a;
		for (int k = 0; k < K;) {
			ll x = 0;
			for (int c = 0; c < C; c++)
				x = x * K + min(K - 1, k++);
			a.push_back(x);
		}
		printf("Case #%d:", t);
		if (a.size() <= S)
			for (ll x: a)
				cout << ' ' << x + 1;
		else cout << " IMPOSSIBLE";
		cout << endl;
	}
}

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

ll f(string& s, string& t) {
	ll x = 0, y = 0;
	for (char c: s) x = x * 10 + (c - '0');
	for (char c: t) y = y * 10 + (c - '0');
	return abs(x - y);
}

int main() {
	int T; cin >> T;
	for (int _t = 1; _t <= T; _t++) {
		string S, T; cin >> S >> T;
		int N = S.length();
		pair<ll, pair<string, string> > ans;
		ans.first = LLONG_MAX;
		for (int l = 0; l < N; l++) {
			bool ok = true;
			for (int i = 0; i < l; i++) {
				char &c = S[i], &d = T[i];
				if (c == '?' && d == '?') c = '0', d = '0';
				else if (c == '?' && d != '?') c = d;
				else if (c != '?' && d == '?') d = c;
				else if (c != d) ok = false;
			}
			if (!ok) break;
			for (int x = '0'; x <= '9'; x++)
				for (int y = '0'; y <= '9'; y++)
					for (int z = 0; z <= 1; z++) {
						string s = S, t = T;
						if (s[l] == x || s[l] == '?') s[l] = x;
						else continue;
						if (t[l] == y || t[l] == '?') t[l] = y;
						else continue;
						for (int i = l + 1; i < N; i++) {
							if (s[i] == '?') s[i] = (z ? '0' : '9');
							if (t[i] == '?') t[i] = (z ? '9' : '0');
						}
						ans = min(ans, make_pair(f(s, t), make_pair(s, t)));
					}
		}
		printf("Case #%d: ", _t);
		cout << ans.second.first << ' ' << ans.second.second << endl;
	}
}

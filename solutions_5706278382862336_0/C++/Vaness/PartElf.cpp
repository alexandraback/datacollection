#include <iostream>
#include <cstdio>
#include <fstream>

#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <utility>
#include <string>
#include <cstring>

#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <memory.h>
using namespace std;

#define fr(i, n) for (int i = 0; i < (int)(n); i++)
#define fb(i, n) for (int i = n - 1; i >= 0; i--)
#define all(a) (a).begin(), (a).end()
#define _(a, b) memset(a, b, sizeof(a))
#define mp make_pair
#define pb push_back
#define sz(v) ((int)(v).size())

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;

inline int ni() { int a; scanf("%d", &a); return a; }
inline double nf() { double a; scanf("%lf", &a); return a; }
template <class T> void out(T a, T b) { bool first = true; for (T i = a; i != b; i++) { if (!first) printf(" "); first = false; cout << *i; } puts(""); }
template <class T> void outl(T a, T b) { for (T i = a; i != b; i++) cout << *i << "\n"; } 

ll gcd(ll x, ll y) {
	while (x) {
		y %= x;
		swap(x, y);
	}
	return y;
}

int T;
ll P, Q;
string s;
int ans;

int solve() {
	//cin >> P >> Q;
	cin >> s;
	P = 0, Q = 0;
	int dd = 0;
	while (s[dd] != '/') {
		P *= 10;
		P += s[dd++] - '0';
	}
	dd++;
	while (dd < sz(s)) {
		Q *= 10;
		Q += s[dd++] - '0';
	}
	ll g = gcd(P, Q);
	P /= g;
	Q /= g;

	ll z = 1;
	int c = 0;
	while (z < Q) {
		z <<= 1;
		c++;
	}
	if (z != Q) {
		return -1;
	}
	//return c;		
	c = 0;
	while (P < Q) {
		c++;
		P <<= 1;
	}
	return c;
}

int main() {
	freopen("partelf.in", "r", stdin);
	freopen("partelf.out", "w", stdout);
	cin >> T;
	fr(test, T) {
		ans = solve();
		if (ans == -1)
			printf("Case #%d: impossible\n", test + 1);
		else
			printf("Case #%d: %d\n", test + 1, ans);
	}	       	
}
        
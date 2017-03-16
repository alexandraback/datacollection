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

const int MAXN = 800;

int T;
int N, X, Y;
ll cur, level;
double d[MAXN][MAXN], next[MAXN][MAXN];
    
double solve() {
	N = ni(); 	
	X = ni(); Y = ni();
	X = abs(X);
	level = (X + Y) / 2 - 1;
	cur = N - ((level + 1) * 1 + 2 * level * (level + 1));
	if (cur <= 0)
		return 0.0;
	if (Y + 1 > cur)
		return 0.0;
	level++;
	if (cur >= 1 + 4 * level) {
		return 1.0;
	}
	_(d, 0);
	d[1][0] = d[0][1] = 0.5;
	for (int i = 2; i <= cur; i++) {
		for (int j = 0; j < 2 * level + 1; j++) {
			if (j > i - 1)
				continue;
			int rest = i - 1 - j;
			if (j + 1 < 2 * level + 1 && rest + 1 < 2 * level + 1) {
				d[j + 1][rest] += 0.5 * d[j][rest];
				d[j][rest + 1] += 0.5 * d[j][rest];
			} else {
				if (rest + 1 < 2 * level + 1)
					d[j][rest + 1] += d[j][rest];
				else
					d[j + 1][rest] += d[j][rest];
			}
		}
	}
	double ans = 0;
	for (int j = 0; j < 2 * level + 1; j++) {
		if (j >= Y + 1 && cur - j < 2 * level + 1)
			ans += d[j][cur - j];
	}
	return ans;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	T = ni();
	fr(test, T) {
		printf("Case #%d: %.10lf\n", test + 1, solve());
	}	  
}
        
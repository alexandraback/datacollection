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

int T;
int N, M, K;

int solve() {
	cin >> N >> M >> K;
	int best = K;
	int cur, val;
	for (int x = 1; x < N; x++) {
		for (int y = 1; y < M; y++) {
			cur = (x + 1) * (y + 1);
			val = 2 * (y + 1) + 2 * (x - 1);
			if (cur >= K)
				best = min(best, val);		
			if (x > 1) {
				cur--;
				val--;
				if (cur >= K)
					best = min(best, val);
				cur--;
				val--;
				if (cur >= K)
					best = min(best, val);
			}
			if (y > 1) {
				cur--;
				val--;
				if (cur >= K)
					best = min(best, val);
   	
				cur--;
				val--;
				if (cur >= K)
					best = min(best, val);
			}
		}
	}
	return best;
}

int main() {
	freopen("enclosure.in", "r", stdin);
	freopen("enclosure.out", "w", stdout);  
	T = ni();
	fr(test, T)
		printf("Case #%d: %d\n", test + 1, solve());
}
        
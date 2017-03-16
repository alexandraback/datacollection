#define _CRT_SECURE_NO_DEPRECATE
#pragma comment(linker, "/STACK:128777216")

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <sstream>

#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <queue>
#include <deque>
#include <stack>

#include <math.h>
#include <cmath>
#include <string>
#include <cstring>
#include <string.h>

#include <memory.h>
#include <cassert>
#include <time.h>

using namespace std;

#define forn(i,n) for (int i = 0; i < (int)(n); i++)
#define fornd(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i,a,b) for (int i = (int)(a); i <= (int)(b); i++)
#define forabd(i, b, a) for (int i = (int)(b); i >= (int)(a); i--)
#define forit(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)

#define _(a, val) memset (a, val, sizeof (a))
#define sz(a) (int)((a).size())
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()

typedef long long lint;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vii;

const lint LINF = 1000000000000000000LL;
const int INF = 1000000000;
const long double eps = 1e-9;
const long double PI = 3.1415926535897932384626433832795l;

#ifdef MY_DEBUG
#define dbgx( x ) { cerr << #x << " = " << x << endl; }
#define dbg( ... ) { fprintf(stderr, __VA_ARGS__); fflush(stderr); }
#else
#define dbgx( x ) {  } 
#define dbg( ... ) {  } 
#endif

void prepare(string s) {
#ifdef MY_DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	//freopen("input.txt", "r", stdin);
	//freopen ("output.txt", "w", stdout);
#endif
}

int A, B, C, K;

struct Result {
  int a[3];
};

bool operator==(const Result &a, const Result &b) {
  return a.a[0] == b.a[0] && a.a[1] == b.a[1] && a.a[2] == b.a[2];
}

void read() {
  scanf("%d %d %d %d", &A, &B, &C, &K);
}

vector<Result> fun() {
  vector<Result> res;
  for (int k = 0; k < K; ++k) {
    for (int i = 0; i < A; ++i) {
      for (int j = 0; j < B; ++j) {
        Result cur;
        cur.a[0] = i;
        cur.a[1] = j;
        cur.a[2] = (i + j + k) % C;
        if (find(all(res), cur) != res.end())
          return res;
        res.pb(cur);
      }
    }
  }
  return res;
}

void solve() {
  auto res = fun();
  printf("%d\n", sz(res));
  for (auto e : res) {
    printf("%d %d %d\n", e.a[0] + 1, e.a[1] + 1, e.a[2] + 1);
  }
}

int main() {
	prepare("");
	int t;
	scanf("%d", &t);
	forn(i, t) {
		printf("Case #%d: ", i + 1);
		read();
		solve();
	}
	dbg("Clock = %.3f\n", clock() / (double)CLOCKS_PER_SEC);
	return 0;
}


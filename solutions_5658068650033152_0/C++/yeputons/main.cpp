#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <iostream>

#define pb push_back
#define mp make_pair
//#define TASKNAME ""

#ifdef DEBUG
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("[" #x "] Time = %.3lfs\n",clock()*1.0/CLOCKS_PER_SEC)

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

#define sz(x) ((int)(x).size())

using namespace std;

typedef long double ld;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;
typedef pair <ll, ll> pll;
typedef vector<pii> vpii;

//const int inf = 1e9;
const double eps = 1e-7;
//const int INF = inf;
const double EPS = eps;

#ifdef DEBUG
struct __timestamper {
	~__timestamper(){
		TIMESTAMP(end);
	}
} __Timestamper;
#else
struct __timestamper {};
#endif

/*Template end*/

void solve() {
  int h, w, k;
  scanf("%d%d%d", &h, &w, &k);

  int ans = 1e9;
  vvb af;
  for (int m = 0; m < (1 << (h * w)); m++) {
    vvb f(h, vb(w));
    for (int y = 0; y < h; y++)
    for (int x = 0; x < w; x++)
      f[y][x] = (m >> (y * w + x)) & 1;

    vvb was(h, vb(w));
    deque<pii> q;
    for (int y = 0; y < h; y++)
    for (int x = 0; x < w; x++) if (!f[y][x]) {
      if (x == 0 || x == w - 1 || y == 0 || y == h - 1) {
        q.pb(mp(x, y));
        was[y][x] = true;
      }
    }

    int wcnt = 0;
    while (!q.empty()) {
      wcnt++;
      int x = q.front().first;
      int y = q.front().second;
      q.pop_front();
      for (int i = 0; i < 4; i++) {
        const int dx[] = { 1, 0, -1, 0 };
        const int dy[] = { 0, 1, 0, -1 };
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= w || ny >= h) continue;
        if (f[ny][nx]) continue;
        if (was[ny][nx]) continue;
        was[ny][nx] = true;
        q.pb(mp(nx, ny));
      }
    }
    if (wcnt <= h * w - k) {
      int cans = __builtin_popcount(m);
      if (cans < ans) {
        ans = cans;
        af = f;
      }
    }
  }
  printf("%d\n", ans);
  for (int y = 0; y < h; y++)
  for (int x = 0; x < w; x++)
    eprintf("%d%c", !!af[y][x], "\n "[x + 1 < w]);
}

bool endsWith(string a, string b) {
  return a.length() >= b.length() && string(a, a.length() - b.length()) == b;
}

int main(int argc, char *argv[]) {
  {
    string fn = "";
    if (argc >= 2) fn = argv[1];
    if (endsWith(fn, ".in")) fn = string(fn, 0, fn.length() - 3);
    freopen((fn + ".in").c_str(), "r", stdin);
    freopen((fn + ".out").c_str(), "w", stdout);
  }

  int TC;
  assert(scanf("%d", &TC) >= 1);
  for (int TN = 1; TN <= TC; TN++) {
    eprintf("Case #%d:\n", TN);
    printf("Case #%d: ", TN);
    try {
      solve();
    } catch (...) {
      eprintf("Caught exception at test case #%d\n", TN);
      return 1;
    }
  }
  return 0;
}

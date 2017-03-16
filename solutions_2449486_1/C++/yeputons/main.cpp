#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <map>
#include <set>

using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())

typedef long long ll;

typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

void solve() {
  int h, w;
  scanf("%d%d", &h, &w);
  vvi f(h, vi(w));
  for (int y = 0; y < h; y++)
  for (int x = 0; x < w; x++)
    scanf("%d", &f[y][x]);

  vi incol(w, 0), inrow(h, 0);
  for (int y = 0; y < h; y++)
  for (int x = 0; x < w; x++) {
    incol[x] = max(incol[x], f[y][x]);
    inrow[y] = max(inrow[y], f[y][x]);
  }

  bool g = true;
  for (int y = 0; y < h; y++)
  for (int x = 0; x < w; x++)
    if (f[y][x] != min(incol[x], inrow[y]))
      g = false;
  printf(g ? "YES\n" : "NO\n");
}

bool endsWith(string a, string b) {
  return a.length() >= b.length() && string(a, a.length() - b.length()) == b;
}

int main(int argc, char *argv[]) {
  {
    string fn = "std";
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
      eprintf("Catched exception at test case #%d\n", TN);
      return 1;
    }
  }
  return 0;
}

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

const int h = 4;
const int w = 4;

void solve() {
  char f[h][w + 1];
  for (int y = 0; y < h; y++)
    scanf("%s", f[y]);

  bool won[2] = { false };
  int emcnt = 0;
  for (int y = 0; y < h; y++)
  for (int x = 0; x < w; x++) {
    emcnt += f[y][x] == '.';

    const int dx[] = { 1, 1, 1, 0 };
    const int dy[] = { -1, 0, 1, 1 };
    for (int d = 0; d < 4; d++) {
      const char *cs = "XOT.";
      int cnts[4] = { 0 };
      for (int i = 0; i < 4; i++) {
        int nx = x + dx[d] * i;
        int ny = y + dy[d] * i;
        if (nx < 0 || ny < 0 || nx >= w || ny >= h) continue;
        cnts[find(cs, cs + 4, f[ny][nx]) - cs]++;
      }
      if (cnts[0] == 4 || (cnts[0] == 3 && cnts[2] == 1)) won[0] = true;
      if (cnts[1] == 4 || (cnts[1] == 3 && cnts[2] == 1)) won[1] = true;
    }
  }
  if (won[0]) printf("X won\n");
  else if (won[1]) printf("O won\n");
  else if (emcnt > 0) printf("Game has not completed\n");
  else printf("Draw\n");
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

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <set>
using namespace std;

const int MAX_N = 20;
const int MAX_KEYS = 400;

int k;
int n;
int tt[MAX_N];  // required key type to open chest[i]
int kk[MAX_N];  // num keys inside chest[i]
int s[MAX_N][MAX_N];  // keys inside chest[i]

int a[MAX_N];
int d[MAX_N];
int w[MAX_N];
bool v[MAX_N];
struct State {
  unsigned char z[25];
  bool operator < (const State& o) const {
    for (int i = 0; i < 25; ++i) {
      if (z[i] != o.z[i])
        return z[i] < o.z[i];
    }
    return false;
  }
} u;
set<State> uu;

void print_solution() {
  for (int i = 0; i < n; ++i) {
    if (i > 0)
      putchar(' ');
    printf("%d", w[i] + 1);
  }
}

bool impossible() {
  for (int i = 0; i < n; ++i) {
    if (a[i] < 0)
      return true;
  }
  return false;
}

bool solve(int depth) {
  for (int i = 0; i < n; ++i) {
    if (v[i]) continue;
    if (!d[tt[i]]) continue;
    w[depth] = i;
    if (depth + 1 == n)
      return true;
    u.z[i / 8] ^= 1 << i % 8;
    if (uu.find(u) != uu.end()) {
      u.z[i / 8] ^= 1 << i % 8;
      continue;
    }
    uu.insert(u);
    --d[tt[i]];
    for (int j = 0; j < kk[i]; ++j)
      ++d[s[i][j]];
    v[i] = true;
    if (solve(depth + 1))
      return true;
    ++d[tt[i]];
    for (int j = 0; j < kk[i]; ++j)
      --d[s[i][j]];
    v[i] = false;
    u.z[i / 8] ^= 1 << i % 8;
    // this was wrong
    //if (s[i][tt[i]] > 0)
    //    break;
  }
  return false;
}

int main() {
  int num_tests = 0;
  scanf("%d", &num_tests);
  for (int test = 1; test <= num_tests; ++test) {
    //fprintf(stderr, "Case #%d\n", test);
    memset(a, 0, sizeof(d));
    memset(d, 0, sizeof(d));
    memset(v, 0, sizeof(v));
    memset(&u, 0, sizeof(u));
    uu.clear();
    scanf("%d%d", &k, &n);
    int t;
    for (int i = 0; i < k; ++i) {
      scanf("%d", &t);
      --t;
      ++d[t];
      ++a[t];
    }
    for (int i = 0; i < n; ++i) {
      scanf("%d%d", &tt[i], &kk[i]);
      --tt[i];
      --a[tt[i]];
      for (int j = 0; j < kk[i]; ++j) {
        scanf("%d", &s[i][j]);
        --s[i][j];
        ++a[s[i][j]];
      }
    }
    printf("Case #%d: ", test);
    if (impossible())
      printf("IMPOSSIBLE");
    else if (solve(0))
      print_solution();
    else
      printf("IMPOSSIBLE");
    printf("\n");
  }
  return 0;
}

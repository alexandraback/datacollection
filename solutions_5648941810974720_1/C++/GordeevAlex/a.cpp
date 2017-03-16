#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <ctime>
#include <cmath>
#include <complex>
#include <cassert>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef long double ld;

long long rdtsc() {
  long long tmp;
  asm("rdtsc" : "=A"(tmp));
  return tmp;
}

inline int myrand() {
  return abs((rand() << 15) ^ rand());
}

inline int rnd(int x) {
  return myrand() % x;
}

#define pb push_back
#define mp make_pair
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stdout)
#define sz(x) ((int)(x).size())
#define TASKNAME ""

void precalc() {
}

const int l = 26;
const int k = 10;
const string names[k] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

const int maxn = 3e3 + 10;

int n;
char s[maxn];

bool read() {
  if (scanf("%s", s) < 1) {
    return false;
  }
  n = strlen(s);
  return true;
}

int a[l];

bool used[k];

int ans[k];

int mark[l];

void solve() {
  memset(a, 0, sizeof(a));
  for (int i = 0; i < n; ++i) {
    assert(isupper(s[i]));
    ++a[s[i] - 'A'];
  }

  memset(used, 0, sizeof(used));
  memset(ans, 0, sizeof(ans));
  int m = 10;
  while (m > 0) {
    memset(mark, -1, sizeof(mark));
    for (int i = 0; i < k; ++i) {
      if (used[i]) {
        continue;
      }
      for (int j = 0; j < sz(names[i]); ++j) {
        int cur = names[i][j] - 'A';
        if (mark[cur] == -1 || mark[cur] == i) {
          mark[cur] = i;
        } else {
          mark[cur] = -2;
        }
      }
    }

    for (int i = 0; i < l; ++i) {
      if (mark[i] >= 0) {
        int j = mark[i];
        if (used[j]) {
          assert(a[i] == 0);
          continue;
        }
        used[j] = true;
        --m;
        while (a[i] > 0) {
          ++ans[j];
          for (int q = 0; q < sz(names[j]); ++q) {
            int cur = names[j][q] - 'A';
            assert(a[cur] > 0);
            --a[cur];
          }
        }
      }
    }
  }

  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < ans[i]; ++j) {
      printf("%d", i);
    }
  }
  printf("\n");
}

int main() {
  srand(rdtsc());
#ifdef LOCAL 
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#else
//  freopen(TASKNAME".in", "r", stdin);
//  freopen(TASKNAME".out", "w", stdout);
#endif

  precalc();

  int T;
  scanf("%d", &T);
  for (int tn = 1; tn <= T; ++tn) {  
    assert(read());
    printf("Case #%d: ", tn);
    solve();
#ifdef LOCAL
    eprintf("%.18f\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}



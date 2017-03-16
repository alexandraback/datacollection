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

const int maxn = 1010;
int k;
int n[2];
map<string, int> ids[2];

vector<int> to[maxn];
int mark[maxn];

char s[maxn];

bool read() {
  if (scanf("%d", &k) < 1) {
    return false;
  }
  for (int i = 0; i < maxn; ++i) {
    to[i].clear();
    mark[i] = -1;
  }
  n[0] = n[1] = 0;
  ids[0].clear();
  ids[1].clear();
  for (int i = 0; i < k; ++i) {
    int a[2];
    for (int j = 0; j < 2; ++j) {
      scanf("%s", s);
      string cur = string(s);
      auto it = ids[j].find(cur);
      if (it != ids[j].end()) {
        a[j] = it->second;
      } else {
        a[j] = n[j];
        ids[j][cur] = n[j]++;
      }
    }

    to[a[0]].pb(a[1]);
  }
  return true;
}

int used[maxn];
int T;

bool dfs(int v) {
  used[v] = T;
  for (auto u : to[v]) {
    if (mark[u] == -1 || (used[mark[u]] < T && dfs(mark[u]))) {
      mark[u] = v;
      return true;
    }
  }
  return false;
}

void solve() {
  int cnt = 0;
  memset(used, 0, sizeof(used));
  T = 0;
  for (int i = 0; i < n[0]; ++i) {
    ++T;
    if (dfs(i)) {
      ++cnt;
    }
  }
  printf("%d\n", k - (n[0] + n[1] - cnt));
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





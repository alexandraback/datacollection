#include <bits/stdc++.h>

using namespace std;

struct outfit {
  int j, p, s;
  outfit(int _j, int _p, int _s) {
    j = _j;
    p = _p;
    s = _s;
  }
};

int j, p, s, k;
vector<outfit> allOutfits;

bool check(int bm) {
  int a[4][4], b[4][4], c[4][4];
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      a[i][j] = b[i][j] = c[i][j] = 0;
    }
  }
  for (int i = 0; i < int(allOutfits.size()); i++) if (bm&(1<<i)) {
    a[allOutfits[i].j][allOutfits[i].p]++;
    b[allOutfits[i].j][allOutfits[i].s]++;
    c[allOutfits[i].p][allOutfits[i].s]++;
  }
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (a[i][j] > k) return false;
      if (b[i][j] > k) return false;
      if (c[i][j] > k) return false;
    }
  }
  return true;
}

void solve() {
  scanf("%d%d%d%d", &j, &p, &s, &k);
  allOutfits.clear();
  for (int _j = 1; _j <= j; _j++) {
    for (int _p = 1; _p <= p; _p++) {
      for (int _s = 1; _s <= s; _s++) {
        allOutfits.push_back(outfit(_j, _p, _s));
      }
    }
  }
  int bbm = 0;
  for (int bm = 0; bm < (1<<(int(allOutfits.size()))); bm++) {
    //printf("%d: %d\n", bm, check(bm));
    if (check(bm) && __builtin_popcount(bm) > __builtin_popcount(bbm)) {
      bbm = bm;
    }
  }
  printf("%d\n", __builtin_popcount(bbm));
  for (int i = 0; i < int(allOutfits.size()); i++) if (bbm&(1<<i)) {
    printf("%d %d %d\n", allOutfits[i].j, allOutfits[i].p, allOutfits[i].s);
  }
}

int main() {
  int t; scanf("%d", &t);
  for (int ct = 1; ct <= t; ct++) {
    printf("Case #%d: ", ct);
    solve();
  }
  return 0;
}

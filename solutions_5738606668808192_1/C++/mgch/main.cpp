#include <stdio.h>
#include <algorithm>
#include <assert.h>
#include <set>
#include <map>
#include <complex>
#include <iostream>
#include <time.h>
#include <stack>
#include <stdlib.h>
#include <memory.h>
#include <bitset>
#include <math.h>
#include <string>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;

const int MaxN = 2e8 + 10;
const int INF = 1e9;
const int MOD = 1e9 + 7;

vector < unsigned > masks;
vector < vector < int > > all;
int lp[MaxN], pr[MaxN / 10], sz;

int prime(long long n) {
  if (n < MaxN) {
    if (lp[n] != n) {
      return lp[n];
    }
    return 0;
  }
  for (int i = 0; i < sz && 1LL * pr[i] * pr[i] <= n; ++i) {
    if (n % pr[i] == 0) {
      return pr[i];
    }
  }
  return 0;
}

void gen(int len) {
  for (int i = 2; i < MaxN; ++i) {
    if (!lp[i]) {
      lp[i] = pr[sz++] = i;
    }
    for (int j = 0; j < sz && i * pr[j] < MaxN && pr[j] <= lp[i]; ++j) {
      lp[i * pr[j]] = pr[j];
    }
  }
  for (unsigned mask = (1U << 31); mask != 0; ++mask) {
    if (~mask & 1) {
      continue;
    }
    bool ok = true;
    vector < int > cur;
    for (int base = 2; base <= 10 && ok; ++base) {
      bool now = false;
      for (int it = 0; it < 50; ++it) {
        long long val = 0;
        for (int i = 0; i < len; ++i) {
          val = (val * base + (mask >> i) % 2) % pr[it];
        }
        if (val == 0) {
          cur.push_back(pr[it]);
          now = true;
          break;
        }
      }
      ok &= now;
    }
    if (ok == true) {
      masks.push_back(mask);
      all.push_back(cur);
    }
    if ((int)masks.size() == 500) {
      break;
    }
  }
  for (int i = 0; i < (int)masks.size(); ++i) {
    for (int it = 0; it < len; ++it) {
      cout << (masks[i] >> it) % 2;
    }
    for (int j = 0; j < 9; ++j) {
      cout << " " << all[i][j];
    }
    cout << "\n";
  }
}

int main() {
//  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cout << "Case #1:\n";
  gen(32);
/*  int t;
  scanf("%d", &t);
  for (int it = 1; it <= t; ++it) {
    printf("Case #%d: ", it);
    int n, j;
    scanf("%d%d", &n, &j);
  }*/
/*  cout << "Case #1:\n";
  for (int i = 0; i < 500; ++i) {
    for (int j = 0; j < 10; ++j) {
      cout << arr[i][j] << (j == 9 ? '\n' : ' ');
    }
  }*/
  return 0;
}


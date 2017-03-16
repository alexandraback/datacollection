#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

typedef long long LL;

char s[8][3] = {"1", "-1", "i", "-i", "j", "-j", "k", "-k"};

int table[8][8];

void init() {
  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      table[i][j] = i ^ j;
      if (i >= 2 && j >= 2 && ((i >> 1) - (j >> 1) + 1) % 3 != 0) {
        table[i][j] ^= 1;
      }
    }
  }
}

int id(char c) {
  return 2 * (c - 'i' + 1);
}

bool solve(string s, LL l, LL x) {
  LL iI, jI = -1, iJ, jJ = -1, iK, jK = -1;
  LL p = min(x, 4LL);
  int now = 0;
  for (LL i = 0; i < p; ++i) {
    bool found = false;
    for (LL j = 0; j < l; ++j) {
      now = table[now][id(s[j])];
      if (now == id('i')) {
        iI = i, jI = j;
        found = true;
        break;
      }
    }
    if (found)
      break;
  }
  if (jI == -1)
    return false;
  now = 0;
  for (LL i = 0; i < p; ++i) {
    bool found = false;
    for (LL j = l - 1; j >= 0; --j) {
      now = table[id(s[j])][now];
      if (now == id('k')) {
        iK = i, jK = j;
        found = true;
        break;
      }
    }
    if (found)
      break;
  }
  if (jK == -1)
    return false;
  if (iI + iK >= x)
    return false;
  now = 0;
  if (iI + iK + 1 == x) {
    for (LL j = jI + 1; j < jK; ++j) {
      now = table[now][id(s[j])];
    }
  } else {
    for (LL j = jI + 1; j < l; ++j) {
      now = table[now][id(s[j])];
    }
    x -= iI + 1 + iK + 1;
    x %= 4;
    for (LL i = 0; i < x; ++i) {
      for (LL j = 0; j < l; ++j) {
        now = table[now][id(s[j])];
      }
    }
    for (LL j = 0; j < jK; ++j) {
      now = table[now][id(s[j])];
    }
  }
  return now == id('j');
}

int main() {
  init();
  int cases;
  scanf("%d", &cases);
  for (int T = 0; T < cases; ++T) {
    LL L, X;
    scanf("%lld %lld", &L, &X);
    string s;
    cin >> s;
    printf("Case #%d: %s\n", T + 1, solve(s, L, X) ? "YES" : "NO");
  }
  return 0;
}
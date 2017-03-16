#include <cstdio>
#include <deque>
#include <queue>
#include <stack>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <bitset>
#include <list>
#include <set>
#include <map>

using namespace std;

const int N = 22;

inline long long diff(long long a, long long b) {
  long long z = a - b;
  return (z < 0) ? -1 * z : z;
}

long long mn;
long long mnx, mny;
string resx, resy;
string x, y;

inline void solve(long long px, long long py, int pos, int n) {
  if (pos == n) {
    if (mn > diff(px, py)) {
      mn = diff(px, py);
      resx = x;
      resy = y;
      mnx = px;
      mny = py;
    } else if (mn == diff(px, py)) {
      if (px < mnx) {
        resx = x;
        resy = y;
        mnx = px;
        mny = py;
      } else if (px == mnx) {
        if (py < mny) {
          resx = x;
          resy = y;
          mnx = px;
          mny = py;
        }
      }
    }
  } else {
    char cx = x[pos], cy = y[pos];
    if(x[pos] == '?' || y[pos] == '?') {
      if (x[pos] == '?' && y[pos] != '?') {
        if (px < py) {
          x[pos] = '9';
          solve(px * 10 + (x[pos] - '0'), py * 10 + (y[pos] - '0'), pos + 1, n);
        } else if (px == py) {
          if (y[pos] + 1 <= '9') {
            x[pos] = y[pos] + 1;
            solve(px * 10 + (y[pos] - '0' + 1), py * 10 + (y[pos] - '0'), pos + 1, n);
            x[pos] = '?';
          }
          if (y[pos] - 1 >= '0') {
            x[pos] = y[pos] - 1;
            solve(px * 10 + (y[pos] - '0' - 1), py * 10 + (y[pos] - '0'), pos + 1, n);
            x[pos] = '?';
          }
          x[pos] = y[pos];
          solve(px * 10 + (y[pos] - '0'), py * 10 + (y[pos] - '0'), pos + 1, n);
        } else {
          x[pos] = '0';
          solve(px * 10 + (x[pos] - '0'), py * 10 + (y[pos] - '0'), pos + 1, n);
        }
      } else if (x[pos] != '?' && y[pos] == '?') {
        if (px < py) {
          y[pos] = '0';
          solve(px * 10 + (x[pos] - '0'), py * 10 + (y[pos] - '0'), pos + 1, n);
        } else if (px == py) {
          if (x[pos] + 1 <= '9') {
            y[pos] = x[pos] + 1;
            solve(px * 10 + (x[pos] - '0'), py * 10 + (x[pos] - '0' + 1), pos + 1, n);
            y[pos] = '?';
          }
          if (x[pos] - 1 >= '0') {
            y[pos] = x[pos] - 1;
            solve(px * 10 + (x[pos] - '0'), py * 10 + (x[pos] - '0' - 1), pos + 1, n);
            y[pos] = '?';
          }
          y[pos] = x[pos];
          solve(px * 10 + (x[pos] - '0'), py * 10 + (x[pos] - '0'), pos + 1, n);
        } else {
          y[pos] = '9';
          solve(px * 10 + (x[pos] - '0'), py * 10 + (y[pos] - '0'), pos + 1, n);
        }
      } else {
        if (px < py) {
          y[pos] = '0';
          x[pos] = '9';
          solve(px * 10 + (x[pos] - '0'), py * 10 + (y[pos] - '0'), pos + 1, n);
        } else if (px == py) {
          x[pos] = '1';
          y[pos] = '0';
          solve(px * 10 + 1, py * 10 + 0, pos + 1, n);
          x[pos] = '0';
          y[pos] = '1';
          solve(px * 10 + 0, py * 10 + 1, pos + 1, n);
          x[pos] = '0';
          y[pos] = '0';
          solve(px * 10, py * 10, pos + 1, n);
        } else {
          y[pos] = '9';
          x[pos] = '0';
          solve(px * 10 + (x[pos] - '0'), py * 10 + (y[pos] - '0'), pos + 1, n);
        }
      }
    } else {
      solve(px * 10 + (x[pos] - '0'), py * 10 + (y[pos] - '0'), pos + 1, n);
    }
    x[pos] = cx;
    y[pos] = cy;
  }
}

char c[N], j[N];

int main() {
  freopen("input.in", "r", stdin);
  freopen("output.out", "w", stdout);
  int test;
  scanf("%d", &test);
  for (int t = 1; t <= test; t++) {
    scanf("%s %s", c, j);
    int n = strlen(c);
    x = "";
    y = "";
    for (int i = 0; i < n; i++) {
      x.push_back(c[i]);
      y.push_back(j[i]);
    }
    mn = (long long)2e18;
    solve(0, 0, 0, n);
    printf("Case #%d: %s %s\n", t, resx.c_str(), resy.c_str());
  }
}

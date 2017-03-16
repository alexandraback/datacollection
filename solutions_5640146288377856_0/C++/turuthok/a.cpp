#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int N = 20;

int rows, cols, w;
int bc[2048];

bool possible(int h, int& lo, int& hi) {
  lo = 1000, hi = -1;
  for (int i = 0; i < cols; i++) if ((1<<i) & h) {
    lo = min(lo, i), hi = max(hi, i);
  }
  return (hi-lo+1 <= w);
}

int go(int m, int h) {
  if ((m & (m-1)) == 0) return w-bc[h];

  int best = 1000;
  for (int guess = 0; guess < cols; guess++) {
    bool anyhit = false;
    for (int i = 0, mm = 1; i < cols; i++, mm <<= 1) if (mm & m) {
      if (i <= guess && guess < i+w) anyhit = true;
    }
    if (!anyhit) continue;

    int worst = 0;
    int hh = h | (1 << guess);
    int lo, hi;
    if (possible(hh, lo, hi)) {
      int newm = m;
      for (int i = 0, mm = 1; i < cols; i++, mm <<= 1) if (mm & m) {
        if (!(i <= lo && i+w > hi))
          newm &= ~mm;
      }
      if (newm != m) worst = max(worst, go(newm, hh)); else continue;
    } else continue;

    int newm = m;
    for (int i = 0, mm = 1; i < cols; i++, mm <<= 1) if (mm & m) {
      if (i <= guess && guess < i+w) newm &= ~mm;
    }
    if (newm && (newm != m)) worst = max(worst, go(newm, h));

    best = min(best, worst+1);
  }
  return best;
}

int main() {
  for (int i = 0; i < 2048; i++) {
    int j = i;
    bc[i] = 0;
    while (j) {
      bc[i]++;
      j &= (j-1);
    }
  }

  int tests; cin >> tests;
  for (int tc = 1; tc <= tests; tc++) {
    cin >> rows >> cols >> w;
    int m = 0;
    for (int j = 0; j+w <= cols; j++) m |= (1 << j);
    cout << "Case #" << tc << ": " << go(m, 0) << endl;
  }

  return 0;
}


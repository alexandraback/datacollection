/**
 * Jerry Ma
 * B.cpp
 */

#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <algorithm>
#include <array>
#include <bitset>
#include <chrono>
#include <complex>
#include <deque>
#include <forward_list>
#include <fstream>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

typedef long long int lli;
typedef pair<int, int> pii;
typedef pair<int, lli> pil;
typedef pair<lli, int> pli;
typedef pair<lli, lli> pll;

int gInt () {
  int i;
  scanf("%d", &i);
  return i;
}

lli gLong () {
  lli i;
  scanf("%lld", &i);
  return i;
}

double gDouble () {
  double i;
  scanf("%lf", &i);
  return i;
}

void quit () {
  fflush(stdout);
  exit(0);
}

int n;
char s1[20], s2[20];
char buf[20];

bool matches(lli num, char* str) {
  sprintf(buf, "%0*lld", n, num);
  for (int i = 0; i < n; ++i) {
    if (buf[i] != str[i] && str[i] != '?') {
      return false;
    }
  }
  return true;
}

void solve (int nC) {
  scanf("%s %s", s1, s2);
  fprintf(stderr, "%d %s %s\n", nC, s1, s2);
  n = strlen(s1);
  lli lim = 1;
  for (int i = 0; i < n; ++i)
    lim *= 10;
  lli besta = -1;
  lli bestb = -1;
  lli bestdiff = 99999999999999999LL;
  for (lli a = 0; a < lim; ++a) {
    for (lli b = 0; b < lim; ++b) {
      lli diff = abs(a - b);
      if (matches(a, s1) && matches(b, s2)) {
        if (diff < bestdiff) {
          bestdiff = diff;
          besta = a;
          bestb = b;
        }
      }
    }
  }
  printf("Case #%d: %0*lld %0*lld\n", nC, n, besta, n, bestb);
}

int main (int argc, char ** argv) {
  int nC = gInt();
  for (int i = 0; i < nC; ++i)
    solve(i + 1);
  quit();
}

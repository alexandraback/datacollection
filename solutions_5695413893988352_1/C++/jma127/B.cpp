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
char s1[25], s2[25];
char buf[25], buf1[25], buf2[25];
lli lim, besta, bestb, bestdiff;

bool matches(lli num, char* str) {
  sprintf(buf, "%0*lld", n, num);
  for (int i = 0; i < n; ++i) {
    if (buf[i] != str[i] && str[i] != '?') {
      return false;
    }
  }
  return true;
}

void attempt (int mode, int pos) {
  memset(buf1, 0, sizeof(buf1));
  memset(buf2, 0, sizeof(buf2));
  if (mode == 0) {
    for (int i = 0; i < n; ++i) {
      if (s1[i] == '?' && s2[i] == '?') {
        buf1[i] = buf2[i] = '0';
      } else if (s1[i] == '?') {
        buf1[i] = buf2[i] = s2[i];
      } else if (s2[i] == '?') {
        buf1[i] = buf2[i] = s1[i];
      } else {
        buf1[i] = s1[i];
        buf2[i] = s2[i];
      }
    }
  } else {
    for (int i = 0; i < n; ++i) {
      buf1[i] = s1[i];
      buf2[i] = s2[i];
      if (i < pos - 1) {
          if (s1[i] == '?' && s2[i] == '?') {
            buf1[i] = buf2[i] = '0';
          } else if (s1[i] == '?') {
            buf1[i] = buf2[i] = s2[i];
          } else if (s2[i] == '?') {
            buf1[i] = buf2[i] = s1[i];
          }
      } else if (i == pos - 1) {
        if (s1[i] == '?' && s2[i] == '?') {
          if (mode < 0) {
            buf1[i] = '0';
            buf2[i] = '1';
          } else {
            buf1[i] = '1';
            buf2[i] = '0';
          }
        } else if (s1[i] == '?') {
          if (mode < 0) {
            buf1[i] = max<char>('0', s2[i] - 1);
          } else {
            buf1[i] = min<char>('9', s2[i] + 1);
          }
        } else if (s2[i] == '?') {
          if (mode < 0) {
            buf2[i] = min<char>('9', s1[i] + 1);
          } else {
            buf2[i] = max<char>('0', s1[i] - 1);
          }
        }
      } else {
        if (s1[i] == '?') {
          buf1[i] = (mode < 0) ? '9' : '0';
        }
        if (s2[i] == '?') {
          buf2[i] = (mode < 0) ? '0' : '9';
        }
      }
    }
  }

  lli num1, num2;
  sscanf(buf1, "%lld", &num1);
  sscanf(buf2, "%lld", &num2);
  lli diff = abs(num1 - num2);
  if (diff < bestdiff || (diff == bestdiff && (num1 < besta || (num1 == besta && num2 < bestb)))) {
    bestdiff = diff;
    besta = num1;
    bestb = num2;
  }
}

void solve (int nC) {
  scanf("%s %s", s1, s2);
  fprintf(stderr, "%d %s %s\n", nC, s1, s2);
  n = strlen(s1);
  lim = 1;
  for (int i = 0; i < n; ++i)
    lim *= 10;
  besta = bestb = -1;
  bestdiff = lim + 1;
  attempt(0, 0);
  for (int i = -1; i < n + 2; ++i) {
    attempt(-1, i);
    attempt(1, i);
  }
  printf("Case #%d: %0*lld %0*lld\n", nC, n, besta, n, bestb);
}

int main (int argc, char ** argv) {
  int nC = gInt();
  for (int i = 0; i < nC; ++i)
    solve(i + 1);
  quit();
}

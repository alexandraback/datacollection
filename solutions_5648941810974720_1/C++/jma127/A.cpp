/**
 * Jerry Ma
 * A.cpp
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
char ch[2005];
int chfreq[128];

int digfreq[10][128];
std::string words[10] = {
  "ZERO",
  "ONE",
  "TWO",
  "THREE",
  "FOUR",
  "FIVE",
  "SIX",
  "SEVEN",
  "EIGHT",
  "NINE"};
int digorder[10] = {0, 6, 8, 4, 5, 2, 7, 1, 3, 9};
int ans[10];

void solve (int nC) {
  scanf("%s", ch);
  n = strlen(ch);
  memset(chfreq, 0, sizeof(chfreq));
  memset(ans, 0, sizeof(ans));
  for (int i = 0; i < n; ++i) {
    chfreq[ch[i]] ++;
  }
  printf("Case #%d: ", nC);
  for (int i = 0; i < 10; ++i) {
    int dig = digorder[i];
    bool good = true;
    for (int j = 0; j < 128; ++j) {
      if (digfreq[dig][j] > chfreq[j]) {
        good = false;
        break;
      }
    }
    if (!good) {
      continue;
    }
    --i;
    ans[dig]++;
    for (int j = 0; j < 128; ++j) {
      chfreq[j] -= digfreq[dig][j];
    }
  }
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < ans[i]; ++j)
      printf("%d", i);
  }
  printf("\n");
}

int main (int argc, char ** argv) {
  for (int i = 0; i < 10; ++i) {
    for (char c : words[i]) {
      digfreq[i][c] ++;
    }
  }
  int nC = gInt();
  for (int i = 0; i < nC; ++i) {
    solve(i + 1);
  }
  quit();
}

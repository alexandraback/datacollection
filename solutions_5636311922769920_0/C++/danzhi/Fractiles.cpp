#define _CRT_SECURE_NO_DEPRECATE
#include <algorithm>
#include <bitset>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <functional>
#include <unordered_map>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <list>
#include <deque>
#include <queue>
#include <math.h>
#include <map>
#include <numeric>
#include <set>
#include <stack>
#include <stdio.h>
#include <string>
#include <sstream>
#include <utility>
#include <vector>

using namespace std;
bool test = false;
const double pi = acos(-1.0);
const double eps = 1e-11;
int breakpoint = 0;

const char rootdir[] = "C:\\CodeJam\\Fractiles";
void reopen(char* a) {
  char input[256], output[256];
  sprintf(input, "%s\\%s", rootdir, a);
  sprintf(output, "%s\\%s", rootdir, a);
  char *p = strstr(output, ".in");
  if (p) sprintf(p, ".out");
  else sprintf(&p[strlen(output)], ".out");
  freopen(input, "r", stdin);
  if (!test) freopen(output, "w", stdout);
}

int K;
int C;
int S;

void solve(int t) {
  __int64 p[120];
  p[0] = 1;
  for (int i = 1; i < 120; i++) {
    p[i] = p[i - 1] * K;
    if (p[i] < 0) p[i] = 0;
  }

  if (C * S < K) {
    printf("Case #%d: IMPOSSIBLE\n", t);
  } else {
    // 1 2 3 4 5 6 7 8 9
    int N = (K + C - 1) / C;
    __int64 output[120];
    for (int i = 0; i < N; i++) {
      // i * N + 1, ..., i * N + C
      __int64 v = 0;

      // find minimal index
      __int64 a[120];
      a[C] = min(i * C + C, K);
      for (int j = C - 1; j > 0; j--) {
        a[j] = a[j + 1] - 1;
        if (a[j] <= i * C) a[j] = 1;
      }

      for (int j = 1; j <= C; j++) {
        v += p[C - j] * (a[j] - 1);
      }
      v += 1;
      output[i] = v;

      if (test) {
        printf("index(", v);
        for (int j = 1; j <= C; j++) {
          if (j < C) printf("%d,", a[j]);
          else printf("%d", a[j]);
        }
        printf(") = %lld\n", v);
      }
    }
    printf("Case #%d:", t);
    for (int i = 0; i < N; i++) {
      printf(" %lld", output[i]);
    }
    printf("\n");
  }
}

int main() {
  // test = true;
  // reopen("sample.in");
  reopen("D-small-attempt0.in");
  // reopen("A-large-practice.in");

  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    scanf("%d %d %d", &K, &C, &S);
    if (test) printf("%d %d %d\n", K, C, S);
    solve(qq);
  }
  return 0;
}

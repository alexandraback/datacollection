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

const char rootdir[] = "C:\\CodeJam\\Slides";
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

int B;  // [2,50]
__int64 M;
int S[64][64];

void solve(int t) {
  __int64 ONE = 1;
  __int64 MAX = (ONE << (B - 2));
  if (M > MAX) {
    printf("Case #%d: IMPOSSIBLE\n", t);
    return;
  }
  for (int i = 0; i < 64; i++) for (int j = 0; j < 64; j++) S[i][j] = 0;
  printf("Case #%d: POSSIBLE\n", t);
  int n = B;
  for (; n >= 2; n--) {
    if (M >= (ONE << (n-2))) break;
  }

  // file complete sub-n
  for (int i = 1; i <= n; i++) for (int j = i+1; j <= n; j++) S[i][j] = 1;
  if (n < B) S[n][B] = 1;
  __int64 r = M - (ONE << (n-2));
  for (int i = 1; i <= n; i++) {
    if (r % 2 == 1) S[i+1][B] = 1;
    r /= 2;
  }

  for (int i = 1; i <= B; i++) {
    for (int j = 1; j <= B; j++) {
      printf("%d", S[i][j]);
    }
    printf("\n");
  }
}

int main() {
  // test = true;
  // reopen("sample.in");
  // reopen("B-small-attempt1.in");
  reopen("B-large.in");

  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    scanf("%d %lld", &B, &M);
    // if (test && qq != 47) continue;
    solve(qq);
  }
  return 0;
}

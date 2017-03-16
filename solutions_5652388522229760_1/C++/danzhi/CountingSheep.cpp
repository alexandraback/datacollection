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

const char rootdir[] = "C:\\CodeJam\\CountingSheep";
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

int N;

__int64 calculate(int n) {
  __int64 output = n;
  int mask = 0;
  int loop = 0;
  while (true) {
    loop++;
    __int64 v = output;
    while (v > 0) {
      int d = v % 10;
      mask |= (1 << d);
      v /= 10;
    }
    if (mask == 1023) return output;
    if (loop > 1000) {
      if (test) printf("%d loop exceed limit mask=%d\n", n, mask);
      return -1;
    }
    output += n;
  }
}

void solve(int t) {
  __int64 output = calculate(N);
  if (output < 0) printf("Case #%d: INSOMNIA\n", t);
  else printf("Case #%d: %lld\n", t, output);
}

int main() {
  // test = true;
  // reopen("sample.in");
  // reopen("A-small-attempt0.in");
  reopen("A-large.in");

  // for (N = 0; N < 1000; N++) solve(N + 1);

  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    scanf("%d", &N);
    solve(qq);
  }
  return 0;
}

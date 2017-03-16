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

const char rootdir[] = "C:\\CodeJam\\RevengeOfThePancakes";
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

char S[120];

void solve(int t) {
  int m = strlen(S);
  assert(S[m - 1] == '+' || S[m - 1] == '-');
  int diff = 0;
  for (int i = 0; i < m - 1; i++) {
    if (S[i] != S[i + 1]) diff++;
  }
  if (S[m - 1] == '-') diff++;
  printf("Case #%d: %d\n", t, diff);
}

int main() {
  // test = true;
  // reopen("sample.in");
  // reopen("B-small-attempt0.in");
  reopen("B-large.in");

  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    scanf("%s", &S);
    solve(qq);
  }
  return 0;
}

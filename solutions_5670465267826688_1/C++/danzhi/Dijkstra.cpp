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
#include <hash_map>
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
const double pi=acos(-1.0);
const double eps=1e-11;
int breakpoint = 0;

const char rootdir[] = "C:\\CodeJam\\Dijkstra";
void reopen(char* a) {
	char input[256], output[256];
	sprintf(input, "%s\\%s", rootdir, a);
	sprintf(output, "%s\\%s", rootdir, a);
	char *p = strstr(output, ".in");
	if (p) sprintf(p, ".out"); 
	else sprintf(&p[strlen(output)], ".out");
	freopen(input,"r",stdin);
	if (!test) freopen(output,"w",stdout);
}

int T;
__int64 L;
__int64 X;
char buf[10240];
int table[8][8];

int idx(char c) {
  if (c == '1') return 1;
  else if (c == 'i') return 2;
  else if (c == 'j') return 3;
  else if (c == 'k') return 4;
  assert(false);
}

int func(int value, char c) {
  bool negative = false;
  if (value < 0) {
    value = -value;
    negative = true;
  }
  assert(value <= 4);
  assert(value >= 1);
  int v = table[value][idx(c)];
  return negative? -v : v;
}

bool solve() {
  bool iok = false;
  bool jok = false;
  bool kok = false;
  __int64 repeat = X % 4;
  repeat = std::min(repeat + 12, X);
  if (test) printf("Use repeat %d\n", repeat);
  int value = 1;
  for (int i = 0; i < repeat; i++) {
    if (i >= 4 && !iok) return false;
    if (i >= 8 && !jok) return false;
    for (int j = 0; j < L; j++) {
      int v = func(value, buf[j]);
      if (!iok) {
        if (v == 2) {
          iok = true;
          value = 1;
        } else {
          value = v;
        }
      } else if (!jok) {
        if (v == 3) {
          jok = true;
          value = 1;
        } else {
          value = v;
        }
      } else if (!kok) {
        if (v == 4) {
          kok = true;
          value = 1;
        } else {
          value = v;
        }
      } else {
        value = v;
      }
    }
  }
  bool ok = iok && jok && kok && (value == 1);
  return ok;
}

int main() {
  test = false;
  // reopen("sample.in");
  // reopen("C-small-attempt0.in");
  reopen("C-large.in");

  table[1][1] = 1;
  table[1][2] = 2;
  table[1][3] = 3;
  table[1][4] = 4;
  table[2][1] = 2;
  table[2][2] = -1;
  table[2][3] = 4;
  table[2][4] = -3;
  table[3][1] = 3;
  table[3][2] = -4;
  table[3][3] = -1;
  table[3][4] = 2;
  table[4][1] = 4;
  table[4][2] = 3;
  table[4][3] = -2;
  table[4][4] = -1;

  scanf("%d", &T);
  
  for (int TC = 1; TC <= T; TC++) {
    scanf("%lld %lld", &L, &X);
    scanf("%s", buf);
    assert(strlen(buf) == L);
    bool ok = solve();
    if (ok) {
      printf("Case #%d: YES\n", TC);
    } else {
      printf("Case #%d: NO\n", TC);
    }
  }
}
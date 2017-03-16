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

const char rootdir[] = "C:\\CodeJam\\OminousOmino";
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
int X;
int R;
int C;

// Whether Gabriel can make it.
bool solve() {
  int total = R*C;
  if (total % X != 0) return false;
  if (X == 1) return true;
  if (X == 2) return true;
  if (X == 3) {
    if (R == 1) return false;
    return true;
  }
  if (X == 4) {
    if (R <= 2) return false;
    return true;
  }
  if (X == 5) {
    if (R <= 3) return false;
    return true;
  }
  if (X == 6) {
    if (R <= 3) return false;
    return true;
  }
  return false;
}

int main() {
  test = false;
  // reopen("sample.in");
  // reopen("D-small-attempt0.in");
  reopen("D-large.in");

  scanf("%d", &T);
  
  for (int TC = 1; TC <= T; TC++) {
    scanf("%d %d %d", &X, &R, &C);
    if (R > C) swap(R, C);
    assert(R <= C);
    bool ok = solve();
    if (ok) {
      printf("Case #%d: GABRIEL\n", TC);
    } else {
      printf("Case #%d: RICHARD\n", TC);
    }
  }
}
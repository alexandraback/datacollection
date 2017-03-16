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

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

#define M_PI 3.14159265358979323846

bool test = false;
const double pi=acos(-1.0);
const double eps=1e-11;
int breakpoint = 0;

const char rootdir[] = "C:\\CodeJam\\Battleship";
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
int R,C,W;

int solve1D() {
  // assert(R == 1);
  assert(W <= C);
  return W + (C-1)/W;
}

int main() {
  test = false;
  // reopen("sample.in");
  reopen("A-small-attempt0.in");
  // reopen("C-small-practice-2.in");
  // reopen("C-large-practice.in");
  scanf("%d", &T);
  
  if (test) {
    R = 1;
    for (C = 1; C <= 10; C++) {
      printf("C:%2d ", C);
      for (W = 1; W <= C; W++) {
        printf("%2d ", solve1D());
      }
      printf("\n");
    }
  }
  for (int TC = 1; TC <= T; TC++) {
    scanf("%d %d %d", &R, &C, &W);
    int output = solve1D();
    printf("Case #%d: %d\n", TC, output);
  }
  return 0;
}
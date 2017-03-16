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
#define debug(x) cerr<<#x<<" = "<<(x)<<endl;
bool test = false;
const double pi=acos(-1.0);
const double eps=1e-11;
int breakpoint = 0;

const char rootdir[] = "C:\\CodeJam\\CookieClickerAlpha";
void reopen(char* a) {
	char input[256], output[256];
	sprintf(input, "%s\\%s", rootdir, a);
	sprintf(output, "%s\\%s", rootdir, a);
	char *p = strstr(output, ".in");
	if (p) sprintf(p, ".out"); 
	else sprintf(&p[strlen(output)], ".out");
	debug(input);
	debug(output);
	freopen(input,"r",stdin);
	if (!test) freopen(output,"w",stdout);
}

const int md = 1000002013;

int cost(int n, int len) {
  int a = n + (n - len + 1);
  int b = len;
  if (a % 2 == 0) a /= 2;
  else b /= 2;
  return (long long)a * b % md;
}

int T = 0;
double C, F, X;
double answer = 0.0;

void showin() {
  if (!test) return;
  printf("%lf %lf %lf\n", C, F, X);
}

double solve() {
  double output = 0;
  double rate = 2.0;
  while (true) {
    // time needed for cookie farm
    double tf = C / rate;
    // time needed to win
    double tw = X / rate;
    if (tf + eps >= tw) {
      return output + tw;
    }
    // compare two options:
    //  1. accumulate C, then buy cookie farm and then accumulate to win
    //  2. simply accumulate to win
    double t1 = tf + X / (rate + F);
    if (t1 + eps >= tw) {
      return output + tw;
    } else {
      output += tf;
      rate += F;
    }
  }
  // should not reach here!
  assert(false);
}

int main() {
  test = false;
  // reopen("sample.in");
  // reopen("B-small-attempt0.in");
  reopen("B-large.in");
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    scanf("%lf %lf %lf", &C, &F, &X);
    showin();
    double answer = solve();
    printf("Case #%d: %.7f\n", t, answer);
  }
  return 0;
}
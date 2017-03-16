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

const char rootdir[] = "C:\\CodeJam\\FallingDiamonds";
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

int T = 0;
int N = 0;
int X = 0;
int Y = 0;

const int LEN = 710;
// triangle numbers (2*n, 2)
int a[LEN];

double** p = NULL;

void computeTriNum() {
  a[0] = 0;
  for (int i = 1; i < LEN; i++) {
    a[i] = i * (2 * i - 1);
    if (test) printf("  %2d %d\n", i, a[i]);
  }
  if (test) printf("\n");
}

void showin() {
	if (!test) return;
  printf("%d %d %d\n", N, X, Y);
  printf("\n");
}

int compareInt(const void * a, const void * b) {
  return ( *(int*)a - *(int*)b );
}

void showPascal(int n) {
  for (int i = 0; i < n; i++) {
    printf("%03d: ", i);
    for (int j = 0; j <= i; j++) {
      if (j < i) printf("%10.9f ", p[i][j]);
      else printf("%10.9f\n", p[i][j]);
    }
  }
}

void buildProbPascal() {
  if (p != NULL) return;
  p = (double**)malloc(LEN*sizeof(double));
  for (int i = 0; i < LEN; i++) {
    p[i] = (double*)malloc(LEN*sizeof(double));
    memset(p[i], 0, LEN*sizeof(double));
  }
  p[0][0] = 1.0;
  p[1][0] = 0.5;
  p[1][1] = 0.5;
  for (int i = 2; i < LEN; i++) {
    p[i][0] = p[i-1][0] * 0.5;
    p[i][i] = p[i-1][i-1] * 0.5;
    for (int j = 1; j < i; j++) {
      p[i][j] = (p[i-1][j-1] + p[i-1][j]) * 0.5;
    }
    if (test && i == 20) showPascal(20);
  }
}

void solve(int cn) {
  int n = (abs(X) + Y) / 2;
  /* 1 1
     2 6
     3 15
     4 28
     5 45
     6 66
     7 91
    ......
   707 998991
   708 1001820
  */
  if (n >= 708) {
    printf("Case #%d: %10.9f\n", cn, 0.0);
    return;
  }
  if (N <= a[n]) {
    printf("Case #%d: %10.9f\n", cn, 0.0);
    return;
  }
  if (N >= a[n+1]) {
    printf("Case #%d: %10.9f\n", cn, 1.0);
    return;
  }
  int m = N - a[n];
  // now both left and right have M slots, and one extra one in middle
  int M = 2 * n;
  assert(m > 0 && m < 2 * M + 1);
  if (m > M + Y) {
    printf("Case #%d: %10.9f\n", cn, 1.0);
    return;
  }
  if (Y >= m) {
    printf("Case #%d: %10.9f\n", cn, 0.0);
    return;
  }
  assert(Y < m);

  // Now we need probability of Y+1 or more 1s out of m 0/1s.
  // p is the probability that one of the N diamonds will fall 
  // so that its center ends up exactly at (X, Y).

  if (Y == M) {
    printf("Case #%d: %10.9f\n", cn, 0.0);
    return;
  }
  double q = 0.0;
  for (int i = Y+1; i <= m; i++) q += p[m][i];
  printf("Case #%d: %10.9f\n", cn, q);
}

int main(int argc, char* argv[]) {
  test = false;
  computeTriNum();
  buildProbPascal();
	// reopen("sample.in");
  reopen("B-small-attempt0.in");
  // reopen("A-large.in");
	scanf("%d", &T);
	for(int tc=1; tc<=T; tc++) {
    scanf("%d %d %d", &N, &X, &Y);
    showin();
    solve(tc);
  }
 	return 0;
}
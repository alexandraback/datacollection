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

const char rootdir[] = "C:\\CodeJam\\Lawnmower";
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
int M = 0;
int a[100][100];

void showin() {
	if (!test) return;
  printf("%d %d\n", N, M);
  for (int i = 0; i < N; i++) {
    printf("%2d: ", i);
    for (int j = 0; j < M; j++) {
      printf("%d ", a[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

void solve(int cn) {
  int rmin[100];
  int cmin[100];
  for (int i = 0; i < 100; i++) {
    rmin[i] = 100;
    cmin[i] = 100;
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      int v = a[i][j];
      // If I am bigger than either my rmin or cmin, NO
      if (v > rmin[i] || v > cmin[j]) {
        printf("Case #%d: NO\n", cn);
        if (test) printf("due to a[%d][%d]\n", i, j);
        return;
      }
      // If v is less than left or right, v relies on column cut.
      // acually every entry in the same row relies their column (since no row cut).
      if ((j+1 < M  && v < a[i][j+1]) || (j > 0 && v < a[i][j-1])) {
        assert(v <= cmin[j]);
        for (int k = 0; k < M; k++) {
          if (a[i][k] < cmin[k]) {
            cmin[k] = a[i][k];
            if (test) printf("cmin[%d]=%d due to a[%d][%d]\n", k, a[i][k], i, j);
          }
        }
      }

      // If v is less than upper or lower, v rely on row cut.
      // actually every entry in the same columns relies on their row (since no column cut).
      if ((i > 0 && v < a[i-1][j]) || (i+1 < N && v < a[i+1][j])) {
        assert(v <= rmin[j]);
        for (int k = 0; k < M; k++) {
          if (a[k][j] < rmin[j]) {
            rmin[k] = a[k][j];
            if (test) printf("rmin[%d]=%d due to a[%d][%d]\n", k, a[k][j], i, j);
          }
        }
      }
    }
  }
  // one last retrospective pass.
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      int v = a[i][j];
      // If I am bigger than either my rmin or cmin.
      if (v > rmin[i] || v > cmin[j]) {
        printf("Case #%d: NO\n", cn);
        if (test) printf("due to a[%d][%d]\n", i, j);
        return;
      }
    }
  }
  printf("Case #%d: YES\n", cn);
}

int main(int argc, char* argv[]) {
	// reopen("sample.in");
  reopen("B-small-attempt3.in");
  // reopen("A-large.in");
	scanf("%d", &T);
	for(int t=1; t<=T; t++) {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        scanf("%d", &a[i][j]);
      }
    }
    showin();
    solve(t);
  }
 	return 0;
}
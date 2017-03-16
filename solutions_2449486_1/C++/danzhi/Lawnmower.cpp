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
  if (test && cn != 20) return;
  int rmin[100];
  int rmax[100];
  int cmin[100];
  int cmax[100];
  bool rdone[100];
  bool cdone[100];
  int rcount = 0;
  int ccount = 0;
  for (int i = 0; i < N; i++) rdone[i] = false;
  for (int j = 0; j < M; j++) cdone[j] = false;

  while (rcount < N && ccount < M) {
    int gmin = 100;  // global min
    int gmax = 0;    // global max
    for (int i = 0; i < N; i++) {
      rmin[i] = 100;
      rmax[i] = 0;
    }
    for (int j = 0; j < M; j++) {
      cmin[j] = 100;
      cmax[j] = 0;
    }
    for (int i = 0; i < N; i++) {
      if (rdone[i]) continue;
      for (int j = 0; j < M; j++) {
        if (cdone[j]) continue;
        int v = a[i][j];
        if (v < rmin[i]) rmin[i] = v;
        if (v > rmax[i]) rmax[i] = v;
        if (v < cmin[j]) cmin[j] = v;
        if (v > cmax[j]) cmax[j] = v;
        if (v < gmin) gmin = v;
        if (v > gmax) gmax = v;
      }
    }
    int count = 0;
    for (int i = 0; i < N; i++) {
      if (rmin[i] == gmin && rmax[i] == gmin) {
        rcount++;
        rdone[i] = true;
        count++;
      }
    }
    for (int j = 0; j < M; j++) {
      if (cmin[j] == gmin && cmax[j] == gmin) {
        ccount++;
        cdone[j] = true;
        count++;
      }
    }
    if (count == 0) {
      printf("Case #%d: NO\n", cn);
      return;
    }
  }
  printf("Case #%d: YES\n", cn);
}

int main(int argc, char* argv[]) {
  test = false;
	// reopen("sample.in");
  // reopen("B-small-attempt3.in");
  reopen("B-large.in");
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
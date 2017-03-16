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

const char rootdir[] = "C:\\CodeJam\\InfiniteHouseofPancakes";
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
int D;
int P[1028];
const int M = 1001;
int S[M][M];

int main() {
  test = false;
  // reopen("sample.in");
  // reopen("B-small-attempt0.in");
  reopen("B-large.in");

  scanf("%d", &T);
  
  // pre-compute special minutes count;
  for (int i = 1; i < M; i++) {
    for (int j = 1; j < M; j++) {
      S[i][j] = (i-1)/j;
    }
  }
  for (int TC = 1; TC <= T; TC++) {
    scanf("%d", &D);
    int m = 0;
    for (int i = 0; i < D; i++) {
      scanf("%d", &P[i]);
      m = std::max(m, P[i]);
    }

    if (test) {
      printf("max=%d\n", m);
      for (int i = 1; i <= m; i++) {
        printf("m=%d ", i);
        for (int j = 1; j <= m; j++) {
          printf("%2d ", S[i][j]);
        }
        printf("\n");
      }
    }
    int result = m;
    for (int mpp = m; mpp >= 1; mpp--) {
      // max number of pancakes on each plate is i
      int minutes = mpp;
      for (int i = 0; i < D; i++) {
        minutes += S[P[i]][mpp];
      }
      if (test) printf("mpp=%d minutes=%d\n", mpp, minutes);
      result = std::min(result, minutes);
    }
    printf("Case #%d: %d\n", TC, result);
  }
}
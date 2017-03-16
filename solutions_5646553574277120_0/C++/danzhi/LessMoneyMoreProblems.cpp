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

const char rootdir[] = "C:\\CodeJam\\LessMoneyMoreProblems";
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
int C,D,V;
int d[128];
int vmap[128];

int main() {
  test = false;
  reopen("sample.in");
  reopen("C-small-attempt0.in");
  scanf("%d", &T);
  for (int TC = 1; TC <= T; TC++) {
    scanf("%d %d %d", &C, &D, &V);
    for(int i = 0; i < D; i++) {
      scanf("%d", &d[i]);
    }

    if (test) {
      printf("%d %d %d\n", C, D, V);
      for(int i = 0; i < D; i++) {
        printf("%d ", d[i]);
      }
      printf("\n");
    }
    // for (int i = 0; i < 128; i++) vmap[i] = 0;
    // for (int i = 0; i < D; i++) vmap[d[i]]++;

    int output = 0;
    for (int v = 1; v <= V; v++) {
      int N = (1 << D);
      bool ok = false;
      for (int i = 1; i < N; i++) {
        // which d to choose
        int value = 0;
        for (int j = 0; j < D; j++) {
          if ((i >> j) & 0x1) value += d[j];
        }
        if (value == v) {
          ok = true;
          break;
        }
      }
      if (ok) continue;  // the v is possible
      // add new coin with value v
      // assert(vmap[v] == 0);
      output++;
      // vmap[v] = 1;
      d[D] = v;
      D++;
    }
    printf("Case #%d: %d\n", TC, output);
  }
  return 0;
}
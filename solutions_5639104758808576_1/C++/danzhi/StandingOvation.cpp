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

const char rootdir[] = "C:\\CodeJam\\StandingOvation";
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
int Smax;
int S[1024];

int main() {
  test = false;
  // reopen("sample.in");
  // reopen("A-small-attempt0.in");
  reopen("A-large.in");

  scanf("%d", &T);
  
  for (int TC = 1; TC <= T; TC++) {
    scanf("%d", &Smax);
    int m = 0;
    char buf[1024];
    scanf("%s", buf);
    assert(strlen(buf) == Smax + 1);
    for (int i = 0; i <= Smax; i++) {
      S[i] = buf[i] - '0';
    }

    if (test) {
      printf("%d ", Smax);
      for (int i = 0; i <= Smax; i++) {
        printf("%d", S[i]);
      }
      printf("\n");
    }

    int numStanding = 0;
    int totalExtra = 0;
    for (int i = 0; i <= Smax; i++) {
      if (S[i] == 0) continue;
      if (numStanding < i) {
        int extra = i - numStanding;
        totalExtra += extra;
        numStanding += extra;
      }
      numStanding += S[i];
    }
    printf("Case #%d: %d\n", TC, totalExtra);
  }
}
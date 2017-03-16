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

const char rootdir[] = "C:\\CodeJam\\Bullseye";
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
__int64 r = 0;
__int64 t = 0;

void showin() {
	if (!test) return;
  printf("%lld %lld\n", r, t);
  printf("\n");
}

void solve(int cn) {
  if (cn == 4)
    breakpoint++;
  // (2r + 2m -1) * m <= t
  // binary search m from 1 to t-r
  __int64 l = 1;
  __int64 h = t-r;
  assert(h > 0);
  while (true) {
    __int64 m = (l + h) >> 1;
    __int64 v1 = 2 * r + 2 * m -1;
    __int64 v = v1 * m;
    double v2 = log10(v1 * 1.0) + log10(m * 1.0);
    if (v2 >= 19) {
      h = m;
      continue;
    }
    assert(v > 0);
    if (v == t) {
      printf("Case #%d: %lld\n", cn, m);
      return;
    }
    if (v > t) {
      if (m == h) {
        printf("Case #%d: %lld\n", cn, l);
        return;
      }
      h = m;
      continue;
    } else if (v < t) {
      if (l == m) {
        printf("Case #%d: %lld\n", cn, l);
        return;
      }
      l = m;
      continue;
    }
  }
}

int main(int argc, char* argv[]) {
  test = false;
	// reopen("sample.in");
  reopen("A-small-attempt0.in");
  // reopen("B-large.in");
	scanf("%d", &T);
	for(int tc=1; tc<=T; tc++) {
    scanf("%lld %lld", &r, &t);
    showin();
    solve(tc);
  }
 	return 0;
}
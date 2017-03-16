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

const char rootdir[] = "C:\\CodeJam\\NewLotteryGame";
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

int T;
int A, B, K;

void showin() {
  if (!test) return;
  printf("%d %d %d\n", A, B, K);
}

// number of digits
int dlen(int m) {
  int len = 0;
  while(m > 0) {
    m >>= 1;
    len++;
  }
  return len;
}

__int64 p(int a, int b, int k) {
  __int64 output = 0;
  if (a < b) swap(a,b);
  assert(a >= b);
  if (k >= b) {
    output = a;
    output *= b;
  } else if (k == 0) {
    return 0;
  } else {
    // a, b, k in decreasing order
    assert(a >= b && b > k);
    int d = dlen(a-1);  // number of digits
    int low = (1 << (d-1));
    assert(a > low);
    __int64 output = 0;
    output += p(low, b, k);
    output += p(a-low, min(b, low), k);

    // if k's leading digit is 1, also include the leading 1 cases
    if (k > low && b > low) {
      output += p(a-low, b-low, k-low);
    }
    if (test) printf("p(%3d,%3d,%3d)=%lld\n", a,b,k,output);
    return output;
  }
}

void solve(int t) {
  __int64 output = p(A,B,K);
  printf("Case #%d: %lld\n", t, output);
}

int main() {
  // test = true;
  // reopen("sample.in");
  reopen("B-small-attempt0.in");
  // reopen("A-large.in");
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    scanf("%d %d %d", &A, &B, &K);
    showin();
    solve(t);
  }
  return 0;
}
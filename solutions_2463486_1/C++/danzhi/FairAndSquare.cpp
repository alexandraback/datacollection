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

const char rootdir[] = "C:\\CodeJam\\FairAndSquare";
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
__int64 A = 0;
__int64 B = 0;

int numDigits(__int64 m) {
  if (m == 0) return 1;
  int v = 0;
  while (m > 0) {
    m = m / 10;
    v++;
  }
  return v;
}

__int64 mirror(__int64 m, int d) {
  int v = 0;
  for (int i = 0; i < d; i++) {
    v = 10 * v + (m % 10);
    m = m / 10;
  }
  return v;
}

// tell whether uppereppu^2 is palindrome
bool isFair(__int64 upper, int d) {
  if (d % 2 == 0) {
    // for example upper = 14, d=4 => p = 1441
    int sum = 0;
    for (int i = 0; i < (d>>1); i++) {
      int v = upper % 10;
      sum += v * v;
      if (sum >= 5) return false;
      upper /= 10;
    }
  } else {
    // for example, upper = 14, d=3 => p = 141
    int v = upper % 10;
    int sum = v * v;
    if (sum >= 10) return false;
    upper = upper / 10;
    d -= 1;
    for (int i = 0; i < (d>>1); i++) {
      int v = upper % 10;
      sum += 2 * v * v;
      if (sum >= 10) return false;
      upper /= 10;
    }
  }
}

int debug = 0;
bool isPalindrome(__int64 q) {
  char a[64];
  int d = 0;
  while (q != 0) {
    a[d] = q % 10 + '0';
    q /= 10;
    d++;
  }
  a[d] = 0;
  for (int i = 0; i < (d>>1); i++) {
    if (a[i] != a[d-1-i]) return false;
  }
  return true;
}

void solve(int cn) {
  int total = 0;
  
  __int64 M = (__int64)(sqrt(A * 1.0) + eps);
  __int64 N = (__int64)(sqrt(B * 1.0) + eps);
  // look for palindromes between [M, N]
  // 147 -> 151 161 171 181 191 202 ... 999 (1001)
  // 1447 -> 1551 1661 1771 1881 1991 2002 ... 9999 (10001)
  int d = numDigits(M);
  __int64 upper = M / 10^((d+1)/2) - 1;
  while (true) {
    __int64 p = 0;
    if (d % 2 == 0) {
      p = upper;
      for (int i = 0; i < (d>>1); i++) p *= 10;
      p += mirror(upper, d/2);
    } else {
      p = upper;
      for (int i = 0; i < ((d-1)>>1); i++) p *= 10;
      p += mirror(upper/10, (d-1)/2);
    }
    __int64 q = p * p;
    bool ok = isPalindrome(q);
    if (q > B) break;
    if (ok && test && q >= A)
      printf("%7lld %14lld %s\n", p, q, ok? "true":"");
    int od = numDigits(upper);
    upper++;
    int nd = numDigits(upper);
    if (nd > od) {
      d++;
      // upper:99 p:999  d:3 => upper:10  p:1001  d:4
      // upper:99 p:9999 d:4 => upper:100 p:10001 d:5
      if (d % 2 == 0) upper /= 10;
    }
    if (ok && q >= A) total++;
  }
  printf("Case #%d: %d\n", cn, total);
}

void runTest() {
  A = 1L;
  B = 100000000000000L;
  int total = 0;
  for (__int64 p = 1; p < 10000000; p++) {
    if (!isPalindrome(p)) continue;
    __int64 q = p * p;
    if (!isPalindrome(q)) continue;
    printf("%2d %7lld %14lld\n", ++total, p, q);
  }
}


int main(int argc, char* argv[]) {
	// reopen("sample.in");
  // reopen("C-small-attempt0.in");
  reopen("C-large-1.in");
  // runTest();
  /*
  A = 1L;
  B = 90000000000000L;
  solve(1);
  */
	scanf("%d", &T);
	for(int t=1; t<=T; t++) {
    scanf("%lld %lld", &A, &B);
    // showin();
    solve(t);
  }
 	return 0;
}
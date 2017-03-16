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

const char rootdir[] = "C:\\CodeJam\\CounterCulture";
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
__int64 N;

__int64 A[16];

__int64 mypow(__int64 n, int m) {
  __int64 output = 1;
  for (int i = 0; i < m; i++) output *= n;
  return output;
}

__int64 reverse(__int64 n) {
  __int64 output = 0;
  while (n > 0) {
    __int64 v = n % 10;
    output = output * 10 + v;
    n = n / 10;
  }
  return output;
}

__int64 lastk(__int64 n, int k) {
  return n % mypow(10, k);
}

__int64 getValue(__int64 n) {
  __int64 output = 0;
  int k = 0;
  __int64 v = n;
  while (v > 0) {
    k++;
    v = v / 10;
  }
  if (k == 1) return n;
  int m = k >> 1;
  if (k % 2 != 0) m++;
  __int64 low = lastk(n, m);
  __int64 high = n / mypow(10, m);
  __int64 high_reverse = reverse(high);

  if (low == 0) return 1 + getValue(n-1);
  output += low - 1;  // high ..... 01
  if (high_reverse == 1) {
    // 1000001
    output += 2;
    // 99999
    return output + A[k-1];
  } else {
    output++;
    // 1000 ... high_reverse
    output += high_reverse + 1 + A[k-1];
  }
  return output;
}

int main() {
  test = false;
  // reopen("sample.in");
  // reopen("A-small-attempt3.in");
  reopen("A-large.in");

  // precompute count of 999...9 (k of 9) in A[k]
  A[0] = 0;
  A[1] = 9;
  for (int k = 2; k < 16; k++) {
    int m = (k >> 1);
    if (k % 2 == 0) {
      A[k] = 2*(mypow(10, m)- 1) + 1 + A[k-1];
    } else {
      A[k] = (mypow(10, m+1) - 1) + (mypow(10, m) - 1) + 1 + A[k-1];
    }
    if (test) printf("%3d %lld\n", k, A[k]);
  }

  if (test) {
    __int64 n = 12345678909876;
    printf("%lld %lld\n", n, getValue(n));
  }

  scanf("%d", &T);
  for (int TC = 1; TC <= T; TC++) {
    scanf("%lld", &N);
    __int64 output = getValue(N);
    if (test) printf("Case #%d: N=%lld %lld\n", TC, N, output);
    else printf("Case #%d: %lld\n", TC, output);
  }
  return 0;
}
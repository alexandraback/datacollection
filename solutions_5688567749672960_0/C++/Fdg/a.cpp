#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <memory.h>
#include <cmath>
#include <string> 
#include <ctime>

using namespace std;

#undef Fdg_Home

map<long long, long long> f;

long long go(long long n) {
  // if (f.count(n)) return f[n];
  if (n == 1) return 1;
  long long ret = 0;
  while (n > 1) {
    long long rev = 0, k = n, was = 0;
    if (k % 10 > 0) {
      while (k > 0) rev = rev * 10 + k % 10, k /= 10;
      if (rev < n)
        n = rev, was = 1;
    }
    if (!was)
      n = n - 1;
    ++ret;
    // cout << n << endl;
  }
  // cout << n << "  " << rev << " " << ret + 1 << endl;
  return ret + 1;
}

long long go2(long long n) {
  if (f.count(n)) return f[n];
  if (n == 1) return 1;
  long long ret = go2(n - 1);
  long long rev = 0, k = n, was = 0;
  if (k % 10 > 0) {
    while (k > 0) rev = rev * 10 + k % 10, k /= 10;
    if (rev < n)
      ret = min(ret, go2(rev)), was = 1;
  }
  // cout << n << endl;
  // cout << n << "  " << rev << " " << ret + 1 << endl;
  return f[n] = ret + 1;
}

void solveTest(int CS) {
  printf("Case #%d: ", CS);
  // f.clear();
  long long n;
  scanf("%lld", &n);
  printf("%lld\n", go2(n));
}

int main() {
#ifndef Fdg_Home
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int T;
  scanf("%d\n", &T);

  for (int i = 1; i <= 1000000; ++i)
    go2(i);

  for (int test = 1; test <= T; ++test) {
    solveTest(test);
  }
  return 0;
}
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

bool valid(long long a, long long n, long long t) {
  if (a > t / n) return false;
  t -= a * n;
  return 2 * (n-1) * n <= t;
}

int main() {
  int cases; cin >> cases;
  for (int caseNo = 1; caseNo <= cases; caseNo++) {
    long long r;
    long long t;
    cin >> r >> t;
    long long a = r*2+1;
    long long hi = 1000000000;
    long long lo = 0;
    while (lo+1 < hi) {
      long long n = (lo+hi) / 2;
      if (valid(a, n, t)) lo = n; else hi = n;
    }
    cout << "Case #" << caseNo << ": " << lo << endl;
  }
  return 0;
}
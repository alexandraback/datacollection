#include <cstdio>
#include <cassert>
#include <algorithm>
#include <iostream>
using namespace std;

int solve(int n, int m, int k) {
  if (n <= 2 || m <= 2) {
    return k;
  }

  if (n < m) {
    swap(n, m);
  }

  int maxw = n;
  int candidate = min((k+4)/3, maxw);
  int result = candidate*2-2;
  if (candidate*3 - 4 < k) {
    result += k - (candidate*3-4);
  }
  return result;
}

int main() {
  int zet;
  assert(scanf("%d", &zet) == 1);
  int caseNo = 1;
  while (zet--) {
    printf("Case #%d: ", caseNo);
    caseNo++;
    int n, m, k;
    assert(scanf("%d %d %d", &n, &m, &k) == 3);
    printf("%d\n", solve(n, m, k));
  }
  return 0;
}

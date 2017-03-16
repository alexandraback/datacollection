#include <stdio.h>
#include <set>

using std::set;

set<long long> ans;
void test(long long x) {
  long long x2 = x * x;
  long long t = 0;
  while (x2) {
    t = t * 10 + x2 % 10;
    x2 /= 10;
  }
  if (t == x * x) {
    ans.insert(t);
  }
}
int check(int x) {
  long long t = x;
  int tx = x;
  while (tx) {
    t = t * 10 + tx % 10;
    tx /= 10;
  }
  test(t);
  long long ct = t;
  t = x / 10;
  tx = x;
  while (tx) {
    t = t * 10 + tx % 10;
    tx /= 10;
  }
  if (t != ct) test(t);
}
int main() {
  for (int i = 1; i < 40000; i++) check(i);
  int T, cp = 0;
  for (scanf("%d", &T); T; T--) {
    long long A, B;
    scanf("%lld%lld", &A, &B);
    int ret = 0;
    for (set<long long>::iterator it = ans.begin(); it != ans.end(); it++)
      if (*it >= A && *it <= B) ++ret;
    printf("Case #%d: %d\n", ++cp, ret);
  }
  return 0;
}

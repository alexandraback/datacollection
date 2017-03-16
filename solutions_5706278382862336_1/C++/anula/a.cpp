#include <cstdio>
#include <cassert>
using namespace std;

long long gcd(long long n, long long m)
{
  long long gcd, remainder;

  while (n != 0)
  {
    remainder = m % n;
    m = n;
    n = remainder;
  }

  gcd = m;

  return gcd;
}

int whichPowerOfTwo(long long x) {
  int pow = 0;
  while(x % 2 == 0) {
    pow++;
    x /= 2;
  }
  if (x != 1) {
    return -1;
  }
  return pow;
}

int maxPowerOfTwo(long long x) {
  int pow = 0;
  long long curr = 1;
  while (curr * 2 <= x) {
    curr *= 2;
    pow++;
  }
  return pow;
}

void lownij(long long &p, long long &q) {
  long long nwd = gcd(p, q);
  p /= nwd;
  q /= nwd;
}

bool solve(long long p, long long q, int &result) {
  if (p > q) {
    return false;
  }
  lownij(p, q);

  int qpow = whichPowerOfTwo(q);
  if (qpow == -1 || qpow > 40) {
    return false;
  }

  long long ancestors = 1LL<<40;
  long long mul = ancestors / q;
  long long newp = mul*p;
  int fromTop = maxPowerOfTwo(newp);
  //printf("anc: %lld mul: %lld newp: %lld fromTop: %d\n",ancestors, mul, newp, fromTop);
  result = 40 - fromTop;
  if (result < 1) {
    result = 1;
  }
  return true;
}

int main() {
  int zet;
  assert(scanf("%d", &zet) == 1);
  int caseNo = 1;
  while (zet--) {
    printf("Case #%d: ", caseNo);
    caseNo++;
    long long p, q;
    assert(scanf("%lld/%lld", &p, &q) == 2);
    int result;
    if (solve(p, q, result)) {
      printf("%d\n", result);
    } else {
      printf("impossible\n");
    }
  }
  return 0;
}

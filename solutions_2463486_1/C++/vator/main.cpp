#include <cmath>
#include <algorithm>
#include <iomanip>
#include <algorithm>
#include <cstdio>
#include <map>

using namespace std;

inline bool isSquare(long long n)
{
  long long r = sqrt(n);
  return r*r == n;
}

inline int getDigit(long long n, int c)
{
  for (int i = 1; i < c; i++) n/=10LL;
  return n%10LL;
}

inline bool isPoly(long long n)
{
  int len = 0;
  long long p = n;
  while (p) {
    p /= 10LL;
    len++;
  }
  for (int i = 0; i < len/2; i++) {
    if (getDigit(n, i+1) != getDigit(n, len-i)) return false;
  }
  return true;
}

long long A[1111];
map<long long, int> mp;

int main(void)
{
  int t;
  int len = 0;
  //freopen("input.txt", "rt", stdin);
  //freopen("output.txt", "wt", stdout);
  for (long long i = 1; i < 150000000; i++) {
    if (isPoly(i) && isPoly(i*i)) {
      mp[i*i] = len;
      A[len++] = i*i;
    }
  }
  scanf("%d",&t);
  for (int i = 0; i < t; i++) {
    long long a,b;
    long long x,y;
    scanf("%lld%lld",&a,&b);
    x = *lower_bound(A,A+len,a);
    y = *lower_bound(A,A+len,b+1);
    printf("Case #%d: %d\n", i+1, mp[y] - mp[x]);
  }
  return 0;
}

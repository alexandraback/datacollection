#include <cstdio>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <ctime>
#include <cassert>
using namespace std;

#define max2(a,b) (((a) > (b)) ? (a) : (b))
#define min2(a,b) (((a) < (b)) ? (a) : (b))

#define debug(x) cout << (#x) << ": " << (x) << endl
#define echo(x) cout << (#x) << endl
#define TIMER_A(timer) int timer = clock()
#define TIMER_B(timer) cerr << (#timer) << ": " << (double)(clock() - timer) / CLOCKS_PER_SEC << endl

typedef long long LL;
const double eps = 1e-9;
const double pi = M_PI;
const int inf = 2000000000; // 2e9
const LL inf64 = 9000000000000000000LL; // 9e18

const int maxSR = 10000000; // 1e7

int TN, TC;
LL A, B;

int cum[maxSR + 1];

int sA, sB;

bool isFair (LL x)
{
  static int digit[15];
  int n = 0;
  while (x)
  {
    digit[n++] = x % 10;
    x /= 10;
  }
  for (int i = 0; i < n / 2; ++i)
    if (digit[i] != digit[n - 1 - i])
      return false;
  return true;
}

bool isValid (int x)
{
  if (isFair(x) && isFair((LL)x * x))
  {
    // printf("%d\n", x);
    return true;
  }
  else
    return false;
}

void calcCum ()
{
  cum[0] = 0;
  for (int i = 1; i <= maxSR; ++i)
    cum[i] = cum[i - 1] + isValid(i);
}

LL sqrt (LL x)
{
  LL l = (LL)floor(sqrt(x * 0.9)), r = (LL)ceil(sqrt(x * 1.1));
  while (r - l > 1)
  {
    LL m = (l + r) / 2;
    if (m * m <= x)
      l = m;
    else
      r = m;
  }
  return l;
}

int main ()
{
  calcCum();
  scanf("%d", &TN);
  for (TC = 1; TC <= TN; ++TC)
  {
    scanf("%lld%lld", &A, &B);
    int sA = sqrt(A);
    int sB = sqrt(B);
    if ((LL)sA * sA == A)
      --sA;
    int num = cum[sB] - cum[sA];
    printf("Case #%d: %d\n", TC, num);
  }
}

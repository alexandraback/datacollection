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

const int maxN = 100;

int TN, TC;

int A, N;
int mote[maxN];

void input ()
{
  scanf("%d%d", &A, &N);
  for (int i = 0; i < N; ++i)
    scanf("%d", &mote[i]);
}

int numAdd (int N)
{
  int num = 0;
  int m0 = A;
  for (int i = 0; i < N; ++i)
  {
    while (m0 <= mote[i])
    {
      m0 += m0 - 1;
      ++num;
    }
    m0 += mote[i];
  }
  return num;
}

void solve ()
{
  if (A == 1)
  {
    printf("%d\n", N);
    return;
  }
  sort(mote, mote + N);
  int ans = N;
  for (int i = 0; i < ans; ++i)
  {
    int d = numAdd(N - i) + i;
    ans = min2(ans, d);
  }
  printf("%d\n", ans);
}

int main ()
{
  scanf("%d", &TN);
  for (TC = 1; TC <= TN; ++TC)
  {
    input();
    printf("Case #%d: ", TC);
    solve();
  }
}

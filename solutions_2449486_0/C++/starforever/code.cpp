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

int TN, TC;

const int maxN = 100;
const int maxM = 100;

int N, M;
int board[maxN][maxM];

int hr[maxN];
int hc[maxM];

bool isPossible ()
{
  for (int i = 0; i < N; ++i)
  {
    hr[i] = 0;
    for (int j = 0; j < M; ++j)
      hr[i] = max2(hr[i], board[i][j]);
  }
  for (int j = 0; j < M; ++j)
  {
    hc[j] = 0;
    for (int i = 0; i < N; ++i)
      hc[j] = max2(hc[j], board[i][j]);
  }
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < M; ++j)
      if (board[i][j] != min2(hr[i], hc[j]))
        return false;
  return true;
}

int main ()
{
  scanf("%d", &TN);
  for (TC = 1; TC <= TN; ++TC)
  {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; ++i)
      for (int j = 0; j < M; ++j)
        scanf("%d", &board[i][j]);
    bool r = isPossible();
    printf("Case #%d: %s\n", TC, r ? "YES" : "NO");
  }
}

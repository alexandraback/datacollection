#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int MaxN = 111;

long long a[MaxN], b[MaxN];
int A[MaxN], B[MaxN]; 
int m, n;
long long res;

void go (int ax, int bx, long long tres)
{
  if (res < tres)
    res = tres;
  if (ax >= n || bx >= m)
    return;
  if (A[ax] == B[bx])
  {
    long long t = min (a[ax], b[bx]);
    int tax = ax, tbx = bx;
    tres += t;
    a[ax] -= t;
    b[bx] -= t;
    if (a[ax] == 0)
      tax++;
    if (b[bx] == 0)
      tbx++;
    go (tax, tbx, tres);
    a[ax] += t;
    b[bx] += t; 
    tres -= t;
  }
  else
  {
    go (ax + 1, bx, tres);
    go (ax, bx + 1, tres);
  }
}

              
int main (void)
{
  int test, tests;

  scanf ("%d", &tests);
  for (test = 0; test < tests; test++)
  {
    int i, j;
    scanf ("%d %d", &n, &m);
    res = 0;
    for (i = 0; i < n; i++)
      scanf ("%I64d %d", &a[i], &A[i]);
    for (i = 0; i < m; i++)
      scanf ("%I64d %d", &b[i], &B[i]);
    res = 0;
    go (0, 0, 0);      
    printf ("Case #%d: %I64d\n", test + 1, res);
    
  }
  return 0;
}

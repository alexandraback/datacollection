#include <cmath>
#include <algorithm>
#include <iomanip>
#include <algorithm>
#include <cstdio>

using namespace std;

inline bool isSquare(int n)
{
  int r = sqrt(n);
  return r*r == n;
}

inline bool isPoly(int n)
{
  if (n < 10)
    return true;
  if (n < 100)
    return (n%10 == n/10);
  return (n%10 == n/100);
}

int A[1111];

int main(void)
{
  int t;
  //freopen("input.txt", "rt", stdin);
  //freopen("output.txt", "wt", stdout);
  for (int i = 1; i < 1000; i++) {
    A[i] = A[i-1];
    if (isSquare(i) && isPoly(i) && isPoly(sqrt(i))) A[i]++;
  }
  A[1000] = A[999];
  scanf("%d",&t);
  for (int i = 0; i < t; i++) {
    int a,b;
    scanf("%d%d",&a,&b);
    printf("Case #%d: %d\n", i+1, A[b] - A[a-1]);
  }
  return 0;
}

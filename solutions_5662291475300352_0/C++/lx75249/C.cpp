#include <cstring>
#include <cstdio>
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

int d[10], m[10];
int tot;
void init()
{
  int n;
  tot = 0;
  cin >> n;
  while (n--)
  {
    int D, H, M;
    cin >> D >> H >> M;
    while (H--)
    {
      ++tot;
      d[tot] = D;
      m[tot] = M++;
    }
  }
}
double s[10];
int work()
{
  if (tot == 1)
    return 0;
  if (m[1] == m[2])
    return 0;
  if (d[1] > d[2])
  {
    swap(d[1], d[2]);
    swap(m[1], m[2]);
  }
  s[1] = 360.0/m[1];
  s[2] = 360.0/m[2];
  double t;
  if (s[2] > s[1])
  {
    t = (360-d[2]+d[1])/(s[2]-s[1]);
    if (d[1] + t*s[1] > 360)
      return 0;
    return 1;
  }
  t = (360+d[2]-d[1])/(s[1]-s[2]);
  if (d[2]+t*s[2] > 360)
    return 0;
  return 1;
}

int main()
{
  //freopen("in","r",stdin);
  int T;
  cin >> T;
  for(int i=1; i<=T; ++i)
  {
    init();
    printf("Case #%d: %d\n", i, work());
  }
}

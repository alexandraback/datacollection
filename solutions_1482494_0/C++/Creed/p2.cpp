#include <iostream>
#include <cstdio>
using namespace std;
const int N = 1010;
int t, n, a[N], b[N], f[N];
int main()
{
  freopen("B-small-attempt2.in", "r", stdin);
  freopen("O.txt", "w", stdout);
  cin >> t;
  for(int q = 0; q < t; q++)
  {
    cin >> n;
    for(int i = 0; i < n; i++)
      cin >> a[i] >> b[i];
    for(int i = 0; i < n; i++)
      f[i] = 0;
    int cnt = 0, ans = 0, sc = 0, pos;
    bool flag = false;
    while(cnt < n && !flag)
    {
      int tp = 0, st = 0;
      for(int i = 0; i < n; i++)
      {
        if (f[i] == 0 && a[i] <= sc && tp < 1)
        {
          pos = i;
          tp = 1;
        }
        if (f[i] <= 1 && b[i] <= sc && tp <= 2)
        {
          tp = 2;
          if (f[i] == 0 && st <= 1)
          {
            pos = i;
            st = 2;
          }
          if (f[i] == 1 && st == 0)
          {
            pos = i;
            st = 1;
          }
        }
      }
      if (tp == 0)
        flag = true;
      else if (tp == 1)
      {
        f[pos] = 1;
        sc++;
      }
      else
      {
        if (f[pos] == 0)
          sc += 2;
        else
          sc++;
        f[pos] = 2;
        cnt++;
      }
      ans++;
    }
    if (flag)
      printf("Case #%d: Too Bad\n", q + 1);
    else
      printf("Case #%d: %d\n", q + 1, ans);
  }
  return 0;
}

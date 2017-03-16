#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int a[3]; int kk;
int all;

int cnt[256];

bool check(int mask)
{
  memset(cnt, 0, sizeof(cnt));

  int pos = 0;
  for(int i = 0; i < a[0]; i++)
    for(int j = 0; j < a[1]; j++)
      for(int k = 0; k < a[2]; k++, pos++)
      {
        if(mask&(1<<pos))
        {
          int p1 = (i+1) * 25 + (j+1)*5 + (k+1);
          int p2 = (i+1) * 25 + (0)*5 + (k+1);
          int p3 = (0) * 25 + (j+1)*5 + (k+1);
          int p4 = (i+1) * 25 + (j+1)*5 + (0);


          if(cnt[p2] >= kk
            || cnt[p3] >= kk
            || cnt[p4] >= kk
            || cnt[p1] > 0)
          {
            return false;
          }

          cnt[p1] ++;
          cnt[p2] ++;
          cnt[p3] ++;
          cnt[p4] ++;
        }
      }
      return true;
}

void printresult(int mask)
{
  //cout << mask << endl;
  cout << __builtin_popcount(mask) << endl;

  int pos = 0;
  for(int i = 0; i < a[0]; i++)
    for(int j = 0; j < a[1]; j++)
      for(int k = 0; k < a[2]; k++, pos++)
      {
        if(mask&(1<<pos))
        {
          cout << i+1 << " " << j+1 << " " << k+1 << endl;
        }
      }

}

void solve()
{
  cin >> a[0] >> a[1] >> a[2] >> kk;

  all = a[0] * a[1] * a[2];

  int mask = 0, maxmask = 0, ret = 0;
  for(mask = 0; mask < (1<<all); mask++)
  {
    if(check(mask))
    {
      int o = __builtin_popcount(mask);
      if(o > ret)
      {
        ret = o;
        maxmask = mask;
      }
    }
  }

  printresult(maxmask);
}

int main()
{
  int t;
  scanf("%d", &t);

  for(int i = 1; i<=t; i++)
  {
    printf("Case #%d: ", i);
    solve();
  }
  return 0;
}

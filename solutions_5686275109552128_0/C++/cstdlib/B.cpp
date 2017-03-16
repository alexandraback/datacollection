#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;

int ccount[1100];
int solve(int toeat)
{
  int ans = 0;
  int eaten = 0;
  while(eaten < toeat)
    {
      bool ok = false;
      int p = 1009;
      for(; p >= 3; p--)
      {
        if(ccount[p] > 0)
        {
          ok = true;
          break;
        }
      }
      if(ok) 
      {
        int r1 = p / 2;
        int r2 = p - p / 2;
        int ti = p;
        int op = max(r1, r2);
        int maa = op;
        for(int j = 1099; j >= 1; j--)
          if(j != p && ccount[j] && j >= op)
            maa = j;
        int need = ccount[ti] + maa;
        if(need <= ti)
        {
          ans += ccount[ti];
          ccount[r1] += ccount[ti];
          ccount[r2] += ccount[ti];
          ccount[ti] = 0;
        }
      }
      for(int p = 1; p <= 1099; p++)
      {
        if(ccount[p] > 0)
        {
          ccount[p - 1] += ccount[p]; 
          eaten += ccount[p];
          ccount[p] = 0;
        }
      }
      ans++;
    }
    return ans;

}
int main()
{
  int T;
  cin>>T;
  for(int i = 1; i <= T; i++)
  {
    memset(ccount, 0, sizeof ccount); 
    int  D, P, toeat = 0, eaten = 0;
    cin>>D;
    for(int j = 0; j < D; j++)
    {
      cin>>P;
      toeat += P;
      ccount[P]++;
    }
    printf("Case #%d: %d\n", i, solve(toeat));
  }

  return 0;
}

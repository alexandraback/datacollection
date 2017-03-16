#include <cstdio>
#include <set>
#include <iostream>

using namespace std;

#define DBG(X)

int solvesmall(int c, int w)
{
  int ret = 0;
      if (c == w)
      {
        ret = c;
      }
      else
      {
        if (c < 2 * w)
        {
          ret = w + 1;
        }
        else
        {
          if (c % w == 0)
          {
            ret = c / w - 1 + w;
          }
          else
          {
            ret = c / w + w;
          }
        }
      }
      
      return ret;
  
}

int main()
{
  int r, c;
  int t;
  scanf("%d", &t);
  int z = 1;
  while (z <= t)
  {
    int ret = 0;
    int r, c, w;
    scanf("%d%d%d", &r, &c, &w);
    //cout << " r c  " << r << " " << c << endl;
    
    if (r == 1)
    {
      if (c == w)
      {
        ret = c;
      }
      else
      {
        if (c < 2 * w)
        {
          ret = w + 1;
        }
        else
        {
          if (c % w == 0)
          {
            ret = c / w - 1 + w;
          }
          else
          {
            ret = c / w + w;
          }
        }
      }
    }
    else
    {
      ret = ((c + w - 1) / w) * (r - 1) + solvesmall(c, w);
    }
    
    printf("Case #%d: %d\n", z, ret);
    z++;
  }
  
  return 0;
}

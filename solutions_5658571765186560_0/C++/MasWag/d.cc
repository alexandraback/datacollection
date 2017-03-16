#include <cstdio>
#include <algorithm>

using namespace std;

#define rep(i,n) for (int i = 0; i < n; i++)
int main(void)
{
  int T;
  scanf ("%d",&T);

  rep (t,T)
    {
      int X,R,C;
      int result = 0;
      scanf ("%d %d %d",&X,&R,&C);
      if ((R * C) % X || max (R,C) < X || min (R,C) * 2 < X)
        goto end;
      // magic number
      if (R * C == 8 && X == 4)
        goto end;
      result = 1;
      end:
      printf ("Case #%d: %s\n",t+1,result ? "GABRIEL" : "RICHARD");
    }
  return 0;
}


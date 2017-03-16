#include<bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  scanf("%d", &t);
  for(int i = 1; i <= t; i++)
  {
      int r,c,w;
      scanf("%d%d%d", &r, &c, &w);
      int odp = (c/w)*(r-1) + (c-w)/w + w;
      if( (c-w)%w != 0 ) odp += 1;
      printf("Case #%d: %d\n", i, odp);
  }

return 0;
}
#include <cstdio>
#include <string>
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
#include <array>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <utility>
#include <cinttypes>


void solve( int64_t b, int64_t m )
{
  int64_t max_possi = ((int64_t)1 <<(b-2));
  if (m> max_possi )
  {
    printf(" IMPOSSIBLE\n");
    return;
  }
  printf(" POSSIBLE\n");
  for ( int i=0; i< b; ++i)
  {
    for (int j=0;j+1<b;++j)
    {
      printf("%d",(int)(j>i));
    }
    if (i==0)
    { if(m==max_possi)
      {
        printf("1");
        --m;
      }
      else
        printf("0");
    }
    else
    {
      if ( ((int64_t)1<<(i-1)) & m )
        printf("1");
      else
        printf("0");
    }
    printf("\n");
  }
}

int main(int arng, char**argv)
{
  int ncase;
  scanf("%d",&ncase);
  for (int icase=0;icase<ncase;++icase)
  {
    int64_t b,m;
    scanf("%lld%lld",&b,&m);
    printf("Case #%d:",icase+1);
    solve(b,m);
  }
  return 0;
}

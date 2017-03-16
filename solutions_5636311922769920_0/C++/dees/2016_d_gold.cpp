#include <cstdio>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <array>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <utility>
#include <cinttypes>

void solve(int k,int c,int s)
{
  if ( c*s < k )
  {
    printf(" IMPOSSIBLE");
    return;
  }
  int checkked = 0;
  while ( checkked < k )
  {
    int64_t check = checkked;
    for ( int i = 1; i < c; ++i )
    {
      check *= c;
      check += i;
    }
    printf(" %lld", check+1 );
    checkked += c;
  }
}

int main(int arng, char**argv)
{
  int ncase;
  scanf("%d",&ncase);
  for (int icase=0;icase<ncase;++icase)
  {
    int k,c,s;
    scanf("%d%d%d",&k,&c,&s);
    printf("Case #%d:",icase+1);
    solve(k,c,s);
    printf("\n");
  }
  return 0;
}

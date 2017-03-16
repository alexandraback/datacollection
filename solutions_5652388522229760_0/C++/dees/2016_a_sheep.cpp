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

int sheep(int n)
{
  if (n==0)
    return 0;
  std::vector<bool> matched(10);
  int nmatched = 0;
  int c = 0;
  do
  {
    c+=n;
    int p = c;
    while ( p > 0 )
    {
      int num = p % 10;
      if ( ! matched[num] )
      {
        matched[num]=true;
        ++nmatched;
      }
      p/=10;
    }
  }  while ( nmatched < 10 );
  return c;
}

int main(int arng, char**argv)
{
  int ncase;
  scanf("%d",&ncase);
  for (int icase=0;icase<ncase;++icase)
  {
    int n;
    scanf("%d",&n);
    printf("Case #%d: ",icase+1);
    int res = sheep(n);
    if ( res )
      printf("%d\n",res);
    else
      printf("INSOMNIA\n");
  }
  return 0;
}

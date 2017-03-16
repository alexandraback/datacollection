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


int solve(std::vector<bool>& v)
{
  int changes = 0;
  bool c = v[0];
  for ( bool b: v )
  {
    if ( c!=b ) ++changes;
    c = b;
  }
  if ( ! ( (changes & 1) ^ v[0] ) ) ++changes;
  return changes;
}

int main(int arng, char**argv)
{
  int ncase;
  scanf("%d",&ncase);
  for (int icase=0;icase<ncase;++icase)
  {
    char s[101];
    scanf("%100s",s);
    std::string str(s);
    std::vector<bool> v;
    for ( char c : str )
      v.push_back( c == '+' );
    printf("Case #%d: %d\n",icase+1,solve(v));
  }
  return 0;
}

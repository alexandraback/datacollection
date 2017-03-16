#include <cstdio>
#include <cstdint>
#include <cstring>
#include <cassert>
#include <bitset>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>
#include <sstream>

int solve( int A, std::vector<int>& motes )
{
  if ( A==1 )
    return motes.size();
  int best=motes.size();
  int cur=0;
  while( !motes.empty() )
  {
    while (!motes.empty()&&motes.back()<A)
    {
      A+=motes.back();
      motes.pop_back();
    }
    best = std::min(best,static_cast<int>(cur+motes.size()));
    ++cur;
    A+=A-1;
  }
  return best;
}

int main( int argn, char** argv )
{
  int ncases;
  scanf("%d",&ncases);
  for ( int icase = 0; icase<ncases; ++icase )
  {
    int A,N;
    scanf("%d%d",&A,&N);
    std::vector<int> motes;
    motes.resize(N);
    for ( int i=0;i<N;++i)
      scanf("%d",&motes[i]);
    std::sort(std::begin(motes),std::end(motes),
	      [](int a,int b){return b<a;});
    int res = solve(A,motes);
    printf("Case #%d: %d\n",icase+1,res);
  }
  return 0;
}

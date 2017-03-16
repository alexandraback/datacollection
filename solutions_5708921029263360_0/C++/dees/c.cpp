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

int j,p,s,k;

std::vector< std::vector<int> > best;

void doit( std::vector<std::vector<int> > combis,
           std::vector<std::vector<std::vector<int> > > used,
           int xstart, int ystart, int zstart
  )
{
//  printf("%d %d %d %d\n",j,p,s,k);
  for (int x=xstart;x<j;++x)
    for (int y=ystart;y<p;++y)
      for (int z=zstart;z<s;++z)
      {
        if ( used[x][3][z] < k
             && used[3][y][z] < k
             && used[x][y][3] < k
             && used[x][y][z] == 0
          )
        {
          auto used2 = used;
          ++used2[x][3][z];
          ++used2[3][y][z];
          ++used2[x][y][3];
          ++used2[x][y][z];
          auto combis2 = combis;
          std::vector<int> tmp(3);
          tmp[0]=x;
          tmp[1]=y;
          tmp[2]=z;
          combis2.push_back( tmp );

          if ( combis2.size() > best.size() )
            best = combis2;
          doit( combis2, used2, x, y, z );
        }
      }
}

void solve()
{
  best.resize(0);
  scanf("%d%d%d%d",&j,&p,&s,&k);
  std::vector< std::vector< std::vector<int> > > used(4);
  for ( std::vector< std::vector<int> >& a : used )
  {
    a.resize(4);
    for ( std::vector<int>& b : a )
      b.resize(4);
  }
  doit(std::vector<std::vector<int> >(),used,0,0,0);

  printf(" %d\n",(int)best.size());
  for ( const std::vector<int>& a : best )
  {
    printf("%d %d %d\n",a[0]+1,a[1]+1,a[2]+1);
  }

};

int main(int arng, char**argv)
{
  int ncase;
  scanf("%d",&ncase);
  for (int icase=0;icase<ncase;++icase)
  {
    printf("Case #%d:",icase+1);
    solve();
  }
  return 0;
}

#include <cstdio>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std ;

typedef unsigned long long ull ;
int size[2] ;
const int Tm = 100+10; 
int type[2][Tm] ;
ull nb[2][Tm] ;


struct hash_ull
{
  size_t operator () ( const pair<ull,ull> & o ) const
  {
    return o.first*3 + o.second ;
  }
};

unordered_map< pair<ull,ull> , ull,hash_ull> seen[Tm][Tm] ; 

ull best_match( int id0, ull took0, int id1, ull took1 )
{
  if( id0 >= size[0] || id1 >= size[1] )
    return 0 ;
  if( type[0][id0] == type[1][id1] )
    {
      const ull take = min( nb[0][id0]-took0, nb[1][id1]-took1 ) ;
      took0 += take ;
      took1 += take ;
      if( nb[0][id0] == took0 )
	{
	  id0++ ;
	  took0 = 0 ;
	}
      if( nb[1][id1] == took1 )
	{
	  id1++ ;
	  took1 = 0 ;
	}
      return best_match(id0,took0,id1,took1)+take;
    }
  const pair<ull,ull> key = make_pair( took0,took1 ) ; 
  
  if(seen[id0][id1].find(key) != seen[id0][id1].end() )
    return seen[id0][id1][key] ;
  const ull res = max( best_match(id0,took0,id1+1,0),best_match(id0+1,0,id1,took1) ) ;
  seen[id0][id1][key] = res ;
  return res ;
}

ull algo()
{
  for( int x = 0 ; x < Tm ; x++ )
    for( int y = 0 ; y < Tm ; y++ )
      seen[y][x].clear();
  scanf("%d %d",&size[0],&size[1]);
  for( int s = 0 ; s < 2 ; s++ )
    for( int i = 0 ; i < size[s] ; i++ )
      scanf("%llu %d",&nb[s][i],&type[s][i]);
  return best_match(0,0,0,0);
}

int main()
{
  int t;
  scanf("%d",&t);
  for(int i = 1 ; i <= t ; i++ )
    printf("Case #%d: %llu\n",i,algo());
  return 0;
}

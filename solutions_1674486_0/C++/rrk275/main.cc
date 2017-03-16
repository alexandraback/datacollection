#include <cstdio>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std ;

const int Tm = 1000+10 ;
vector<int> inherit[Tm] ;
int n ;
int view[Tm] ;

void explore( int c) 
{
  if( view[c]++ )
    return ;
  for( int nxt : inherit[c] )
    explore(nxt) ;
}

bool test( int i )
{
  fill(view,view+Tm,0);
  explore(i) ;
  for( int j = 0 ; j < n ; j++ )
    if(view[j] > 1 )
      return true ;
  return false ;
}

void algo()
{
  scanf("%d",&n);
  for(int i = 0 ; i < n; i++ )
    {
      inherit[i].clear();
      int nc ; 
      scanf("%d",&nc);
      while(nc--)
	{
	  int j ;
	  scanf("%d",&j);
	  inherit[i].push_back(j-1);
	}
    }
  for( int i = 0 ; i < n ; i++ )
    if( test(i) )
      {
	printf("Yes");
	return ;
      }
  printf("No");
}

int main()
{
  int t;
  scanf("%d",&t);
  for(int i = 1 ; i <= t ; i++ )
    {
      printf("Case #%d: ",i);
      algo();
      printf("\n");
    }
  return 0;
}

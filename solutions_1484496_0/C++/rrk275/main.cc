#include <cstdio>
#include <vector>
#include <map>
#include <unordered_set>
#include <algorithm>

using namespace std ;

typedef long long int lli ;

vector<lli> vals ;
unordered_set<lli> done ;
int n ;
vector<lli> res[2] ;

bool equals_set( lli c, lli val )
{
  if( c == n )
    return val == 0 ;
  
  const lli key = val*n+c ;
  if( done.find(key) != done.end() )
    return false ;
  done.insert(key) ;
  
  for( lli nxt = n ; nxt != c ; nxt-- )
    for( lli todo = -vals[c] ; todo <= vals[c] ; todo+=2*vals[c] )
      if( equals_set(nxt,val+todo ) )
	{
	  if( todo>=0 )
	    res[0].push_back(todo);
	  else
	    res[1].push_back(-todo);
	  return true ;
	}
  return false ;
}


void algo()
{
  res[1].clear();
  res[0].clear();
  vals.clear();
  done.clear();
  scanf("%d",&n);
  for ( int i = 0 ; i < n ; i++ )
    {
      int d ;
      scanf("%d",&d);
      vals.push_back(d);
    }
  sort( vals.begin(), vals.end() ) ;
  if( vals[0] + vals[1] == 0 )
    {
      printf("0\n0\n");
      return ;
    }
  for( size_t i = 0 ; i < vals.size() ; i++ )
    if( equals_set(i,0) )
      {
	for( int c = 0 ; c < 2 ; c++ )
	  {
	    for( lli j : res[c] )
	      printf("%lld ",j ) ;
	    printf("\n");
	  }
	return ;
      }
  printf("impossible\n");
}

int main()
{
  int t;
  scanf("%d",&t);
  for(int i = 1 ; i <= t ; i++ )
    {
      printf("Case #%d:\n",i);
      algo();
    }
  return 0;
}

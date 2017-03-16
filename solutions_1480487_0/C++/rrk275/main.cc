#include <cstdio>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std ;

vector<double> x ;
double totX ;

double arrange( double v , bool print = false )
{
  double tot = 0 ; 
  for( double c : x )
      {
	const double val = max( (v-c) / totX , 0. );
	if( print )
	  printf(" %lf",val*100);
	tot += val  ;
      }
  return tot ;
}

void algo()
{
  x.clear();
  totX = 0 ;
  int n ;
  scanf("%d",&n);
  for( int i = 0 ; i < n ; i++ )
    {
      double d ;
      scanf("%lf",&d);
      x.push_back(d);
      totX += d ;
    }
  double left = 0 , right = totX ;
  while( right-left > 0.00000001 )
    {
      const double mid = (left+right)/2;
      if( arrange(mid) > 1 )
	right = mid ;
      else 
	left = mid ;
    }
  arrange(left,true) ;
}

int main()
{
  int t;
  scanf("%d",&t);
  for(int i = 1 ; i <= t ; i++ )
    {
      printf("Case #%d:",i);
      algo();
      printf("\n");
    }
  return 0;
}

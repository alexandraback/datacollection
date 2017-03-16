#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;

#define FOR(i,n) for(int i = 0; i<(n); ++i)
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
#define X first
#define Y second
#define MP make_pair
#define PB push_back

typedef vector<int> VI;

long double ncr(long double n, long double r )
{
  if( r == 0)
    return 1.0;
  if( n == 0)
    return 0.0;
  return ncr(n-1,r) + ncr(n-1,r-1);
}

int main()
{
  int t=1;
  int T;
  cin>>T;
  while( t <= T )
    {
      printf("Case #%d: ", t);
      long double n, x, y;
      cin>>n>>x>>y;
      if( x < 0 ) x = -x;
      
      int rnd = 0;
      int dia = 0;
      while( dia + 1 +4*rnd <= n )
	dia += 1 + 4 * rnd, rnd++;
      
      int left = n - dia;
      
      if( x+y > 2 * rnd )
	printf("%.6lf", 0.0 );
      else if( x+y < 2 * rnd )
	printf("%.6lf", 1.0 );
      else if( x == 0 )
	printf("%.6lf", 0.0 );
      else
	{
	  int pos = 2 * rnd - x;
	  //	  cout<<"asdf "<<left<<" "<<pos<<endl;

	  long double arl[2 * rnd + 1];
	  memset(arl,0,sizeof(arl));
	  long double res = 0;
	  FOR(i, left )
	    {
	      if( left - (i+1 ) < 2 * rnd )
		if( i+1 >= pos )
		  res += ncr(left,i+1);
	    }
		
	  res /= pow(2,left);
	  printf("%.6Lf", res);
	  
	}
	
      printf("\n");
      t++;
    }
  return 0;
}

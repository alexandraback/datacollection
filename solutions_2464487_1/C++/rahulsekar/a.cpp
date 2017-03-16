#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
#include<cmath>
using namespace std;
int main()
{
  int t=1;
  int T;
  cin>>T;
  while( t <= T )
    {
      long double x, y;
      cin>>x>>y;
      long long int low = 1, high = y;
      while( high - low > 1 )
	{
	  long double mid = high + low;
	  mid /= 2;
	  if( y < 2 * x * mid + mid * ( 2 * mid - 1 ) )
	    high = ceil(mid);
	  else
	    low = mid;
	}
      //      cout<< 2 * low * x + low * ( 2 * low - 1 ) <<endl;
      cout<< "Case #"<<t<<": "<<low<<endl;

      t++;
    }
  return 0;
}

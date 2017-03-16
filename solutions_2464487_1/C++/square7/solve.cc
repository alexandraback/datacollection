#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cstdlib>
#include <cmath>

using namespace std;

long long cost(long long r, long long k)
{
  cerr << k << " " << r << endl;
  return 2*k*k+2*k*r-k;
}

int main()
{
  int cnt;
  cin >> cnt;
  for(int i = 0; i < cnt; ++i)
    {
      cout << "Case #" << i+1 << ": ";
      long long r, t;
      cin >> r >> t;
      long long min = 1;
      long long max = t/r;
      if(sqrt(t) < t/r)
	{max = sqrt(t)+1;}
      while(min != max)
	{
	  long long mid = (min+max)/2;
	  if(cost(r, mid) <= t)
	    {
	      min = mid+1;
	    }
	  else
	    {
	      max = mid;
	    } 
	}
      cout << min-1 << endl;
    }
}

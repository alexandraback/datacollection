#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int main()
{
  int T;
  cin >> T;
  
  int caseNum = 1;
  while(caseNum <= T)
  {
    long long r,t;
    cin >> r >> t;
    long long a,b;
    a = 1;
    b = min((long long) sqrt(t), t/(2*r-1));
    while((a+1) < b)
    {
      long long N = (b+a)/2;
      if( ( (2*r-1)*N + 2 * N * N ) <= t )
      {
        a = N;
      }
      else
      {
        b = N;
      }    
    }
    long long count;
    if(( (2*r-1)*b + 2 * b * b ) > t)
    {
      count = a;
    }
    else
    {
      count = b;
    }
    cout << "Case #" << caseNum << ": " << count << endl; 
  
    caseNum++;
  }

}
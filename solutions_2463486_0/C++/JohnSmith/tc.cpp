//
// Qualification round 2013  problem A
//
// Usually built with g++ 4.4.5 on Linux
//
#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <gmpxx.h>

#include <cstdlib>
#include <math.h>

using namespace std;

typedef unsigned long long bigint;

unsigned int digits( bigint x )
{
     unsigned int n=0;
     while (x > 0)
     {
	  n++;
	  x /= 10;
     }
     return n;
}

unsigned int is_palindrome( bigint x )
{
     if (x==0) return true;
     unsigned int n = digits(x);

     bigint dd = 1;
     for (auto i=1u; i<n; i++) dd*=10;

     while (x)
     {
	  if (x/dd != x%10) return false;

	  x -= x/dd*dd;
	  x /= 10;
	  dd /= 100;
     }
     return true;
}

int main( int argc, char ** argv )
{
     vector<bigint> vv;
     bigint t7 = 10000000;
     for (bigint k=1; k*k<t7*t7; k++)
     {
	  if (is_palindrome(k) && is_palindrome(k*k)) 
	  {
	       //cerr << setw(18) << k*k << " " << setw(10) << k << endl;
	       vv.push_back(k*k);
	  }
     }


     unsigned int t;

     cin >> t;

     for (auto i=1u; i<=t; i++) {

	  bigint a;
	  bigint b;

	  cin >> a;
	  cin >> b;

	  unsigned int r=0;

	  for ( auto x : vv)
	  {
	       if (x>=a && x<=b) r++;
	  }

	  cout << "Case #" << i << ": ";
	  cout << r << endl;
     }

     return 0;
}


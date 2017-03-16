//
// Qualification round 2015 problem B
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

unsigned int solve( vector<unsigned int> v )
{
     set<unsigned int> s;
     for (auto x : v)
     {
	  for (auto y=1u; y*y<=x; y++)
	  {
	       s.insert((x+y-1)/y);
	  }
     }

     unsigned int m_min = 1000000000;
     for (auto k : s)
     {
	  unsigned int m = k;
	  for (auto x : v)
	  {
	       m += (x+k-1)/k - 1;
	  }
	  if (m < m_min) m_min = m;
     }

     return m_min;
}

int main( int argc, char ** argv )
{
     unsigned int t;
     unsigned int i;
     string w;
     string s1,s2,s3,s4;
     string s;

     cin >> t;

     for (i=1; i<=t; i++) {
	  unsigned int n;

	  cin >> n;

	  vector<unsigned int> v(n);
	  for (auto &x : v) {
	       cin >> x;
	  }

	  unsigned int a = solve(v);

	  cout << "Case #" << i << ": ";
	  cout << a ;
	  cout << endl;
     }

     return 0;
}


//
// Qualification round 2012  problem B
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

unsigned int best( unsigned int a )
{
     return (a+2)/3;
}

unsigned int best_surprise( unsigned int a )
{
     if (a==0) return 0;
     if (a==30) return 10;
     if (a==29) return 10;

     switch (a%3)
     {
     case 0:
	  return a/3+1;
     case 1:
	  return a/3+1;
     case 2:
	  return a/3+2;
     }
     abort();
}

unsigned int solve(  unsigned int s, 
		     unsigned int p, 
		     vector<unsigned int> v )
{
     unsigned int a=0;
     unsigned int a2=0;
     unsigned int i;
     for (i=0; i<v.size(); i++)
     {
	  unsigned int b = best(v[i]);
	  unsigned int bs = best_surprise(v[i]);

	  if (b >= p) a++;
	  if (b<p && bs >= p) a2++;
     }

     if (a2 <= s) 
     {
	  a += a2;
     }
     else
     {
	  a += s;
     }
     return a;
}

int main( int argc, char ** argv )
{
     unsigned int t;
     unsigned int i,j;
     

     cin >> t;


     for (i=1; i<=t; i++) {

	  vector<unsigned int> v;
	  unsigned int n;
	  unsigned int s;
	  unsigned int p;
	  
	  unsigned int m;

	  cin >> n;
	  cin >> s;
	  cin >> p;

	  
	  for (j=0; j<n; j++)
	  {
	       unsigned int c;
	       cin >> c;
	       v.push_back(c);
	  }

	  m = solve( s, p, v );

	  cout << "Case #" << i << ": ";
	  cout << m << endl;
     }

     return 0;
}

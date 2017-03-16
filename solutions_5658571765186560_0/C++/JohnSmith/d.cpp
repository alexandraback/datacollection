//
// Qualification round 2015  problem D
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

// Return true is we can always fit the blocks in
unsigned int solve( unsigned int x, unsigned int r, unsigned int c )
{
     if (r*c % x != 0) return false;
     if (x <= 2) return true;
     if (x >= 7) return false;

     if (r > c) return solve(x,c,r);

     if (r==1) return false;

     if (r==2) {
	  if (x >= 4) return false;
	  return true;
     }

     if (r==3) {
	  if (x==3) return true;
	  if (x==4) return true;
	  if (x==5) {
	       if (c==5) return false;
	       return true;
	  }
	  if (x==6) {
	       return false;
	  }
     }

     return true;
}

int main( int argc, char ** argv )
{
     unsigned int t;
     unsigned int i;
     string s;

     cin >> t;

     for (i=1; i<=t; i++) {

	  unsigned int x, r, c;

	  cin >> x >> r >> c;

	  unsigned int a = solve(x,r,c);

	  cout << "Case #" << i << ": ";
	  cout << (a ? "GABRIEL" : "RICHARD") ;
	  cout << endl;
     }

     return 0;
}


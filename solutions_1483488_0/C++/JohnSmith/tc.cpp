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

unsigned int solve(  unsigned int a, 
		     unsigned int b ) 
{
     unsigned int da;
     unsigned int db;

     unsigned int m=1;

     unsigned int k=0;
     for (da=0,m=1; m<=a; m*=10, da++)
     {
     }

     for (db=0,m=1; m<=b; m*=10, db++)
     {
     }

     vector<unsigned int> v(da);
     unsigned int x;
     unsigned int y;
     unsigned int i,j;
     for (x=a; x<=b; x++)
     {
	  y = x;

	  v[0] = a;
	  for (i=1; i<da; i++)
	  {
	       y += (y%10)*m;
	       y = y/10;

	       v[i] = y;

	       if (x < y && y <= b)
	       {
		    for (j=1; j<i; j++)
		    {
			 if (y == v[j]) {
			      break;
			 }
		    }
		    
		    if (j==i)
		    {
			 k++;
		    }
	       }

	  }
	       
     }


     return k;
}

int main( int argc, char ** argv )
{
     unsigned int t;
     unsigned int i;
     

     cin >> t;


     for (i=1; i<=t; i++) {

	  unsigned int a;
	  unsigned int b;
	  
	  cin >> a;
	  cin >> b;

	  unsigned int m = solve( a, b );

	  cout << "Case #" << i << ": ";
	  cout << m << endl;
     }

     return 0;
}

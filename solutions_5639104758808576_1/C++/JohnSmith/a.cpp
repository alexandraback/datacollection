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

enum Result {
     x_won,
     o_won,
     draw,
     unfinished
};

int main( int argc, char ** argv )
{
     unsigned int n;
     unsigned int i;
     string w;
     string s1,s2,s3,s4;
     string s;

     cin >> n;

     for (i=1; i<=n; i++) {
	  unsigned int r;

	  cin >> r;
	  cin >> s;

	  if (r+1 != s.size()) {
	       cerr << "ERROR!!" << endl;
	       cerr << r << endl;
	       cerr << s << endl;
	       exit(1);
	  }

	  unsigned int k=0;
	  unsigned int e=0;
	  for (r=0; r<s.size(); r++)
	  {
	       if (k < r) {
		    e += r-k;
		    k = r;
	       }
	       k += s.at(r)-'0';
	  }

	  cout << "Case #" << i << ": ";
	  cout << e ;
	  cout << endl;
     }

     return 0;
}


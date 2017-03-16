//
// Qualification round 2014  problem B
//
// Usually built with g++ 4.4.5 on Linux
//
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <set>

using namespace std;

int main( int argc, char ** argv )
{
     cout << setprecision(12);
     unsigned int n;
     unsigned int i;

     cin >> n;

     for (i=1; i<=n; i++) {

	  double c, f, x;

	  cin >> c >> f >> x;

	  double t=0;
	  double v=2;
	  while ( x/v > c/v + x/(v+f))
	  {
	       t += c/v;
	       v += f;
	  }

	  t += x/v;

	  cout << "Case #" << i << ": ";
	  cout << setw(12) << t << endl;
     }

     return 0;
}


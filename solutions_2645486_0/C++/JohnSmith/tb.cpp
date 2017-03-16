//
// Round-1a 2013  problem B
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

uint64_t solve( unsigned int e,
		unsigned int r,
		vector<unsigned int> v )
{
     vector<uint64_t> w(e+1);

     for (auto& x : w) x=0;

     for (auto j=0u; j<v.size(); j++)
     {
	  vector<uint64_t> w1(e+1);
	  for (auto& x : w1) x=0;

	  for (auto i=0u; i<=e; i++)
	  {
	       for (auto u=0u; u<=e && u<=i; u++)
	       {
		    auto final = min(i-u+r, e);
		    if (0)
		    {
			 cerr << "w1.size() = "<< w1.size() << "   ";
			 cerr << "final = " << final << endl;
			 cerr<< "w.at(i) = w(" << i << ") = ";
			 cerr << w.at(i) << endl;
			 cerr << "v.at(j) = v.at(" << j << ") = " ;
			 cerr << v.at(j) << endl;
		    }
		    w1.at(final) = max( w.at(i) + v.at(j) * u, w1.at(final) );
	       }
	  }

	  w = w1;
     }

     uint64_t y=0;
     for (auto x : w)
     {
	  y = max(y,x);
     }
     return y;
}


int main( int argc, char ** argv )
{
     unsigned int nnn;
     unsigned int iii;
     string w;
     string s1,s2,s3,s4;
     char s[200];

     cin >> nnn;

     cin.getline( s, 200 );

     for (iii=1; iii<=nnn; iii++) {

	  unsigned int e,r,n;

	  cin >> e;
	  cin >> r;
	  cin >> n;

	  vector<unsigned int> v(n);
	  for (auto i=0u; i<n; i++)
	  {
	       cin >> v.at(i);
	  }

	  auto x = solve( e, r, v );

	  cout << "Case #" << iii << ": ";
	  cout << x;
	  cout << endl;
     }

     return 0;
}


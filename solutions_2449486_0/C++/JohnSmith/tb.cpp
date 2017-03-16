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

bool solve( vector< vector< unsigned int> > v )
{
     vector<unsigned int> v1(v.size());
     vector<unsigned int> v2(v.at(0).size());

     unsigned int i,j;
     for (auto &x : v1) x=0;
     for (auto &x : v2) x=0;

     for (i=0; i<v.size(); i++)
     {
	  for (j=0; j<v.at(0).size(); j++)
	  {
	       auto x = v.at(i).at(j);
	       if (x>v1.at(i)) v1.at(i) = x;
	       if (x>v2.at(j)) v2.at(j) = x;
	  }
     }

     for (i=0; i<v.size(); i++)
     {
	  for (j=0; j<v.at(0).size(); j++)
	  {
	       auto x = v.at(i).at(j);
	       if (x<v1.at(i) && x<v2.at(j)) return false;
	  }
     }

     return true;
}

int main( int argc, char ** argv )
{
     unsigned int t;
     unsigned int n,m;
     string w;
     char s[200];

     cin >> t;

     cin.getline( s, 200 );

     for (auto i=1u; i<=t; i++) {

	  cin >> n;
	  cin >> m;

	  vector<vector<unsigned int> > v;
	  v.resize(n);
	  for (auto j=0u; j<n; j++)
	  {
	       v.at(j).resize(m);
	       for (auto k=0u; k<m; k++)
	       {
		    cin >> v.at(j).at(k);
	       }
	  }

	  auto result = solve(v);

	  cout << "Case #" << i << ": ";
	  cout << (result ? "YES" : "NO") << endl;
     }

     return 0;
}


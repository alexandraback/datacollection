//
// Round-1a 2013  problem C
//
// Usually built with g++ 4.4.5 on Linux
//
#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <gmpxx.h>
#include <random>
#include <chrono>

#include <cstdlib>
#include <math.h>

using namespace std;

uint64_t power( unsigned int m, unsigned int n )
{
     uint64_t x = 1;
     while (n > 0)
     {
	  n--;
	  x *= m;
     }
     return x;
}

vector<unsigned int> verify( unsigned int n,
			     unsigned int m,
			     vector<uint64_t> v )
{
     uint64_t x;
     uint64_t p = power(m-1,n);

     vector<vector<unsigned int> > possibilities;
     for (x=0; x<p; x++)
     {
	  vector<unsigned int> c(n);
	  uint64_t xx= x;
	  bool skip=false;
	  for (auto j=0u; j<n; j++)
	  {
	       c.at(j) = (xx%(m-1))+2;
	       xx /= m-1;

	       if (j > 0 && c.at(j) < c.at(j-1)) skip = true;
	  }
	  //if (skip) continue;

	  if (0)
	  {
	       // c is a possible set of cards
	       for (auto y : c)
	       {
		    cerr << y;
	       }
	       cerr << " ";
	  }

	  uint64_t pp = power(2,m);
	  set<uint64_t> s;
	  for (auto j=0u; j<pp; j++)
	  {
	       uint64_t y=1;
	       for (auto k=0u; k<n; k++)
	       {
		    if (j&(1<<k))
		    {
			 y *= c.at(k);
		    }
	       }
	       s.insert(y);
	  }

	  if (0)
	  {
	       for (auto y : s) cerr << y << " ";
	       cerr <<endl;
	  }

	  bool plausible=true;
	  for (auto prod : v)
	  {
	       if (s.find(prod) == s.end()) plausible=false;
	  }
	  if (plausible)
	       possibilities.push_back(c);	  
     }
     
     srand(time(NULL));
     unsigned int r = rand();
     r %= possibilities.size();
     return possibilities.at(r);
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

	  unsigned int r,n,m,k;

	  cin >> r;
	  cin >> n;
	  cin >> m;
	  cin >> k;

	  cout << "Case #" << iii << ": " << endl;

	  for (auto jjj=1u; jjj<=r; jjj++)
	  {
	       vector<uint64_t> v(k);
	       for (auto j=0u; j<k; j++)
	       {
		    cin >> v.at(j);
	       }

	       auto w = verify( n, m, v );
	       
	       //cout << "Guess: ";
	       for (auto x : w) 
	       {
		    cout << x;
	       }
	       cout << endl;
	  }
     }

     return 0;
}


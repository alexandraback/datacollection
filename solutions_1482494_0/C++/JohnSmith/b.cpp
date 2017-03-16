//
// Google codejam - 2012 - Round 1a - question B
//
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <sstream>
#include <gmpxx.h>
using namespace std;
typedef long long big_int;
typedef pair<int,int> pii;
#define SZ(x) (int)(x.size())
const int inf = 1000000009;
const double pi = atan(1.0)*4.0;
const double eps = 1e-8;
big_int gcd(big_int x, big_int y) { return y ? gcd(y, x%y) : x; }
int bc(int n) { return n ? bc((n-1)&n)+1 : 0; }

mpz_class total = 0;

unsigned int n_levels;

unsigned int best_depth=0;

void try_solve( vector<pii> &v,
		unsigned int m,
		int stars,
		unsigned int depth)
{
     unsigned int i;
     if (depth < 0)
     {
	  cerr << "Size " << n_levels << " Depth " << depth ;
	  cerr << " best_depth = " << best_depth << endl;
     }

     if (depth > best_depth) return;

     if (m == (1u<<(2*n_levels))-1)
     {
	  //cerr << "Bottom - depth = " << depth << endl;
	  if (depth < best_depth)
	  {
	       best_depth = depth;
	  }
	  return;
     }

     for (i=0; i<n_levels; i++)
     {
	  unsigned int b1 = (1<<i);
	  unsigned int b2 = b1 << n_levels;

	  if ((m & b2) == 0 &&
	      stars >= v.at(i).second)
	  {
	       if (m&b1)
	       {
		    try_solve( v, m|b2, stars+1, depth+1);
		    return;
	       }
	       else
	       {
		    try_solve( v, m|b1|b2, stars+2, depth+1);
		    return;
	       }
	  }
     }				  

     for (i=0; i<n_levels; i++)
     {
	  unsigned int b = 1<<i;
	  if ((m & b) == 0 &&
	      stars >= v.at(i).first &&
	      stars < v.at(i).second)
	  {
	       //cerr << setw(3) << depth << " : Recurse - i = " << i << endl;
	       try_solve( v, m|b, stars+1, depth+1 );
	  }
     }

}

unsigned int solve( vector<pii> v )
{
     n_levels = v.size();
     best_depth = 3*n_levels;

     //cerr<< "Solve - v size " << v.size() << endl;

     try_solve( v, 0, 0, 0);

     if (best_depth > 2*n_levels) return 0;

     return best_depth;
}

int main( int argc, char ** argv )
{
     unsigned int t;
     unsigned int i,j;
     unsigned int n,a1,a2;
     string w;
     char s[200];

     cin >> t;
     cin.getline( s, 200 );

     for (i=1; i<=t; i++) {

	  cin >> n;

	  vector<pii> v;

	  for (j=0; j<n; j++)
	  {
	       cin >> a1;
	       cin >> a2;

	       v.push_back(make_pair(a1,a2));
	  }

	  unsigned int a = solve(v);

	  cout << "Case #" << i << ": ";
	  if (a == 0)
	       cout << "Too Bad" << endl;
	  else
	       cout << a << endl;

     }

     return 0;
}


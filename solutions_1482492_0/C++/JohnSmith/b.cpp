//
// Google codejam - 2012 - Round 1c - question B - John.Smith
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
typedef pair<unsigned int,unsigned int> pii;
#define SZ(x) (int)(x.size())
const int inf = 1000000009;
const double pi = atan(1.0)*4.0;
const double eps = 1e-8;
big_int gcd(big_int x, big_int y) { return y ? gcd(y, x%y) : x; }
int bc(int n) { return n ? bc((n-1)&n)+1 : 0; }

mpz_class total = 0;


double solve( double a, 
	      double d, 
	      vector<double> vt, 
	      vector<double> vx)
{
     if (0)
     {
	  if (vt.size() != 2 || vx.size() != 2)
	  {
	       cerr << "ERROR" << endl;
	       cout << "ERROR" << endl;
	       exit(1);
	  }
     }

     double oct;
     double mct = sqrt( 2.0 * d /a );

     if (vt.size() > 1)
     {
	  oct = (d - vx.at(0)) * (vt.at(1)-vt.at(0))/(vx.at(1)-vx.at(0));
	  oct += vt.at(0);
     }
     else
     {
	  oct = mct;
     }

     return max(oct,mct);
}

vector<double> solve( vector<double> va, 
		      double d, 
		      vector<double> vt, 
		      vector<double> vx)
{
     vector<double> ve;

     for (auto a : va)
     {
	  double e = solve( a, d, vt, vx );
	  ve.push_back(e);
     }
     return ve;
}

int main( int argc, char ** argv )
{
     unsigned int t;
     unsigned int i;
     string w;
     char s[200];

     cout << fixed;
     cout << setprecision(9);

     cin >> t;
     cin.getline( s, 200 );

     for (i=1; i<=t; i++) {

	  double d;
	  unsigned int n;
	  unsigned int a;
	  cin >> d >> n >> a;

	  vector<double> vt;
	  vector<double> vx;
	  vector<double> va;
	  for (auto j=0u; j<n; j++)
	  {
	       double tt, xx;
	       cin >> tt >> xx;
	       vt.push_back(tt);
	       vx.push_back(xx);
	  }

	  for (auto j=0u; j<a; j++)
	  {
	       double aa;
	       cin >> aa;
	       va.push_back(aa);
	  }
	  
	  vector<double> ve = solve(va, d, vt, vx);

	  cout << "Case #" << i << ": " << endl;

	  for (auto e : ve)
	  {
	       cout << e << endl;
	  }
     }

     cout << setw(4) ;

     return 0;
}


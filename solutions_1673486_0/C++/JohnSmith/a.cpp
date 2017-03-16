//
// Google codejam - 2012 - Round 1a - question A
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

double solve( vector<double> v, unsigned int a, unsigned int b )
{
     unsigned int i;
     vector<double> p;

     double best_e = 2*b+100;

     double x ;

     if (0)
     {
	  for (auto y : v )
	  {
	       cerr << y << " ";
	  }
	  cerr << endl;
     }

     x = 1.0;
     for (i=0; i<a; i++)
     {
	  x *= v.at(i);
	  p.push_back(x);
     }

     if (0)
     {
	  for (auto y : p )
	  {
	       cerr << y << " ";
	  }
	  cerr << endl;
     }

     for (i=0; i<a; i++)
     {
	  unsigned int n1 = b-a+1+2*i;
	  unsigned int n2 = n1 +b+1;

	  double p1 = p.at(a-i-1);
	  double p2 = 1-p1;

	  double e = p1*n1 + p2*n2 ;

	  if (e < best_e) best_e = e;

	  if (0)
	  {
	       cerr << "n1 = " << setw(3) << n1 << "  ";
	       cerr << "p1 = " << setw(7) << p1 << "  ";

	       cerr << "n2 = " << setw(3) << n2 << "  ";
	       cerr << "p3 = " << setw(7) << p2 << "  ";

	       cerr << "e = " << setw(7) << e << "     ";
	       cerr << "best_e = " << setw(7) << best_e << " ";
	       cerr << endl;
	  }
     }

     double e = 2+b;
     if (e < best_e) best_e = e ;

     return best_e;
}

unsigned int solve( unsigned int k )
{
     return k;
}

int main( int argc, char ** argv )
{
     unsigned int t;
     unsigned int i;
     unsigned int j;
     unsigned int a,b;

     string w;     
     char s[200];

     cin >> t;
     cin.getline( s, 200 );

     for (i=1; i<=t; i++) {

	  cin >> a;
	  cin >> b;

	  vector<double> v;
	  for (j=0; j<a; j++)
	  {
	       double x;
	       cin >> x;
	       v.push_back(x);
	  }

	  double y = solve( v, a, b );
	  
	  cout << "Case #" << i << ": ";
	  cout << setprecision(10);
	  cout << y << endl;
     }

     return 0;
}


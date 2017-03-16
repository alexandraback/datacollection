//
// Google codejam - 2012 - Round 1b - question A - John.Smith
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

double boundary( unsigned int sum, vector<unsigned int> v, double x )
{
     unsigned int v_sum;
     double y;
     double y_prev = -1.0;
     //cout << "boundary: v.size() = "<< v.size() << endl;
     for (auto r=1u; r<=v.size(); r++)
     {
	  v_sum = 0;
	  for (auto j=0u; j<r; j++)
	  {
	       v_sum += v.at(j);
	  }
	  
	  y = (v_sum+sum*x)/r;

	  //cout << "y = " << y << "   v_sum = " << v_sum << endl;

	  if ((y-v.at(r-1)) < 0) 
	  {
	       return y_prev;
	  }
	  y_prev= y;
     }	  
     return y_prev;
}

double solve( unsigned int sum,
	      unsigned int x,
	      vector<unsigned int> v )
{
     //cout << sum << " : ";
     //cout << x << " : ";
     
     if (0)
     {
	  for (auto y : v )
	  {
	       cout << y << " ";
	  }
	  cout << endl;
     }

     double p_lo = 0.0;
     double p_hi = 1.0;

     //double s_lo = x + p_lo * sum ;
     //double s_hi = x + p_hi * sum ;

     //double b_lo = boundary( sum,  v, 1-p_lo );
     //double b_hi = boundary( sum,  v, 1-p_hi );

     double p;

     for (auto k=0u; k<50;k++)
     {
	  p = (p_lo+p_hi)/2;
	  double s = x+p*sum;
	  double b = boundary( sum, v, 1-p);
	  
	  if (0)
	  {
	       cout << setw(10) << p_lo << " ";
	       cout << setw(10) << p_hi << " ";

	       cout << setw(10) << p << " ";
	       cout << setw(10) << s << " ";
	       cout << setw(10) << b << endl;
	  }
	  if (s<b) {
	       p_lo = p;
	  }
	  else {
	       p_hi = p;
	  }
     }

     return p;
}

vector<double> solve( vector<unsigned int> v )
{
     vector<double> r;
     unsigned int sum=0;

     for (auto s : v)
     {
	  sum += s;
     }

     for (auto i=0u; i<v.size(); i++)
     {
	  vector<unsigned int> vv;
	  for (auto j=0u; j<v.size(); j++)
	  {
	       if (j != i)
	       {
		    vv.push_back(v.at(j));
	       }


	  }
	  sort(begin(vv), end(vv));
	  r.push_back( solve( sum, v.at(i), vv ));
     }
		    
     return r;
}

int main( int argc, char ** argv )
{
     unsigned int t;
     unsigned int i;
     unsigned int k;
     string w;
     char s[200];

     cin >> t;
     cin.getline( s, 200 );

     for (i=1; i<=t; i++) {

	  cin >> k;

	  vector<unsigned int> v;
	  for (auto j=0u; j<k; j++)
	  {
	       unsigned int s;
	       cin >> s;
	       v.push_back(s);
	  }
	  
	  vector<double> r = solve(v);

	  cout << "Case #" << i << ": ";

	  cout << setprecision(10);
	  for (auto x : r)
	       cout << x*100 << " ";
	  cout << endl;

     }

     cout << setw(4) ;

     return 0;
}

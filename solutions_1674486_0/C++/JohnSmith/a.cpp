//
// Google codejam - 2012 - Round 1c - question C - John.Smith
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
vector<set<int> >*vp;
vector<unsigned int> visit;

bool search( unsigned int c, unsigned int depth )
{
     if (depth > 0)
     {
	  if(visit.at(c))
	  {
	       return true;
	  }
	  visit.at(c) = 1;
     }
     cerr << "Enter: c = " << c << endl;
     for (auto x : vp->at(c))
     {
	  cerr << "Search " << setw(2) << x << " at " << depth+1 << endl;
	  if (search( x, depth+1)) return true;
     }

     return false;
}


bool solve( vector<set<int> > v )
{
     vp = &v;
     
     for (auto i=1u; i<v.size(); i++)
     {
	  visit.resize(v.size());
	  for (auto &b : visit)
	  {
	       b = false;
	  }
	  if (search(i, 0)) return true;
	  cerr << "---" << endl;
     }
     
     return false;
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

	  unsigned int n;
	  cin >> n;

	  vector<set<int> > v(n+1);
	  for (auto j=1u; j<=n; j++)
	  {
	       unsigned int m;
	       cin >> m;

	       for (auto k=0u; k<m; k++)
	       {
		    unsigned int c;
		    cin >> c;
		    v.at(j).insert( c );
	       }
	  }

	  if (0)
	  {
	       for (auto s : v)
	       {
		    cout << s.size() << " : ";
		    for (auto c : s)
		    {
			 cout << c << " ";
		    }
		    cout << endl;
	       }
	  }


	  bool a = solve(v);

	  cout << "Case #" << i << ": ";
	  cout << (a ? "Yes" : "No") << endl;
     }

     cout << setw(4) ;

     return 0;
}


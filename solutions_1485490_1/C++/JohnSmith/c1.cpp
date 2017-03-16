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
typedef unsigned long long big_int;
typedef pair<big_int,big_int> pii;
#define SZ(x) (int)(x.size())
const int inf = 1000000009;
const double pi = atan(1.0)*4.0;
const double eps = 1e-8;
big_int gcd(big_int x, big_int y) { return y ? gcd(y, x%y) : x; }
int bc(int n) { return n ? bc((n-1)&n)+1 : 0; }

mpz_class total = 0;

struct mm
{
     unsigned int ia;
     unsigned int ib;
     big_int nia;
     big_int nib;

     mm( unsigned int ia, unsigned int ib, big_int nia, big_int nib)
	  : ia(ia), ib(ib), nia(nia), nib(nib) {}
};

bool operator<( const mm &x, const mm &y )
{
     return (( x.ia < y.ia ) ||
	     ( x.ia==y.ia && x.ib<y.ib) ||
	     ( x.ia==y.ia && x.ib==y.ib && x.nia < y.nia) ||
	     ( x.ia==y.ia && x.ib==y.ib && x.nia == y.nia && x.nib < y.nib) );
}

map<mm,big_int> memo;	     

bool contains( mm u )
{
     if (memo.find(u) == memo.end()) return false;
     return true;
}

big_int search( vector<pii> va, unsigned int ia, 
		vector<pii> vb, unsigned int ib )
{
     
     big_int nn=0;
     if (ia >= va.size() || ib >= vb.size()) return 0;

     mm u(ia, ib, va.at(ia).first, vb.at(ib).first);

     if (contains(u)) return memo.at(u);

     if (va.at(ia).second == vb.at(ib).second)
     {
	  nn = min(va.at(ia).first, vb.at(ib).first);

	  va.at(ia).first -= nn;
	  vb.at(ib).first -= nn;
	       
	  if (va.at(ia).first == 0) ia++;
	  if (vb.at(ib).first == 0) ib++;

	  nn += search(va, ia, vb, ib );	       
     }
     else
     {
	  big_int n1 = search( va, ia+1, vb, ib);
	  big_int n2 = search( va, ia, vb, ib+1);

	  nn = max(n1,n2);
     }

     memo[u] = nn;

     return nn;
}

big_int solve( vector<pii> va, vector<pii> vb )
{
     memo.clear();
     big_int ans = search( va, 0, vb, 0);
     return ans;
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

	  unsigned int n,m;
	  cin >> n >> m;

	  vector<pii> va;
	  vector<pii> vb;

	  for (auto j=0u; j<n; j++)
	  {
	       big_int a, tp;

	       cin >> a >> tp;

	       va.push_back(make_pair(a,tp));
	  }

	  for (auto j=0u; j<m; j++)
	  {
	       big_int b, tp;

	       cin >> b >> tp;

	       vb.push_back(make_pair(b,tp));
	  }

	  big_int ans = solve( va, vb);

	  cout << "Case #" << i << ": ";
	  cout << ans << endl;
     }

     cout << setw(4) ;

     return 0;
}


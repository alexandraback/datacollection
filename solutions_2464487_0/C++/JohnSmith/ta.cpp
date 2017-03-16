//
// Round-1a 2013  problem A
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
typedef mpz_class bigint;

mpz_class paint( mpz_class k, mpz_class r )
{
     bigint p;

     p= k*(2*r+1) + 2*(k-1)*(k);

     return p;
}

mpz_class find( bigint r, bigint t )
{
     bigint k = 1;
     while (paint(k,r) < t) k*=2;
     k *=2;

     bigint k0 = 1;
     bigint k1 = k;

     //cerr<< "Limits " << k0 << " to " << k1 << endl;
     while (k1-k0 > 1)
     {

	  bigint k2 = (k1+k0)/2;

	  bigint p = paint(k2,r);

	  if (p <= t)
	  {
	       k0 = k2;
	  }
	  else
	  {
	       k1 = k2;
	  }
     }
     return k0;
}

void test_paint( bigint k, bigint r )
{
     cerr << "k " << setw(6) <<k <<" ";
     cerr << "r " << setw(6) <<r <<" ";
     cerr << setw(8) << paint(k,r) << endl;
}

int main( int argc, char ** argv )
{
     unsigned int nnn;
     unsigned int iii;
     string w;
     string s1,s2,s3,s4;
     char s[200];

     if (0)
     {
	  test_paint(1,1);
	  test_paint(2,1);
	  test_paint(3,1);
     }

     cin >> nnn;

     cin.getline( s, 200 );

     for (iii=1u; iii<=nnn; iii++) {
	  bigint r;
	  bigint t;

	  cin >> r;
	  cin >> t;


	  auto x = find(r,t);
	  cout << "Case #" << iii << ": ";

	  cout << x ;
	  cout << endl;
     }

     return 0;
}


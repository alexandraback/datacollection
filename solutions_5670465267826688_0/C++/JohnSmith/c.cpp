//
// Qualification round 2015  problem C
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

enum Q {ONE, I, J, K, MONE, MI, MJ, MK } ;

bool is_neg( Q a )
{
     return (a==MONE ||
	     a==MI   ||
	     a==MJ   ||
	     a==MK);
}

Q miinus(Q a)
{
     return ( a==ONE  ? MONE :
	      a==I    ? MI   :
	      a==J    ? MJ   :
	      a==K    ? MK   :
	      a==MONE ? ONE  :
	      a==MI   ? I    :
	      a==MJ   ? J    :
	      a==MK   ? K    : ONE );
}

Q mult(Q a, Q b)
{
     if (is_neg(a)) return miinus(mult(miinus(a),b));
     if (is_neg(b)) return miinus(mult(a,miinus(b)));
     if (a==ONE) return b;
     if (b==ONE) return a;
     if (a==I && b==I) return MONE;
     if (a==I && b==J) return K;
     if (a==I && b==K) return MJ;
     if (a==J && b==I) return MK;
     if (a==J && b==J) return MONE;
     if (a==J && b==K) return I;
     if (a==K && b==I) return J;
     if (a==K && b==J) return MI;
     if (a==K && b==K) return MONE;
     cerr << "mult: error" << endl;
     return ONE;
}

Q QQ(char c )
{
     if (c=='i') return I;
     if (c=='j') return J;
     if (c=='k') return K;
     cerr << "Conversion error" << endl;
     exit(1);
     return ONE;
}

unsigned int solve( string ss )
{
     Q q=ONE;
     unsigned int t=0;
     for (auto c : ss)
     {
	  q = mult(q,QQ(c));
	  if (t==0 && q==I) { t++; q=ONE; }
	  if (t==1 && q==J) { t++; q=ONE; }
	  if (t==2 && q==K) { t++; q=ONE; }
     }
     return t==3 && q==ONE;
}

int main( int argc, char ** argv )
{
     unsigned int t;
     unsigned int i;
     string s;

     cin >> t;

     for (i=1; i<=t; i++) {
	  uint64_t l;
	  uint64_t x;

	  cin >> l >> x;

	  string s;

	  cin >> s;
	  
	  if (s.size() != l) {
	       cerr<< "Error!!";
	       exit(1);
	  }

	  string ss;
	  if (x > 16)
	  {
	       x -= (x-16)/4*4;
	  }

	  for (auto j=0u; j<x; j++) ss += s;

	  unsigned int a = solve(ss);

	  cout << "Case #" << i << ": ";
	  cout << (a ? "YES" : "NO") ;
	  cout << endl;
     }

     return 0;
}


//
// 2014 round 1b problem B
//
// John Smith
//
// Usually built with g++ 4.4.5 on Linux
//
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <set>
#include <queue>
#include <map>

using namespace std;

typedef pair<unsigned int,unsigned int> pii;

uint64_t count_ways( uint64_t a, uint64_t am,
		     uint64_t b, uint64_t bm,
		     uint64_t K )
{
     if (0)
     {
	  cerr << "Count_ways: a=" << setw(4) << a << " ";
	  cerr << "am = " << setw(4) << am << "   ";
	  cerr << "b = " << setw(4) << b << "   ";
	  cerr << "bm = " << setw(4) << bm << "   ";
	  cerr << "K = " << setw(5) << K << endl;
     }
     
     if (((a|am) & (b|bm)) < K) 
     {
	  //cerr << "Product " << (am+1)*(bm+1) << endl;
	  return (am+1)*(bm+1);
     }

     if ((a & b) >= K) {
	  //cerr << "Zero" << endl;
	  return 0;
     }

     //cerr << "Subdivide" << endl;
     if (am>bm)
     {
	  am >>= 1;
	  uint64_t c0 = count_ways( a,      am, b, bm, K);
	  uint64_t c1 = count_ways( a+am+1, am, b, bm, K);
	  //cerr << "Sum(1) " << c0+c1 << endl;
	  return c0+c1;
     }
     else
     {
	  bm >>= 1;
	  uint64_t c0 = count_ways( a, am, b, bm, K);
	  uint64_t c1 = count_ways( a, am, b+bm+1, bm, K);
	  //cerr << "Sum(2) " << c0+c1 << endl;
	  return c0+c1;
     }
}

uint64_t fast( uint64_t A, uint64_t B, uint64_t K )
{
     uint64_t a,b;
     uint64_t am,bm;

     uint64_t sa=0;
     uint64_t t=0;

     a=A;
     am = 0;
     do
     {
	  while ((a&am) == 0) am = am*2+1;
	  a &= ~am;
	  sa += 1+(am>>1);
	  //cerr << "fast a " << a << " " << (am>>1) << endl;

	  {
	       uint64_t sb=0;
	       b=B;
	       bm = 0;
	       do
	       {
		    while ((b&bm) == 0) bm = bm*2+1;
		    b &= ~bm;
		    //cerr << "fast b " << b << " " << (bm>>1) << endl;

		    sb += 1+(bm>>1);
		    
		    t += count_ways( a, am>>1,
				     b, bm>>1,
				     K );
	       }
	       while (b);
	       if (sb != B)
	       {
		    cerr << "B calculated incorrectly" << endl;
		    exit(1);
	       }
	  }

     } while (a);
     
     if (A != sa) {
	  cout << "Error" << endl;
	  exit(1);
     }
     return t;
}


uint64_t slow( unsigned int A, unsigned int B, unsigned int K )
{
     uint64_t s=0;
     unsigned int i,j;
     for (i=0; i<A; i++)
     {
	  for (j=0; j<B;j++)
	  {
	       if ((i&j) < K) s++;
	  }
     }
     return s;
}

int main( int argc, char ** argv )
{
     
     unsigned int n;
     unsigned int i;

     cin >> n;

     for (i=1; i<=n; i++) 
     {
	  unsigned int A,B,K;

	  cin >> A >> B >> K;

	  //uint64_t s0 = slow(A,B,K);
	  uint64_t s1 = fast(A,B,K);
	  
#if 0
	  if (s0 != s1)
	  {
	       cerr << "s0 = " << s0 << endl;
	       cerr << "s1 = " << s1 << endl;
	       exit(1);
	  }
#endif

	  cout << "Case #" << i << ": ";
	  cout << s1;
	  cout << endl;
     }

     return 0;
}


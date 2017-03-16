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

	  uint64_t s = slow(A,B,K);
	  
	  cout << "Case #" << i << ": ";
	  cout << s;
	  cout << endl;
     }

     return 0;
}


//
// Qualification round 2016  problem C
//
// The idea is that "11" in base b is always divisible by b+1.
//
// Usually built with g++ 4.4.5 on Linux
//
#include <iostream>

using namespace std;

int main( int argc, char ** argv )
{
     uint32_t T;
     cin >> T;

     for (auto i=1u; i<=T; i++) {

          uint32_t N, J;
          cin >> N >> J;
          
          cout << "Case #" << i << ":" << endl;
          for (auto j=0u; j<J; j++) {
               auto j1 = j;
               cout << "11";
               for (auto k=0u; k<N-4; k+=2) {
                    cout << ((j1&1) ? "11" : "00");
                    j1 >>= 1;
               }
               if (N%2 == 1) cout << "0";
               cout << "11";
               cout << " 3 4 5 6 7 8 9 10 11" << endl;
          }
     }

     return 0;
}


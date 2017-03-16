//
// Qualification round 2016  problem D
//
// Usually built with g++ 4.4.5 on Linux
//
#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <algorithm>
#include <gmpxx.h>

#include <cstdlib>
#include <math.h>

using namespace std;

int main( int argc, char ** argv )
{
     uint32_t T;

     cin >> T;

     for (auto i=1u; i<=T; i++) {

          uint32_t K, C, S;
          cin >> K >> C >> S;

          cout << "Case #" << i << ": ";
          if (S*C >= K)
          {
               vector<uint32_t> v;
               for (auto j=0u; j<K; j++)
               {
                    v.push_back(j);

                    if (v.size()== C || j == K-1)
                    {
                         uint64_t a=0;
                         for (auto x : v)
                         {
                              a *= K;
                              a += x;
                         }
                         cout << a+1 << " ";
                         v.resize(0);
                    }
               }
               cout << endl;
          }
          else
          {
               cout << "IMPOSSIBLE" << endl;
          }
     }

     return 0;
}


//
// Qualification round 2016  problem A
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

uint64_t count( uint32_t k )
{
     vector<uint32_t> m(10);
     for (auto &x : m) x=0;

     for (uint64_t r=1; r<10000; r++)
     {
          uint64_t kk = r*k;

          if (kk==0) {
               m.at(0) = 1;
          } else {
               while (kk) {
                    m.at(kk%10) = 1;
                    kk /= 10;
               }
          }

          uint32_t s=0;
          for (auto x : m)
          {
               s += x;
          }
          if (s==10) return r*k;
     }
     
     return 0;
}

int main( int argc, char ** argv )
{
     uint32_t T;

     cin >> T;

     for (auto i=1u; i<=T; i++) {

          uint32_t k;
          cin >> k;

          uint64_t a = count(k);

          cout << "Case #" << i << ": ";
          if (a==0) {
               cout << "INSOMNIA";
          } else {
               cout << a;
          }
          cout << endl;
     }

     return 0;
}


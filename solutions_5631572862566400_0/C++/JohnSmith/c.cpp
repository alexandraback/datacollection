//
// Google Codejam 2016 - Round 1a -  problem C
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

vector<uint32_t> v;


uint32_t solve( vector<uint32_t> v1)
{
     uint32_t N = v1.size();
     v=v1;

     vector<uint32_t> a(N);
     for (auto i=0u; i<N; i++) a.at(i) = i;

     uint32_t r0=2;
     //cerr << "N = " << N << endl;
     do {
          //for (auto x : a) cerr << x << " " ; cerr << endl;
          for (auto r=r0+1; r<=N; r++)
          {
               //cerr << "Loop with " << r << endl;
               bool bad = false;
               for (auto i=0u; i<r; i++)
               {
                    uint32_t k0 = i==0 ? a.at(r-1) : a.at(i-1);
                    uint32_t k1 = a.at(i);
                    uint32_t k2 = i+1 == r ? a.at(0) : a.at(i+1);
                    //cerr << k1 << " " << k2 << endl;
                    if (v.at(k1) != k0 && v.at(k1) != k2) {
                         bad = true;
                         break;
                    }
               }
               //cerr << (bad ? "bad" : "good") << endl;
               if (!bad) r0=r;
          } 
          //cerr << endl;

     } while (next_permutation(a.begin(), a.end()));

     return r0;
}

int main( int argc, char ** argv )
{
     uint32_t T;

     cin >> T;

     for (auto i=1u; i<=T; i++) {

          uint32_t k;
          cin >> k;
          vector<uint32_t> bff(k);
          for (auto &x : bff) {
               cin >> x;
               x--;
          }

          auto a = solve(bff);

          cout << "Case #" << i << ": ";
          cout << a << endl;
     }

     return 0;
}


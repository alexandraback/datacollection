//
// Google Codejam 2016 - Round 1a -  problem A
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

vector<uint32_t> solve( vector<vector<uint32_t>> a)
{
     uint32_t KK=1000000;
     uint32_t N = a.at(0).size();
     vector<uint32_t> b(N);

     vector<uint32_t> m(2*N-1);
     for (auto &x : m) x=0;

     vector<pair<uint32_t,uint32_t>> pp(N);

     uint32_t z=KK;

     for (auto i=0u; i<N; i++)
     {
          uint32_t xj=KK;
          uint32_t xj2=KK;
          uint32_t x=0;
          for (auto j=0u; j<2*N-1; j++)
          {
               if (m.at(j) == 0)
               {
                    //cerr << "xj  = " << setw(2) << xj << "  ";
                    //cerr << "xj2 = " << setw(2) << xj2 << "  ";
                    //cerr << "x   = " << setw(2) << x   << "  ";
                    //cerr << "Looking at " << a.at(j).at(i) << endl;
                    if (xj == KK)
                    {
                         xj = j;
                         xj2 = KK;
                         x = a.at(j).at(i);
                    }
                    else if (a.at(j).at(i) == x)
                    {
                         xj2 = j;
                    }
                    else if (a.at(j).at(i) < x)
                    {
                         xj = j;
                         xj2 = KK;
                         x = a.at(j).at(i);
                    }
               }
          }
          if (0) {
               cerr << setw(2) << x << " ";
               cerr << setw(2) << xj << " ";
               cerr << setw(2) << xj2 << endl;
          }

          m.at(xj) = 1;
          if (xj2 != KK) {
               m.at(xj2) = 1;
          }
          else {
               z = i;
          }
          pp.at(i) = make_pair(xj,xj2);
          //cerr << setw(2) << xj << " " << setw(2) << xj2 << endl;
     }
     //cerr << "z = " << z << endl;

     if (0) {
          for (auto i=0u; i<N; i++)
          {
               uint32_t i1 = pp.at(i).first;
               uint32_t i2 = pp.at(i).second;     
               for (auto x : a.at(i1)) cerr << setw(2) << x << " "; cerr << endl;
               if (i2 != KK)
                    for (auto x : a.at(i2)) cerr << setw(2) << x << " "; cerr << endl;
               cerr << endl;
          }
     }

     for (auto i=0u; i<N; i++)
     {
          if (i == z)
          {
               uint32_t i1 = pp.at(i).first;
               b.at(i) = a.at(i1).at(i);
          }
          else
          {
               uint32_t i0 = pp.at(z).first;
               uint32_t i1 = pp.at(i).first;
               uint32_t i2 = pp.at(i).second;     
               uint32_t v0 = a.at(i0).at(i);
               uint32_t v1 = a.at(i1).at(z);
               uint32_t v2 = a.at(i2).at(z);
               
               if (v0 == v1) 
                    b.at(i) = v2;
               else if (v0 == v2)
                    b.at(i) = v1;
               else
               {
                    cerr << "This shouldnt happen" << endl;
                    cerr << "v0 = " << v0 << " ";
                    cerr << "v1 = " << v1 << " ";
                    cerr << "v2 = " << v2 << " ";
                    cerr << endl;
               }
          }
     }

     return b;
}

int main( int argc, char ** argv )
{
     uint32_t T;

     cin >> T;

     for (auto i=1u; i<=T; i++) {

          uint32_t N;
          cin >> N;

          vector<vector<uint32_t>> a(2*N-1);
          for (auto &r : a) {
               r.resize(N);
               for (auto &x : r) cin >> x;
          }

          auto b = solve(a);

          cout << "Case #" << i << ": ";

          for (auto &x : b) cout << x << " ";
          cout << endl;
     }

     return 0;
}


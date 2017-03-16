//
// Google Codejam 2016 - Round 1b -  problem B
//
// Usually built with g++ 4.4.5 on Linux
//

#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <list>
#include <algorithm>
#include <gmpxx.h>

#include <cstdlib>
#include <math.h>

using namespace std;

uint64_t p10(uint32_t n )
{
     if (n==0) return 1;
     return 10*p10(n-1);
}

void set_string( string &a, uint64_t v )
{
     for (auto i=0u; i<a.size(); i++)
     {
          a.at(a.size()-1-i) = '0'+v%10;
          v/=10;
     }
}

vector<uint64_t> vals( string s )
{
     vector<uint64_t> v;
     uint64_t hi = p10(s.size());

     string a=s;
     for (uint64_t x=0; x<hi; x++)
     {
          set_string(a,x);
          uint32_t i;
          for (i=0; i<a.size(); i++)
          {
               if (a.at(i) == s.at(i) ||
                   s.at(i) == '?')
               {                    
               }
               else
               {
                    break;
               }
          }
          if (i == a.size())
          {
               v.push_back(x);
          }
     }
     return v;
}


void solve_slow(string s1, string s2, string &a1, string &a2)
{
     vector<uint64_t> v1 = vals(s1);
     vector<uint64_t> v2 = vals(s2);

     if (0) {
          for (auto x : v1)
          {
               cerr << x << " ";
          }
          cerr << endl;
          for (auto x : v2)
          {
               cerr << x << " ";
          }
          cerr << endl;
     }

     int64_t mx = 999999999999999999ull;

     uint32_t j1=0;
     uint32_t j2=0;

     for (auto i1=0u; i1<v1.size(); i1++)
     {
          for (auto i2=0u; i2<v2.size(); i2++)
          {
               int64_t d = v1.at(i1) - v2.at(i2);
               if (d < 0) d=-d;

               if (d < mx)
               {
                    mx=d;
                    j1 = i1;
                    j2 = i2;
               }
          }
     }

     a1 = s1;
     a2 = s2;
     set_string( a1, v1.at(j1));
     set_string( a2, v2.at(j2));
}

int main( int argc, char ** argv )
{
     uint32_t T;

     cin >> T;

     for (auto i=1u; i<=T; i++) {

          string s1, s2;
          cin >> s1 >> s2;
          
          string a1, a2;
          solve_slow(s1, s2, a1, a2);

          cout << "Case #" << i << ": ";

          cout << a1 << " " << a2;
          cout << endl;
     }

     return 0;
}

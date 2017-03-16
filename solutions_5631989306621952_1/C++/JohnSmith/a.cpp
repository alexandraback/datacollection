//
// Google Codejam 2016 - Round 1a -  problem A
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

uint32_t solve()
{
     return 0;
}

int main( int argc, char ** argv )
{
     uint32_t T;

     cin >> T;

     for (auto i=1u; i<=T; i++) {

          string s;
          cin >> s;

          list<char> a;

          for (auto c : s)
          {
               if (a.begin() == a.end() ||
                   c >= *a.begin())
               {
                    a.insert(a.begin(),c);
               }
               else
               {
                    a.insert(a.end(),c);
               }
          }

          cout << "Case #" << i << ": ";
          for (auto c : a)
          {
               cout << c;
          }

          cout << endl;
     }

     return 0;
}


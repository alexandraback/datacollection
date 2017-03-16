//
// Qualification round 2016  problem B
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

uint32_t count(string s)
{
     unsigned int n=0;
     while (1)
     {
          char c='+';
          for (auto cc : s) 
          {
               c = cc;
               if (c != '+') break;
          }
          if (c=='+') return n;

          c = *s.begin();
          char c2 = (c=='+' ? '-': '+');

          for (auto p=s.begin(); p!=s.end(); p++)
          {
               if (*p != c) break;
               *p = c2;
          }

          n++;
     }
}

int main( int argc, char ** argv )
{
     uint32_t T;

     cin >> T;

     for (auto i=1u; i<=T; i++) {
          string p;
          cin >> p;

          cout << "Case #" << i << ": ";
          cout << count(p) << endl;
     }

     return 0;
}


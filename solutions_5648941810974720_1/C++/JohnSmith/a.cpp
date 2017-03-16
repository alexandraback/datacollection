//
// Google Codejam 2016 - Round 1b -  problem A
//
// Usually built with g++ 4.4.5 on Linux
//

#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <algorithm>
#include <gmpxx.h>

#include <cstdlib>
#include <math.h>

using namespace std;

const char* names[] = {
     "ZERO",
     "ONE",
     "TWO",
     "THREE",
     "FOUR",
     "FIVE",
     "SIX",
     "SEVEN",
     "EIGHT",
     "NINE",
     0
};

const uint32_t select_order[] = {
     0, 2, 4, 5, 6, 7, 8, 9, 1, 3
};
const char select_letter[] = {
     'Z',
     'W',
     'U',
     'F',
     'X',
     'S',
     'G',
     'I',
     'O',
     'T'
};


map<char,uint32_t> table;

void init()
{
     for (const char **p =names; *p; p++)
     {
          for (const char *q=*p; *q; q++)
          {
               table[*q]++;
          }
     }
     
     for (const char **p =names; *p; p++)
     {
          for (const char *q=*p; *q; q++)
          {
               cerr << *q << " " << setw(2) << table[*q] << " ";
          }
          cerr << endl;
     }

     vector<uint32_t> tick(10,0);
     bool looping = true;
     while (looping)
     {
          looping = false;
          uint32_t i=0;
          for (const char **p =names; *p; p++,i++)
          {
               if (tick.at(i) == 0)
               {
                    for (const char *q=*p; *q; q++)
                    {
                         if (table[*q] == 1)
                         {
                              cerr << *q << " ";
                              cerr << *p << endl;
                              for (const char *qq=*p; *qq; qq++)
                              {
                                   table[*qq]--;
                              }
                              tick.at(i) = 1;
                              looping = true;
                              break;
                         }
                    }
               }
          }
     }

     cerr << endl;
     uint32_t i=0;
     for (const char **p =names; *p; p++,i++)
     {
          if (tick.at(i) == 0) {
               for (const char *q=*p; *q; q++)
               {
                    cerr << *q << " " << setw(2) << table[*q] << " ";
               }
               cerr << endl;
          }
     }

}

uint32_t solve()
{
     return 0;
}

int main( int argc, char ** argv )
{
     //init();

     uint32_t T;

     cin >> T;

     for (auto i=1u; i<=T; i++) {

          string s;
          cin >> s;
          //cout << s << endl;

          map<char,uint32_t> m;
          for (auto c : s) m[c]++;

          vector<uint32_t> a(10,0);

          for (auto j=0; j<10; j++)
          {
               uint32_t r = m[select_letter[j]];
               a.at(select_order[j]) = r;
               for (const char *p=names[select_order[j]]; *p; p++)
               {
                    m[*p]-=r;
               }
          }

          for (auto p : m) {
               if (p.second != 0) {
                    cerr << "ERROR!!!" << endl;
               }
          }
          
          cout << "Case #" << i << ": ";

          for (auto j=0; j<10; j++)
          {
               for (auto k=0u; k<a.at(j); k++)
               {
                    cout << j;
               }
          }
          cout << endl;
          
     }

     return 0;
}


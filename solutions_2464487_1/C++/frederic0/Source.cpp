#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <cassert>
#include <complex>
#include <climits>
#include <functional>

#include "LargeNumber.h"

using namespace std;

typedef unsigned int uint;
typedef long long LL;
typedef long double LD;

#define fabsl __builtin_fabsl
#define atan2l __builtin_atan2l
#define cosl __builtin_cosl
#define sinl __builtin_sinl
#define sqrtl __builtin_sqrtl

int main(int argc, char **argv)
{
   int testcases = 0, cont;

   
   string tt, rr;
   CLargeNumber t, r;
   cin >> testcases;

   // t mililitros
   // r first white circle
   // 1 t cobre 1 PI cm^2 

   for (int caso = 1; caso <= testcases; ++caso)
   {
      cin >> rr >> tt;
      cont = 0;
      t = CLargeNumber(tt);
      r = CLargeNumber(rr);

      CLargeNumber first = (r+CLargeNumber(1))*(r+CLargeNumber(1))-(r*r);

      CLargeNumber cont = 1;
      CLargeNumber dir = first;
      
      while (cont * dir < t) {
         cont += 100000;
         dir += 200000;
      }
      while (cont * dir > t) {
         cont -= 100;
         dir -= 200;
      }
      while (cont * dir <= t) {
         cont += 1;
         dir += 2;
      }
      cont-= 1;

      cout << "Case #" << caso << ": " << cont <<  endl;  
   }

}
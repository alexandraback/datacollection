/*
 * Tibor Mezei (zemei)
 * Google Code Jam 2014
 * Standard: C++11 with GCC-4.8.2
*/

#include <deque>
#include <list>
#include <tuple>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

#include <algorithm>
#include <complex>
#include <iostream>
#include <fstream>
#include <ios>
#include <iomanip>
#include <regex>
#include <string>

#include <cctype>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;


// Prime number tester
bool isPrime(uint64_t x)
{
  if (x<2) return false;
  for (uint64_t i=2; i*i<=x; ++i)
    if (x%i==0) return false;
  return true;
}

uint64_t gcd (uint64_t a, uint64_t b)
{
    uint64_t c;
    while ( a != 0 ) {
        c = a; a = b%a;  b = c;
    }
    return b;
}


int main(int argc, char **argv)
{

  ifstream fi;		// input file
  ofstream fo;		// output file
  int numCases;	    // number of cases

  if (argc!=2) { 
    printf("No input!\n"); 
    return -1; 
  }

  fi.open(argv[1]);
  fo.open("output.txt");


  fi >> numCases;

  const uint64_t max = 1ull << 40;

  for (int cases=1; cases<=numCases; ++cases) {
    // -----------------------------------------------------------------------------
    uint64_t P, Q;
    uint64_t result;
    char c;
    fi >> P >> c >> Q;
    bool impossible = false;

    uint64_t lnko = gcd(P, Q);
    if (lnko != 0) {
        P /= lnko;
        Q /= lnko;
    }
    
    if (max % Q == 0) {
        uint64_t div = max / Q;
        P *= div;
        for (int i = 39; i > 0; --i) {
            if (P >= (1ull << i)) {
                result = 40 - i;
                break;
            }
        }
    } else {
        impossible = true;
    }


    // ------------------------------------------------------------------------------
    fo << "Case #" << cases << ": ";
    if (impossible)
    fo << "impossible";
    else
    fo << result;
    fo << endl;
  }

  fi.close();
  fo.close();
  return 0;
}



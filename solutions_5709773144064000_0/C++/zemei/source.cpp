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
#include <ios>
#include <iomanip>
#include <fstream>
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
bool isPrime(uint64_t x) {
  if (x<2) return false;
  for (uint64_t i=2; i*i<=x; ++i)
    if (x%i==0) return false;
  return true;
}


int main(int argc, char **argv) {

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

  for (int cases=1; cases<=numCases; ++cases) {
    // -----------------------------------------------------------------------------
    double C, F, X;
    fi >> C >> F >> X;
    double T = 1000000000;
    for (int i = 0; i < (int)(X/C) + 1; ++i) {
        double p = 2.0;
        double t = 0.0;
        for (int f = 0; f < i; ++f) {
            t += C/p;
            p += F;
        }
        t += X/p;
        if (t < T)
            T = t;
    }
    // ------------------------------------------------------------------------------
    fo << "Case #" << cases << ": ";
    fo << fixed << setprecision(7) << T;
    fo << endl;
  }

  fi.close();
  fo.close();
  return 0;
}



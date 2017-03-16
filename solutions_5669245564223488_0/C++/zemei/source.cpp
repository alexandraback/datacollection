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
    int C;
    fi >> C;
    vector<string> t(C);
    vector<int> index(C);
    for (int i = 0; i < C; ++i) {
        fi >> t[i];
        index[i] = i;
    }
    uint64_t result = 0;
    
    do {
        vector<int> c(255);
        string all;
        for (int i = 0; i < C; ++i) {
            all += t[index[i]];
        }
        auto it = unique(all.begin(), all.end());
        all.resize(distance(all.begin(), it));
        for (unsigned i = 0; i < all.length(); ++i) {
            c[all[i]]++;
        }
        result += (all_of(c.begin(), c.end(), [](int q){ return q < 2; }) ? 1 : 0);
    } while (next_permutation(index.begin(), index.end()));

    // ------------------------------------------------------------------------------
    fo << "Case #" << cases << ": ";
    fo << (result % 1000000007);
    fo << endl;
  }

  fi.close();
  fo.close();
  return 0;
}



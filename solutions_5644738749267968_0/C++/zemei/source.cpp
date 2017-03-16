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
    int N;
    fi >> N;
    vector<double> n(N);
    for (int i = 0; i < N; ++i)
        fi >> n[i];
    vector<double> k(N);
    for (int i = 0; i < N; ++i)
        fi >> k[i];

    sort(n.begin(), n.end());
    sort(k.begin(), k.end());

    int w = 0;
    vector<double> dk(k);
    for (int i = N - 1; i >= 0; --i) {
        auto it = lower_bound(dk.begin(), dk.end(), n[i]);
        if (it == dk.end()) {
            ++w;
            dk.erase(dk.begin());
        } else {
            dk.erase(it);
        }
    }

    int dw = 0;
    vector<double> dwk(k);
    for (int i = N - 1; i >= 0; --i) {
        auto it = upper_bound(dwk.begin(), dwk.end(), n[i]);
        if (it != dwk.begin()) {
            int pos = it - dwk.begin() - 1;
            ++dw;
            dwk.erase(dwk.begin() + pos);
        }
    }


    // ------------------------------------------------------------------------------
    fo << "Case #" << cases << ": ";
    fo << dw << " " << w;  // TODO
    fo << endl;
  }

  fi.close();
  fo.close();
  return 0;
}



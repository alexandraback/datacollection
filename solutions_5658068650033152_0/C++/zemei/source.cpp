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


int calc(int X, int Y, int K) {
    if (K < 5) return K;

    if (X < 3 || Y < 3) return K;

    int min = X * Y;
    for (int i = 1; i < X - 1; ++i) {
        for (int j = 1; j < Y - 1; ++j) {
            int num = i * j + 2*i + 2 *j;
            if (num <= K) {
            int count = 2 * i + 2 * j;
            count += (K - count - i*j);
            if (count < min)
                min = count;
            }
        }
    }

    return min; 
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
    int X, Y, K;
    fi >> X >> Y >> K;
    // ------------------------------------------------------------------------------
    fo << "Case #" << cases << ": ";
    fo << calc(X, Y, K);
    fo << endl;
  }

  for (int X = 1; X < 6; ++X) {
      for (int Y = 1; Y < 6; ++Y) {
          for (int K = 1; K <= X*Y; ++K) {
              cout << X << " " << Y << " " << K << ": " << calc(X, Y, K) << endl;
          }
      }
  }

  fi.close();
  fo.close();
  return 0;
}



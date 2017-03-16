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

void print(vector<char>& t, int R, int C)
{
    cout << R << " " << C << endl;
    for (int i = 0; i < R * C; ++i) {
        cout << t[i];
        if ((i+1)%C==0)
            cout << endl;
    }
}

list<int> neigh(vector<char>& t, int R, int C, int p) 
{
    int x = p % C;
    int y = p / C;
    list<int> a;
    for (int i = -1; i < 2; ++i) {
        for (int j = -1; j < 2; ++j) {
            if (x+i>=0 && x+i<C && y+j>=0 && y+j<R) {
                int np = (y+j)*C + x+i;
                if (t[np] == '*')
                    a.push_back(np);
            }
        }
    }
    return a;
}

int needed;

bool step(vector<char>& t, int R, int C, int count, bool first = false)
{
    bool found = false;
    for (int i = 0; i < R*C; ++i) {
        if (t[i] == '.' || (t[i] == 'c' && first)) {
            auto list = neigh(t, R, C, i);
            if (!list.empty() && count + list.size() <= needed) {
                for (int p : list)
                    t[p] = '.';
                //print(t, R, C);
                if (count + list.size() == needed)
                    return true;
                found = step(t, R, C, count + list.size());
                if (found)
                    break;
                for (int p : list)
                    t[p] = '*';
            }
        }
    }
    return found;
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
    int R, C, M;
    fi >> R >> C >> M;
    vector<char> t(R*C, '*');

    bool found = false;
    needed = R * C - M;
    if (needed > 0) {
    for (int c = 0; c < R*C; ++c) {
        t[c] = 'c';
        if (needed == 1) {
            found = true;
            break;
        }
            
        found = step(t, R, C, 1, true);
        if (found)
            break;
        t[c] = '*';
    }
    }

    // ------------------------------------------------------------------------------
    fo << "Case #" << cases << ":" << endl;
    if (found) {
        for (int i = 0; i < R*C; ++i) {
            fo << t[i];
            if ((i+1)%C==0)
                fo << endl;
        }
    } else {
        fo << "Impossible" << endl;
    }
  }

  fi.close();
  fo.close();
  return 0;
}



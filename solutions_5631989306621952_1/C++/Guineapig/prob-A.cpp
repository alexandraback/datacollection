#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <numeric>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <limits>
using namespace std;

// #pragma warning(disable: 4018)
// #include "../my_header.h"


struct solver
{
  string solve(string &S, int n)
  {
    assert(n > 0);

    char last_letter = 'A';
    int pos = -1;
    for (int i=0 ; i < n ; i++)
    {
      char letter = S[i];
      if (letter > last_letter)
      {
        last_letter = letter;
        pos = i;
      }
    }

    string res;
    for (int i=0 ; i < n ; i++)
      if (S[i] == last_letter)
        res += last_letter;

    if (pos > 0)
      res += solve(S, pos);

    for (int i=pos+1 ; i < n ; i++)
    {
      char letter = S[i];
      if (letter != last_letter)
        res += letter;
    }

    return res;
  }
};

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void process_test_case(int case_num, ifstream &ifs, ofstream &ofs)
{
  string S;
  ifs >> S;

  string res = solver().solve(S, S.size());

  cout << "Case #" << case_num << ": " << res << endl;
  ofs << "Case #" << case_num << ": " << res << endl;
}

////////////////////////////////////////////////////////////////////////////////

int main(int argc, char **argv)
{
  if (argc != 3) {
    cout << "Usage: runme <input file> <output file>" << endl;
    return 1;
  }

  ifstream ifs(argv[1], ifstream::in);
  ofstream ofs(argv[2]);

  ofs.precision(8);
  ofs << fixed;

  int T;
  ifs >> T;
  // assert(T > 0 && T < 200);

  for (int i=0 ; i < T ; i++)
  {
    // if (i > 0)
    //  cout << "\n---------------------------------------------\n\n";
    process_test_case(i+1, ifs, ofs);
  }

  return 0;
}

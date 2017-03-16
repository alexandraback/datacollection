
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
  vector<int> solve(int N, int nl, vector<vector<int> > &lists)
  {
    vector<int> counters(2501);
    for (int i=0 ; i < counters.size() ; i++)
      counters[i] = 0;

    for (int i=0 ; i < lists.size() ; i++)
    {
      vector<int> &list = lists[i];
      for (int j=0 ; j < list.size() ; j++)
      {
        int h = list[j];
        assert(h < counters.size());
        counters[h]++;
      }
    }

    vector<int> res;
    for (int h=1 ; h < counters.size() ; h++)
    {
      int count = counters[h];
      if (count % 2 == 1)
        res.push_back(h);
    }

    assert(res.size() == N);

    return res;
  }
};

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void process_test_case(int case_num, ifstream &ifs, ofstream &ofs)
{
  int N;
  ifs >> N;

  int nl = 2 * N - 1;

  vector<vector<int> > lists(nl);
  for (int i=0 ; i < nl ; i++)
    for (int j=0 ; j < N ; j++)
    {
      int v;
      ifs >> v;
      lists[i].push_back(v);
    }

  vector<int> res = solver().solve(N, nl, lists);

  // cout << "Case #" << case_num << ": " << res << endl;
  ofs << "Case #" << case_num << ":";
  for (int i=0 ; i < res.size() ; i++)
    ofs << " " << res[i];
  ofs << endl;
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

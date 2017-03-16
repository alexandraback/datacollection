
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
  vector<int> reachable_from(int start, bool reachable[6], int B, bool cm[6][6])
  {
    for (int i=0 ; i < 6 ; i++)
      reachable[i] = false;

    vector<int> curr_round;
    curr_round.push_back(start);
    while (curr_round.size() != 0)
    {
      vector<int> next_round;
      for (int i=0 ; i < curr_round.size() ; i++)
      {
        int c = curr_round[i];
        for (int j=0 ; j < B ; j++)
          if (cm[c][j])
          {
            if (!reachable[j])
            {
              reachable[j] = true;
              next_round.push_back(j);
            }
          }
      }
      curr_round = next_round;
    }

    vector<int> res;
    for (int i=0 ; i < B ; i++)
      if (reachable[i])
        res.push_back(i);
    return res;
  }


  bool has_loops(int B, bool cm[6][6])
  {
    for (int i=0 ; i < B-1 ; i++)
    {
      bool reachable[6];
      reachable_from(i, reachable, B, cm);
      if (reachable[i])
        return true;
    }
    return false;
  }


  int count_ways(int B, bool cm[6][6])
  {
    int ways_to_B = 0;

    vector<int> ways(B);
    ways[0] = 1;
    for (int i=1 ; i < B ; i++)
      ways[i] = 0;

    for ( ; ; )
    {
      bool is_all_zeros = true;

      vector<int> new_ways(B);
      for (int i=0 ; i < B ; i++)
        new_ways[i] = 0;

      for (int i=0 ; i < B ; i++)
        if (ways[i] != 0)
          for (int j=0 ; j < B ; j++)
            if (cm[i][j])
            {
              new_ways[j] += ways[i];
              is_all_zeros = false;
            }

      ways_to_B += new_ways[B-1];

      if (is_all_zeros)
        return ways_to_B;

      ways = new_ways;
    }
  }


  vector<string> solve(int B, int M)
  {
    int n_bits = (B - 1) * (B - 1);
    for (int m=0 ; m < (1 << n_bits) ; m++)
    {
      bool cm[6][6];
      for (int i=0 ; i < B ; i++)
        for (int j=0 ; j < B ; j++)
        {
          if (i == B-1 || i == j)
            cm[i][j] = 0;
          else
          {
            int shift = i * (B - 1) + j;
            if (i < j)
              shift--;
            cm[i][j] = (m & (1 << shift)) != 0;
          }
        }

      bool has_rev = false;
      for (int i=0 ; i < B ; i++)
        for (int j=0 ; j < i ; j++)
          if (cm[i][j] && cm[j][i])
          {
            has_rev = true;
            break;
          }

      if (!has_rev && !has_loops(B, cm))
        if (count_ways(B, cm) == M)
        {
          vector<string> res;
          res.push_back("POSSIBLE");

          for (int i=0 ; i < B ; i++)
          {
            string line;
            for (int j=0 ; j < B ; j++)
              line += cm[i][j] ? '1' : '0';
            res.push_back(line);
          }

          return res;
        }
    }

    vector<string> bad_res;
    bad_res.push_back("IMPOSSIBLE");
    return bad_res;
  }
};

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void process_test_case(int case_num)
{
  int B, M;
  cin >> B >> M;

  solver a_solver;

  vector<string> res = a_solver.solve(B, M);

  cout << "Case #" << case_num << ": ";
  for (int i=0 ; i < res.size() ; i++)
    cout << res[i] << endl;
}

////////////////////////////////////////////////////////////////////////////////

int main(int argc, char **argv)
{
  cout.precision(8);
  cout << fixed;

  int T;
  cin >> T;
  // assert(T > 0 && T < 200);

  for (int i=0 ; i < T ; i++)
  {
    // if (i > 0)
    //  cout << "\n---------------------------------------------\n\n";
    process_test_case(i+1);
  }

  return 0;
}

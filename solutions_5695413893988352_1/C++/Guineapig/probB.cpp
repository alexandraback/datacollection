
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


enum STATUS {undecided, c_bigger, j_bigger};


unsigned long long abs_diff(unsigned long long x, unsigned long long y)
{
  if (x > y)
    return x - y;
  else
    return y - x;
}


struct solver
{
  string C;
  string J;

  bool init;

  unsigned long long best_c_score;
  unsigned long long best_j_score;

  string best_C;
  string best_J;

  void solve_rec(int idx, STATUS status)
  {
    int len = C.length();

    if (idx == len)
    {
      unsigned long long c_score = 0;
      unsigned long long j_score = 0;

      for (int i=0 ; i < len ; i++)
      {
        c_score = 10 * c_score + (C[i] - '0');
        j_score = 10 * j_score + (J[i] - '0');
      }

      if (!init)
      {
        best_c_score = c_score;
        best_j_score = j_score;
        best_C = C;
        best_J = J;
        init = true;
        return;
      }

      unsigned long long best_diff = abs_diff(best_c_score, best_j_score);
      unsigned long long curr_diff = abs_diff(c_score, j_score);

      if (best_diff != curr_diff)
      {
        if (curr_diff < best_diff)
        {
          best_c_score = c_score;
          best_j_score = j_score;
          best_C = C;
          best_J = J;
        }
      }

      else if (best_c_score != c_score)
      {
        if (c_score < best_c_score)
        {
          best_c_score = c_score;
          best_j_score = j_score;
          best_C = C;
          best_J = J;
        }
      }

      else if (j_score < best_j_score)
      {
        best_c_score = c_score;
        best_j_score = j_score;
        best_C = C;
        best_J = J;
      }

      return;
    }

    int ch_c = C[idx];
    int ch_j = J[idx];

    int next_idx = idx + 1;


    if (status == c_bigger)
    {
      if (ch_c == '?')
        C[idx] = '0';
      if (ch_j == '?')
        J[idx] = '9';
      solve_rec(next_idx, status);
      C[idx] = ch_c;
      J[idx] = ch_j;
    }
    else if (status == j_bigger)
    {
      if (ch_c == '?')
        C[idx] = '9';
      if (ch_j == '?')
        J[idx] = '0';
      solve_rec(next_idx, status);
    }
    else
    {
      if (ch_c == '?')
        if (ch_j == '?')
        {
          if (next_idx < len && C[next_idx] == J[next_idx])
          {
            C[idx] = '0';
            J[idx] = '0';
            solve_rec(next_idx, undecided);
          }
          else
          {
            C[idx] = '0';
            J[idx] = '0';
            solve_rec(next_idx, undecided);

            C[idx] = '1';
            J[idx] = '0';
            solve_rec(next_idx, c_bigger);

            C[idx] = '0';
            J[idx] = '1';
            solve_rec(next_idx, j_bigger);
          }
        }
        else
        {
          C[idx] = ch_j;
          solve_rec(next_idx, undecided);

          if (ch_j > '0')
          {
            C[idx] = ch_j - 1;
            solve_rec(next_idx, j_bigger);
          }

          if (ch_j < '9')
          {
            C[idx] = ch_j + 1;
            solve_rec(next_idx, c_bigger);
          }
        }
      else
        if (ch_j == '?')
        {
          J[idx] = ch_c;
          solve_rec(next_idx, undecided);

          if (ch_c > '0')
          {
            J[idx] = ch_c - 1;
            solve_rec(next_idx, c_bigger);
          }

          if (ch_c < '9')
          {
            J[idx] = ch_c + 1;
            solve_rec(next_idx, j_bigger);
          }
        }
        else
        {
          STATUS new_status = ch_c == ch_j ? undecided : (ch_c > ch_j ? c_bigger : j_bigger);
          solve_rec(idx + 1, new_status);
        }
    }

    C[idx] = ch_c;
    J[idx] = ch_j;    
  }


  string solve()
  {
    init = false;
    solve_rec(0, undecided);
    return best_C + " " + best_J;
  }
};

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void process_test_case(int case_num)
{
  solver s;
  cin >> s.C >> s.J;

  string res = s.solve();

  cout << "Case #" << case_num << ": " << res << endl;
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


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

const char *digit_names[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

struct solver
{
  int digits_needed[10][26];

  solver()
  {
    for (int i=0 ; i < 10 ; i++)
      for (int j=0 ; j < 26 ; j++)
        digits_needed[i][j] = 0;

    for (int i=0 ; i < 10 ; i++)
    {
      const char *name = digit_names[i];
      int name_len = strlen(name);
      for (int j=0 ; j < name_len ; j++)
      {
        int ch_idx = name[j] - 'A';
        digits_needed[i][ch_idx]++;
      }
    }
  }


  bool solve_rec(int counters[26], int digit_counts[10], int d)
  {
    const char *name = digit_names[d];
    int name_len = strlen(name);

    int max_num = 1000000;
    for (int i=0 ; i < 26 ; i++)
    {
      int needed = digits_needed[d][i];
      if (needed > 0)
      {
        int count = counters[i] / needed;
        if (count < max_num)
          max_num = count;
      }
    }

    assert(max_num >= 0);

    for (int num=max_num ; num >= 0 ; num--)
    {
      int counters_copy[26];
      for (int i=0 ; i < 26 ; i++)
      {
        counters_copy[i] = counters[i] - num * digits_needed[d][i];
        assert(counters_copy[i] >= 0);
      }

      if (d == 9)
      {
        for (int j=0 ; j < 26 ; j++)
          if (counters_copy[j] != 0)
            return false;        
        digit_counts[d] = num;
        return true;
      }

      if (solve_rec(counters_copy, digit_counts, d+1))
      {
        digit_counts[d] = num;
        return true;
      }
    }

    return false;
  }

  string solve(string S)
  {
    int counters[26];
    for (int i=0 ; i < 26 ; i++)
      counters[i] = 0;

    for (int i=0 ; i < S.length() ; i++)
    {
      char ch = S[i];
      counters[ch - 'A']++;
    }

    int digit_counts[10];
    for (int i=0 ; i < 10 ; i++)
      digit_counts[i] = 0;

    bool success = solve_rec(counters, digit_counts, 0);
    assert(success);

    string res;
    for (int i=0 ; i < 10 ; i++)
    {
      for (int j=0 ; j < digit_counts[i] ; j++)
        res += '0' + i;
    }

    return res;
  }
};

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void process_test_case(int case_num)
{
  string S;
  cin >> S;

  solver s;
  string res = s.solve(S);

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

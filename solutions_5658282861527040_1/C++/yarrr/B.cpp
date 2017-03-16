#include <iostream>
#include <cstdio>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <stdint.h>

#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cstring>
#include <bitset>
#include <deque>
#include <list>
#include <stack>

using namespace std;

typedef long long ll;

#define mp make_pair
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define foreach(it, v) for(__typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define sz(v) int((v).size())

ll solve_dumb(ll first_border, ll second_border, ll and_border)
{
  ll result = 0;
  for(ll i = 0; i < first_border; i++)
    for(ll j = 0; j < second_border; j++)
      if((i & j) < and_border)
        ++result;
  return result;
}

const int total_bits = 32, total_flags = 3;
const int EQUAL = 0, LESSER = 1, GREATER = 2;

ll ways[total_bits + 1][total_flags][total_flags][total_flags];

ll get_bit(ll number, ll id)
{
  return ((number >> id) & 1);
}

int get_flag(ll number, ll id, int flag, ll bit)
{
  ll number_bit = get_bit(number, id);
  ll other_bit = bit;
  if(number_bit == other_bit)
  {
    return flag;
  }
  else
  {
    if(number_bit < other_bit)
      return GREATER;
    else if(number_bit > other_bit)
      return LESSER;
    else
      assert(false);
  }
}

ll  solve_smart(ll first_border, ll second_border, ll and_border)
{
  memset(ways, 0, sizeof(ways));
  ways[0][EQUAL][EQUAL][EQUAL] = 1;
  for(int bit = 0; bit < total_bits; bit++)
  {
    for(int first_flag = 0; first_flag < total_flags; first_flag++)
    {
      for(int second_flag = 0; second_flag < total_flags; second_flag++)
      {
        for(int and_flag = 0; and_flag < total_flags; and_flag++)
        {
          ll current = ways[bit][first_flag][second_flag][and_flag];
          if(current > 0)
          {
            for(int first_bit = 0; first_bit <= 1; first_bit++)
            {
              for(int second_bit = 0; second_bit <= 1; second_bit++)
              {
                int and_bit = (first_bit & second_bit);
                int new_first_flag = get_flag(first_border, bit, first_flag, first_bit);
                int new_second_flag = get_flag(second_border, bit, second_flag, second_bit);
                int new_and_flag = get_flag(and_border, bit, and_flag, and_bit);
                /*if(new_first_flag == LESSER && new_second_flag == LESSER && new_and_flag == LESSER)
                {
                  cerr << "JUMP" << endl;
                  cerr << bit << " " << first_flag << " " << second_flag << " " << and_flag
                       << " " << current << endl;
                  cerr << first_bit << " " << second_bit << " " << and_bit << endl;
                }*/
                ways[bit + 1][new_first_flag][new_second_flag][new_and_flag] += current;
              }
            }
          }
        }
      }
    }
  }
  return ways[total_bits][LESSER][LESSER][LESSER];
}

void solve()
{
  ll first_border, second_border, and_border;
  cin >> first_border >> second_border >> and_border;
  cout << solve_smart(first_border, second_border, and_border);
}

int main()
{
  int tests;
  cin >> tests;
  for(int test = 1; test <= tests; test++)
  {
    cout << "Case #" << test << ": ";
    solve();
    cout << endl;
  }
  return 0;
}
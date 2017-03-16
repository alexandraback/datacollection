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

void solve()
{
  ll first_border, second_border, and_border;
  cin >> first_border >> second_border >> and_border;
  cout << solve_dumb(first_border, second_border, and_border);
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
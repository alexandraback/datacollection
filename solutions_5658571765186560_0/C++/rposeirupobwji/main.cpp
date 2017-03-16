#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <iterator>
#include <ctime>
#include <iomanip>

typedef unsigned int uint32;
typedef signed long long int64;
typedef unsigned long long uint64;

using namespace std;

#define ALL(a) a.begin(), a.end()
#define FOR(a) for (int i = 0; i < (a); ++i)
#define D(a) #a << ": " << a << "\n"

#define NO "RICHARD"
#define YES "GABRIEL"

string solve(int x, int small, int large)
{
  if ((small * large) % x)
    return NO;

  if (x >= 7)
    return NO;

  //cout << x << " " << small << " " << large << endl;
  if ((x+1) / 2 > small)
    return NO;

  if (small + large - 1 < x)
    return NO;

  if (small + large - 1 == x && small > 1)
    return NO;

  if (x >= small + 2)
    return NO;

  return YES;
}

int main()
{
  int CASES = 100;
  cin >> CASES;
  for (int CASE = 1; CASE <= CASES; ++CASE)
  {
    int x, r, c;
    cin >> x >> r >> c;
    /*for (int x = 1; x <= 4; ++x)
      for (int r = 1; r <= 4; ++r)
        for (int c = r; c <= 4; ++c)
        {
          string s = solve(x, min(r, c), max(r, c));
          cout << s << endl;
        }*/


    printf("Case #%d: %s\n", CASE, solve(x, min(r, c), max(r, c)).c_str());
  }

  return 0;
}

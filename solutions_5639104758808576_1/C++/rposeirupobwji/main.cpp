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

int main()
{
  int CASES;
  cin >> CASES;
  for (int CASE = 1; CASE <= CASES; ++CASE)
  {
    int a;
    string s;
    cin >> a >> s;
    int res = 0;
    int have = 0;
    for (int i = 0; i < s.size(); ++i)
    {
      if (have < i)
      {
        res += i - have;
        have = i;
      }

      have += s[i] - '0';
    }

    printf("Case #%d: %d\n", CASE, res);
  }

  return 0;
}

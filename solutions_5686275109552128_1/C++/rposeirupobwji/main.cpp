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

multiset<int, greater<int> > s;

int calc(int one)
{
  int res = one;
  for (int a : s)
  {
    if (a <= one)
      break;

    res += ceil(1.0 * a / one) - 1;
  }
  
  return res;
}

int main()
{
  int CASES = 100;
  cin >> CASES;
  for (int CASE = 1; CASE <= CASES; ++CASE)
  {
    int d;
    cin >> d;
    s.clear();
    FOR(d)
    {
      int a;
      scanf("%d", &a);
      s.insert(a);
    }

    int res = *s.begin();
    for (int i = *s.begin(); i > 0; --i)
      res = min(res, calc(i));

    printf("Case #%d: %d\n", CASE, res);
  }

  return 0;
}

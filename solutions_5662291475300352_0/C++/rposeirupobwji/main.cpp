#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
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
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <iterator>
#include <ctime>
#include <iomanip>
#include <stdint.h>

typedef unsigned int uint32;
typedef signed long long int64;
typedef unsigned long long uint64;

using namespace std;

#define ALL(a) a.begin(), a.end()
#define FOR(a) for (int i = 0; i < a; ++i)
#define D(a) #a << ": " << a << "\n"

int main()
{
  int CASES = 100000;
  cin >> CASES;
  for (int CASE = 1; CASE <= CASES; ++CASE)
  {
    int n;
    cin >> n;
    vector<pair<int, int>> arr;
    FOR(n)
    {
      int d, h, m;
      cin >> d >> h >> m;
      for (int j = 0; j < h; ++j)
        arr.push_back({ d, m + j });
    }

    int res = 1;

    if (arr.size() <= 1)
    {
      res = 0;
    }
    else
    {
      long double ttf0 = ((360.0 - arr[0].first) / 360.0) * arr[0].second;
      long double ttf1 = ((360.0 - arr[1].first) / 360.0) * arr[1].second;

      if (ttf0 >= ttf1 + arr[1].second || ttf1 >= ttf0 + arr[0].second)
        res = 1;
      else
        res = 0;
    }
    
    printf("Case #%d: ", CASE);
    cout << res << endl;

  }

  return 0;
}
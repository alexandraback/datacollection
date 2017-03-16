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

int64 poww(int64 a, int b)
{
  int64 res = 1;
  while (b--)
    res *= a;
  return res;
}

int64 swap(int64 n)
{
  stringstream ss;
  ss << n;
  string s = ss.str();
  reverse(ALL(s));
  ss.str("");
  ss << s;
  int64 res;
  ss >> res;
  return res;
}

int64 go(int64 n)
{
  if (n == 0)
    return 0;

//   if (n == 1)
//     return 1;

  int dig = 0;
  int64 nn = n;
  while (nn)
    nn /= 10,
    ++dig;

  int64 ten = poww(10, dig / 2);
  int64 rem = n % ten;
  int64 res = max(0LL, rem - 1);
  n -= res;

  if (n % 10)
  {
    int64 n2 = swap(n);
    if (n2 < n)
      ++res,
      n = n2;
  }

  ten = poww(10, dig-1);
  rem = (n % ten) + 1;
  res += rem;
  n -= rem;

  return res + go(n);
}

/*int mem[1000000];

int brute(int n)
{
  if (n == 0)
    return 0;

  if (mem[n] != -1)
    return mem[n];

  int res = n;
  if (n % 10)
  {
    int n2 = swap(n);
    if (n2 < n)
      res = min(res, 1+brute(n2));
  }

  return mem[n] = min(res, 1+brute(n-1));
}*/

int main()
{
  int CASES = 100000;
  cin >> CASES;
  for (int CASE = 1; CASE <= CASES; ++CASE)
  {
    int64 n;// = rand() % 1000000;
    cin >> n;

    printf("Case #%d: ", CASE);
    int64 res = min(go(n), 1+go(n-1));

//     memset(mem, -1, sizeof mem);
//     int res2 = brute(n);

//    assert(res == res2);

    cout << res << endl;

  }

  return 0;
}
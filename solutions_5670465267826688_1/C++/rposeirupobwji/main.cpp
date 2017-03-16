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

int64 l, x;
string ss;
char target[] = { 'i', 'j', 'k', 0 };
char one = '1';

char transform(char a, char b, int& minus)
{
  if (b == '1')
    return a;

  switch (a)
  {
    case '1': return b;
    case 'i':
      switch (b)
      {
        case 'i': minus ^= 1; return '1';
        case 'j': return 'k';
        case 'k': minus ^= 1; return 'j';
      }
    case 'j':
      switch (b)
      {
        case 'i': minus ^= 1; return 'k';
        case 'j': minus ^= 1; return '1';
        case 'k': return 'i';
      }
    case 'k':
      switch (b)
      {
        case 'i': return 'j';
        case 'j': minus ^= 1; return 'i';
        case 'k': minus ^= 1; return '1';
      }
  }

  assert(false);
  return 0;
}

string solve()
{
  string s;
  for (int i = 0; i < min(5LL, x); ++i)
    s += ss;

  uint32 pos = 0;
  char* tar = target;
  while (*tar)
  {
    char curr = '1';
    int minus = 0;
    while (curr != *tar || minus)
    {
      if (pos >= s.size())
        return "NO";

      curr = transform(curr, s[pos], minus);
      ++pos;
    }

    ++tar;
    x -= pos / l;
    pos %= l;
  }

  // Trailing one
  int64 xs = 5;
  while (xs > 0)
  {
    if (x >= 0 && (x % 4 == 0) && pos == 0)
      return "YES";

    char curr = s[pos++];
    int minus = 0;
    tar = &one;
    while (curr != *tar || minus)
    {
      if (pos >= s.size())
        return "NO";

      curr = transform(curr, s[pos], minus);
      ++pos;
    }

    xs -= pos / l;
    x -= pos / l;
    pos %= l;
  }

  if (x >= 0 && (x % 4 == 0) && pos == 0)
    return "YES";

  return "NO";
}

string solve2()
{
  string s;
  for (int i = 0; i < x; ++i)
    s += ss;

  int64 passed = 0;
  uint32 pos = 0;
  char* tar = target;
  while (*tar)
  {
    char curr = '1';
    int minus = 0;
    while (curr != *tar || minus)
    {
      if (pos >= s.size())
        return "NO";

      curr = transform(curr, s[pos], minus);
      ++pos;
    }

    ++tar;
  }

  // Trailing ones
  while (1)
  {
    if (pos == s.size())
      return "YES";

    char curr = s[pos++];
    int minus = 0;
    tar = &one;
    while (curr != *tar || minus)
    {
      if (pos >= s.size())
        return "NO";

      curr = transform(curr, s[pos], minus);
      ++pos;
    }
  }
}

int main()
{
  int CASES = 100;
  cin >> CASES;
  for (int CASE = 1; CASE <= CASES; ++CASE)
  {
    
    cin >> l >> x >> ss;
    printf("Case #%d: %s\n", CASE, solve().c_str());
  }

  return 0;
}

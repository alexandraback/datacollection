#include <cassert>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
using namespace std;

#define REP(i,n) for(int i=0;i<int(n);++i)
#define AUTO(v,e) __typeof__(e) v = (e)
#define FOR(it,c) for(AUTO (it,(c).begin()); (it) != (c).end(); ++(it))

bool
palin_p (long long n)
{
  static char s[32];
  int l = sprintf (s, "%lld", n);
  REP (i, l) if (s[i] != s[l - 1 - i]) return false;
  return true;
}

int
main ()
{
  vector<int> v;
  REP (i, 1e7 + 10)
    {
      long long n = (long long) i * (long long) i;
      if (palin_p (i) && palin_p (n))
        v.push_back (n);
    }
  int t;
  cin >> t;
  REP (k, t)
    {
      int a, b;
      cin >> a >> b;
      printf("Case #%d: %d\n", k + 1,
             (upper_bound (v.begin (), v.end (), b)
              - lower_bound (v.begin (), v.end (), a)));
    }
}

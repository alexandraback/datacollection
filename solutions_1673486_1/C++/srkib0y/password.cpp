#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <set>
#include <limits>

#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define FORIN FOR(i, 0, n)
#define FORV(x) for(int i = 0, __len = (x).size(); i < __len; i++)

#define MAXN 100001

using namespace std;
int t;
long double a, b;
long double p[MAXN], sol;
long double prod[MAXN];

void init()
{
   FOR(i, 0, MAXN)
      p[i] = (long double) 0L;
   sol = (long double) 1e20L;
}

void read()
{
   cin >> a >> b;
   for (int i = 0; i < a; i++)
      cin >> p[i];
}

void write(int casen)
{
   cout.precision(20);
   cout << "Case #" << casen << ": " << sol << endl;
}

void solve()
{
   prod[0] = (long double) 1L;
   for (int i = 1; i <= a; i++)
      prod[i] = prod[i-1] * p[i-1];
   if ((long double) (b + (long double) 2L) < sol)
      sol = (long double) (b + (long double) 2L);
   for (long double i = 0; i <= a; i++)
   {
      long double exp = prod[(int)a - (int)i] * (long double)((long double)2.L * i + b - a + (long double) 1L) + ((long double) 1L - prod[(int)a - (int)i]) * (long double) ((long double) 2L * i + b - a + (long double) 1L + b + (long double) 1L);
      if (exp < sol)
         sol = exp;
   }
}

int main()
{
   cin >> t;
   for (int casen = 0; casen < t; casen++)
   {
      init();
      read();
      solve();
      write(casen + 1);
   }
   return 0;
}

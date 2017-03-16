#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<fstream>
using namespace std;
long long gcd(long long a, long long b)
{
    if (b == 0)
      return a;
    return gcd(b, a % b);
}
long long findans(long long p, long long q)
{
    long long cur = 2;
    for (long long k = 1; k < 41; k++)
    {
        if (p * cur >= q)
          return k;
        cur *= 2;
    }
    return 41;

}
bool checkq(long long q)
{
    long long cur = 1;
    for (int j = 1; j < 43; j++)
    {
        if (q == cur)
          return 1;
        cur *= 2;
    }
    return 0;
}
int main()
{
    ifstream cin("input_asmall.in");
  ofstream cout ("output_asmall.txt");
  int i, j, n, m, k, l, t;
  cin >> t;
  long long p, q, div;
  for (k = 1; k <= t; k++)
  {
      string s;
      cin >> s;
      p = 0;
      q = 0;
      for (j = 0; s[j] != '/'; j++)
      {
          p *= 10;
          p += (s[j] - '0');
      }
      j++;
      for (;j < s.size(); j++)
      {
          q *= 10;
          q += (s[j] - '0');
      }
      //cin >> p >> q;
      cout << "Case #" << k << ": ";
      if (p * q < 0)
      {
          cout << "impossible\n";
          continue;
          //return 0;
      }
      if (p < 0)
      {
          p = -p;
          q = -q;
      }
      div = gcd(max(p, q), min(p, q));
      p /= div;
      q /= div;
      if (p == 0)
      {
          cout << "impossible\n";
          continue;
          //return 0;
      }
      if (!checkq(q))
      {
          cout << "impossible\n";
          continue;
      }
      long long ans = findans(p, q);
      if (ans == 41)
      {
          cout << "impossible\n";
          continue;
      }
      cout << ans << "\n";
  }

}

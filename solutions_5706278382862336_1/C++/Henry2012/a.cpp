#include <vector>
#include <string>
#include <cstdio>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <cstdlib>
using namespace std;

long long gcd(long long a, long long b) {
  if (b==0) return a;
  return gcd(b, a%b);
}

long long solve() {
  long long p, q, ch;
  // cin >> p >> ch >> q;
  scanf("%lld/%lld", &p, &q);

  long long ct = 0;
  while (p < q) {
    if (q % 2 == 1)
      return -1;

    q /= 2;
    ++ct;
  }

  if (p == q)
    return ct;

  q /= gcd(q, p-q);
  while (q > 1) {
    if (q % 2 == 1)
      return -1;
    
    q /= 2;
  }

  return ct; 
}

int main()
{
  long long T;
  cin >> T;

  for (long long t=1; t<=T; ++t) {
    long long ct = solve();
    if (ct >= 0) 
      cout << "Case #" << t << ": " << ct << endl;
    else 
      cout << "Case #" << t << ": impossible" << endl;
  }
}

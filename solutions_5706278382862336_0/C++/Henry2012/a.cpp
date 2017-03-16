#include <vector>
#include <string>
#include <cstdio>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <cstdlib>
using namespace std;

int gcd(int a, int b) {
  if (b==0) return a;
  return gcd(b, a%b);
}

int solve() {
  int p, q, ch;
  // cin >> p >> ch >> q;
  scanf("%d/%d", &p, &q);

  int ct = 0;
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
  int T;
  cin >> T;

  for (int t=1; t<=T; ++t) {
    int ct = solve();
    if (ct >= 0) 
      cout << "Case #" << t << ": " << ct << endl;
    else 
      cout << "Case #" << t << ": impossible" << endl;
  }
}

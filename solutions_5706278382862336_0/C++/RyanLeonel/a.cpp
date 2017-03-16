#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <stdio.h>

using namespace std;

long long gcd(long long a, long long b)
{
  long long c;
  while ( a != 0 ) {
     c = a; a = b%a;  b = c;
  }
  return b;
}

int main()
{
    int cnt, i, j, n, t;
    long long g, p, p1, pp, q, q1, x;
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    cin >> t;
    for (cnt = 1; cnt <= t; cnt++)
    {
        scanf("%lld/%lld", &p, &q);
        p1 = p; q1 = q; g = gcd(p1, q1); p /= g; q /= g;

        n = 0; pp = p;
        while (pp < q) { pp *= 2; n++; }

        x = pp % q; for (i = 0; i < 40; i++) x = (2 * x) % q;
        if (x) n = -1;

        //display results
        if (n == -1) cout << "Case #" << cnt << ": impossible" << endl;
        else cout << "Case #" << cnt << ": " << n << endl;
    }
    return 0;
}

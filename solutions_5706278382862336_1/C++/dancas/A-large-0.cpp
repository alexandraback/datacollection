#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>

using namespace std;

long long gcd(long long a, long long b) {
   if (b == 0)
      return a;
   return gcd(b, a % b);
}

long long solve(long long p, long long q) {
   long long maxDiv = gcd(p, q);
   p = p / maxDiv;
   q = q / maxDiv;

   long long result = 0,
       best = -1;
   while(q != 1) {
      if (q % 2 != 0)
         return -1;
      q /= 2;

      if (best == -1 && p > q)
         best = result + 1;

      p = p % q;

      ++result;
   }

   if (p > 1)
      return -1;

   return best != -1 ? best : result;
}

int main() {
   int cases;
   cin >> cases;
   for(int c = 1; c <= cases; ++c) {
      string fraction;
      cin >> fraction;

      fraction[fraction.find('/')] = ' ';
      istringstream stream(fraction);
      long long p, q;

      stream >> p >> q;

      cout << "Case #" << c << ": ";

      long long result = solve(p, q);
      if (result == -1)
         cout << "impossible\n";
      else
         cout << result << '\n';
   }
}

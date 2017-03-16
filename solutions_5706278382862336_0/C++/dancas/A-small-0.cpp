#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>

using namespace std;

int gcd(int a, int b) {
   if (b == 0)
      return a;
   return gcd(b, a % b);
}

int solve(int p, int q) {
   int maxDiv = gcd(p, q);
   p = p / maxDiv;
   q = q / maxDiv;

   int result = 0,
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
      int p, q;

      stream >> p >> q;

      cout << "Case #" << c << ": ";

      int result = solve(p, q);
      if (result == -1)
         cout << "impossible\n";
      else
         cout << result << '\n';
   }
}

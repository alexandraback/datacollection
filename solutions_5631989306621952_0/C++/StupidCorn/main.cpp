#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;


int main(int, char**) {
   unsigned T = 0;
   cin >> T;

   for (unsigned t = 0; t < T; ++t) {
      string s;
      cin >> s;

      string result;
      result += s[0];

      const unsigned len = s.size();

      for (unsigned i = 1; i < len; ++i) {
         char c = s[i];
         if (c >= result.front()) {
            result = c + result;
         } else {
            result += c;
         }
      }

      cout << "Case #" << t + 1 << ": " << result << endl;
   }

   return 0;
}


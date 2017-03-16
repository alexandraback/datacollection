#include <iostream>
#include <string>

using namespace std;

int print(string s) {
   int i = s.size(), count = 0;
   while (i--) {
      if (s[i] == '-') {
         for (int j = 0; j <= i; ++j) s[j] = (s[j] == '+') ? '-' : '+';
         ++count;
      }
   }
   return count;
}

int main() {
   int T; cin >> T;
   for (int i = 1; i <= T; ++i) {
      string s; cin >> s;
      cout << "Case #" << i << ": " << print(s) << endl;
   }
   return 0;
}


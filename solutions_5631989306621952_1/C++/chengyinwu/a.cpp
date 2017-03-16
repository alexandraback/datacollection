#include <iostream>

using namespace std;

string solve(string s) {
   string ans = "";
   for (int i = 0; i < s.size(); ++i) {
      if (i && s[i] >= ans[0]) ans = s[i] + ans;
      else ans = ans + s[i];
   }
   return ans;
}

int main() {
   int T; cin >> T;
   for (int i = 1; i <= T; ++i) {
      string s; cin >> s;
      cout << "Case #" << i << ": " << solve(s) << endl;
   }
   return 0;
}


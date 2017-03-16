#include <bits/stdc++.h>

using namespace std;

int nTest, sMax;
string s;

int main() {
   freopen("A-small-attempt0.in", "r", stdin);
   freopen("output.txt", "w", stdout);

   ios::sync_with_stdio(false);
   cin >> nTest;
   for (int t = 1; t <= nTest; t++) {
      cin >> sMax >> s;
      int res = 0, standing = 0;
      for (int i = 0; i <= sMax; i++) {
         if (s[i] == '0') continue;
         int newFriends = max(i - standing, 0);
         res += newFriends;;
         standing += newFriends + (s[i] - '0');
      }
      cout << "Case #" << t << ": " << res << endl;
   }

   return 0;
}

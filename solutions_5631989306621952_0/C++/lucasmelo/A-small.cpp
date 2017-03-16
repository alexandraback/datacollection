#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

string s;

int main() {
  ios :: sync_with_stdio(0);
  int t; cin >> t;
  for(int cn=1; cn<=t; cn++) {
    cin >> s;

    string ans = "";

    for(auto c : s) {
      if ( c + ans < ans + c ) {
        ans = ans + c;
      } else  {
        ans = c + ans;
      }
    }

    printf("Case #%d: %s\n", cn, ans.c_str());
  }
  return 0;
}

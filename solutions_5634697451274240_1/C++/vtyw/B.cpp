#include <bits/stdc++.h>
using namespace std;

int main() {
  int T;
  cin >> T;
  for (int i = 0; i < T; ++i) {
    string s;
    cin >> s;
    int ans = 0;
    while (s.size() && !all_of(s.begin(), s.end(), [](char x){return x == '+';})) {
      auto p = s.find_last_not_of('+');
      s = s.substr(0, p+1);
      transform(s.begin(), s.end(), s.begin(), [](char x){return x == '+' ? '-' : '+';});
      ans++;
    }
    printf("Case #%d: %d\n", i+1, ans);
  }
}
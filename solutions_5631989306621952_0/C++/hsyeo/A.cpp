#include <iostream>
#include <cstring>

using namespace std;

int main() {
  int T; cin >> T;
  for (int test_cases = 1; test_cases <= T; test_cases++) {
    string s; cin >> s;
    string ans;
    ans = s[0];
    for (int j = 1; j < s.size(); j++) {
      if (ans[0] <= s[j]) {
	ans = s[j] + ans;
      } else {
	ans = ans + s[j];
      }      
    }
    printf("Case #%d: %s\n", test_cases, ans.c_str());
  }
  return 0;
}

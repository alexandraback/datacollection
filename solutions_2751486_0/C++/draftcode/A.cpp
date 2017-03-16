#include <iostream>
#include <string>
using namespace std;

int main(void) {
  int T;
  cin >> T;
  for (int cases = 1; cases <= T; cases++) {
    string s; int n;
    cin >> s >> n;

    long long ans = 0;
    int prev_start = -1;
    int cons = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == 'a' || s[i] == 'i' || s[i] == 'u' || s[i] == 'e' || s[i] == 'o') {
        cons = 0;
      } else {
        cons++;
      }

      if (cons >= n) {
        prev_start = i - n + 1;
        ans += (i - n) + 2;
      } else if (prev_start != -1) {
        ans += prev_start + 1;
      }
    }

    cout << "Case #" << cases << ": " << ans << endl;
  }
}

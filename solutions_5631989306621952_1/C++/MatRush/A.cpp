#include <iostream>
#include <cstring>
#include <string>

using namespace std;
const int MAXN = 11111;
string s;

string dp[MAXN];

int main() {
  int cases;
  scanf("%d", &cases);
  for (int T = 1; T <= cases; ++T) {
    printf("Case #%d: ", T);
    cin >> s;
    int n = s.size();
    dp[0] = s[0];
    for (int i = 0; i < n - 1; ++i) {
      if (s[i + 1] + dp[i] > dp[i] + s[i + 1]) {
        dp[i + 1] = s[i + 1] + dp[i];
      } else {
        dp[i + 1] = dp[i] + s[i + 1];
      }
    }
    cout << dp[n - 1] << endl;
  }
}
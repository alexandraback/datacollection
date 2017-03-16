#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
using namespace std;

const long long MAX_NUM = 10000000+1;

inline bool palindrome(long long n)
{
  stringstream ss;
  ss << n;

  string s = ss.str();
  string t = s;
  reverse(t.begin(), t.end());

  if (s == t)
    return true;
  return false;
}

int main()
{
  vector<int> dp(MAX_NUM, 0);
  for (long long i = 1; i < MAX_NUM; ++i) {
    dp[i] += dp[i-1];
    if (palindrome(i)) {
      if (palindrome(i*i))
        ++dp[i];
    }
  }

  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    long long A, B;
    cin >> A >> B;
    long long rA = static_cast<long long>(ceil(sqrt(1.0*A)));
    long long rB = static_cast<long long>(sqrt(1.0*B));

    cout << "Case #" << t+1 << ": " << dp[rB] - dp[rA-1] << endl;
  }

  return 0;
}

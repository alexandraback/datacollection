#include <iostream>
using namespace std;

string s;
string dp[1024];

string solve ()
{
  cin >> s;
  dp[0] = s.substr(0, 1);

  int i;
  for(i = 1; i < s.size(); i++)
  {
    dp[i] = max(dp[i-1] + s.substr(i, 1), "" + s.substr(i, 1) + dp[i-1]);
  }

  return dp[s.size() - 1];
}
int main ()
{
  int t;
  cin >> t;
  for(int i = 1; i <= t; i++)
  {
    printf("Case #%d: %s\n", i, solve().c_str());
  }

  return 0;
}

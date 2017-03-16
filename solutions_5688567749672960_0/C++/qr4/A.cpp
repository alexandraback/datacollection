#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

template<typename T> std::ostream& operator<<(std::ostream& str, const std::vector<T>& v) { str << "["; for(auto n : v) str << n << ", "; str << "]"; return str; }
template<typename K, typename V> std::ostream& operator<<(std::ostream& str, const std::unordered_map<K,V>& m) { str << "["; for(auto n : m) str << n.first << " => " << n.second <<  ", "; str << "]"; return str; }

#define debug(x) cout <<  #x  << ": " << x << endl

using namespace std;

void solve()
{
}

int main()
{
  vector<long long> dp(10e6+1,10e6+1);
  dp[1] = 1;
  for (long long i = 1; i <dp.size(); i++)
  {
    string s = to_string(i);
    reverse(s.begin(), s.end());
    long long t = stol(s);
    if (i+1 < dp.size())   dp[i+1] = min(dp[i]+1, dp[i+1]);
    if (t < dp.size())    dp[t] = min(dp[i]+1, dp[t]);
  }

  cin.sync_with_stdio(false);
  cout.sync_with_stdio(false);
  int T;
  cin >> T;
  for (int i = 0; i < T; i++)
  {
    int N;
    cin >> N;
    cout << "Case #" << i+1 << ": ";
    cout << dp[N] << endl;
  }
}

#include <iostream>
#include <algorithm>
#include <stdint.h>
using namespace std;

const int64_t MAX_N = 1000000000001;

int64_t data[1000];
int64_t dp[MAX_N];

int main()
{
  int t;
  cin >> t;
  int64_t maxn = 0;
  for (int i = 0; i < t; ++i) {
    int64_t temp;
    // cin >> temp;
    cin >> data[i];
    maxn = max(maxn, data[i]);
  }
  
  dp[1] = 1;
  for (int64_t i = 2; i <= maxn; ++i) {
    string ns = to_string(i);
    string rns = ns;
    reverse(rns.begin(), rns.end());
    // cout << ns << ", " << rns << endl;
    if (ns[ns.size()-1] != '0' && ns > rns) {
      dp[i] = min(dp[i-1], dp[stoi(rns)]) + 1;
      // cout << dp[i] << endl;
    } else {
      dp[i] = dp[i-1] + 1;
    }
  }
  for (int i = 0; i < t; ++i) {
    cout << "Case #" << i+1 << ": " << dp[data[i]] << endl;
  }
  return 0;
}
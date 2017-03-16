#include <algorithm>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;

#define all(x) x.begin(), x.end()
#define forn(i, n) for(int i = 0; i < (n); ++i)
#define debug(x) std::cerr << "DEBUG: " << #x << " = " << (x) << std::endl
#define mp make_pair
#define pb push_back
#define PATH "C:\\Users\\Valentin\\Desktop\\"

template<class T> inline int sz(const T& x)
{ return (int) x.size(); }

template<class X, class Y> inline void mx(X& x, Y&& y)
{ if (x < y) x = std::forward<Y>(y); }

template<class X, class Y> inline void mn(X& x, Y&& y)
{ if (y < x) x = std::forward<Y>(y); }

// SOLUTION BEGINS HERE

int dp_bit[1 << 16];

void solve() {
  int n;
  cin >> n;
  map<string, int> first, second;
  auto add = [](map<string, int>& idx, string s) {
    auto it = idx.find(s);
    if (it != idx.end()) {
      return it->second;
    }
    int id = idx.size();
    idx[s] = id;
    return id;
  };
  vector<pair<int, int>> topics(n);
  forn (i, n) {
    string a, b;
    cin >> a >> b;
    topics[i] = {1 << add(first, a), 1 << add(second, b)};
  }
  int need_first = (1 << first.size()) - 1;
  int need_second = (1 << second.size()) - 1;
  vector<pair<int, int>> dp(1 << n);
  dp[0] = {0, 0};
  int ans = n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < (1 << i); ++j) {
      dp[j | (1 << i)].first = dp[j].first | topics[i].first;
      dp[j | (1 << i)].second = dp[j].second | topics[i].second;
    }
  }
  forn (i, (1 << n)) {
    if (dp[i] == pair<int, int>{need_first, need_second}) {
      mn(ans, dp_bit[i]);
    }
  }
  cout << n - ans << endl;
}

void run() {
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  int nTests;
  cin >> nTests;
  for (int iTest = 0; iTest < nTests; ++iTest) {
    cout << "Case #" << (iTest + 1) << ": ";
    solve();
  } 
}

// SOLUTION ENDS HERE

int main() {
  dp_bit[0] = 0;
  for (int i = 1; i < (1 << 16); ++i) {
    dp_bit[i] = dp_bit[i >> 1] + (i & 1);
  }
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  run();
  std::cout.flush();
  return 0;
}
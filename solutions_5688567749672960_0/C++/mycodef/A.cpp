#include <iostream>
#include <algorithm>
#include <vector>

#include <cstdio>

using namespace std;

long long rev(long long n) {
  vector<long long> a;
  long long n1 = n;
  while (n1 > 0) {
    a.push_back(n1 % 10);
    n1 /= 10;
  }
  long long ans = 0;
  size_t i = 0;
  for (; i < a.size() && a[i] == 0; ) ++i;
  for (; i < a.size(); ++i) { ans += a[i]; ans *= 10; }
  return ans / 10;
}

long long dp[1000005];

void main2() {
  long long n = 23;
  cin >> n;
  for (int i = 1; i <= n; ++i) dp[i] = 1000000000;
//  cout << rev(n) << '\n';
  dp[1] = 1;
//  cout << '\n';
  for (long long i = 1; i < n; ++i) {
    long long z = rev(i);
    dp[i + 1] = min(dp[i + 1], dp[i] + 1);
    if (z > i) dp[z] = min(dp[z], dp[i] + 1);
//    cout << dp[i] << ' ';
  }
//  cout << '\n';
  cout << dp[n] << '\n';
}

void main2_slow() {
  //
}

int main() {
#ifdef MOCKINGJAY
  freopen("source/data.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#else
  freopen("source/A-small-0.in", "r", stdin);
  freopen("source/A-small-0.out", "w", stdout);
#endif


  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int T; cin >> T;
  for (int i = 1; i <= T; ++i) {
    cout << "Case #" << i << ": ";
    main2();
  }

}

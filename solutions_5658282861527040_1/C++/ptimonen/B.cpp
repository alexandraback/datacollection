#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
#define A first
#define B second

ll a, b, k;
ll dp[33][2][2][2];

ll ways(int idx, bool toobig, bool anyA, bool anyB) {
  if(idx < 0) {
    return 1;
  }
  ll& cache = dp[idx][toobig][anyA][anyB];
  if(cache != -1) return cache;
  int bit = 1 << idx;
  ll ans = 0;
  bool aT = anyA || ((bit & (a - 1)) != 0);
  bool bT = anyB || ((bit & (b - 1)) != 0);
  if(toobig) {
    // 00 10 01 11
    ans +=              ways(idx - 1, 1, anyA || aT, anyB || bT); 
    ans += aT *         ways(idx - 1, 1, anyA, anyB || bT);
    ans += bT *         ways(idx - 1, 1, anyA || aT, anyB); 
    ans += (aT && bT) * ways(idx - 1, 1, anyA, anyB);
  } else {
    if(bit & k) {
      ans += (aT && bT) * ways(idx - 1, 0, anyA, anyB); 
    } else {
      ans +=              ways(idx - 1, 0, anyA || aT, anyB || bT); 
      ans += aT *         ways(idx - 1, 0, anyA, anyB || bT);
      ans += bT *         ways(idx - 1, 0, anyA || aT, anyB); 
      ans += (aT && bT) * ways(idx - 1, 1, anyA, anyB);
    }
  }
  return cache = ans;
}

int main() {
  int tests;
  cin >> tests;
  for(int test = 1; test <= tests; ++test) {
    fill_n(&dp[0][0][0][0], sizeof(dp) / sizeof(ll), -1);
    cout << "Case #" << test << ": ";
    cin >> a >> b >> k;
    cout << a * b - (ways(30, false, false, false)) << "\n";
  }
  return 0;
}


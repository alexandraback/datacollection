#include <iostream>
#include <algorithm>
#include <vector>

#include <cstdio>

using namespace std;

vector<long long> vec(long long n) {
  vector<long long> a;
  long long n1 = n;
  while (n1 > 0) {
    a.push_back(n1 % 10);
    n1 /= 10;
  }
  return a;
}

long long num(vector<long long> z) {
  long long ans = 0;
  for (auto it = z.rbegin(); it != z.rend(); ++it) {ans += *it; ans *= 10; }
  return ans / 10;
}

long long rev(long long n) {
  vector<long long> a = vec(n);
  return num(vector<long long>(a.rbegin(), a.rend()));
}


long long main2_slow(long long n);
long long main2_fast(long long n);
long long dp[1000005];

void main2() {
  long long n = 11111111111111LL; 
  cin >> n;
  cout << main2_fast(n) << '\n';
//  exit(0);
//  main2_slow(10000);
//  for (int i = 10; i < 1212; ++i) {
//    long long z1 = dp[i];
//    long long z2 = main2_fast(i);
//    if (z1 != z2) {
//      cout << "NO " << i << ' ' << z1 << ' ' << z2 << '\n';
//      break;
//    }
//  }
}

long long main2_slow(long long n) {
  for (int i = 1; i <= n; ++i) dp[i] = 1000000000;
  dp[1] = 1;
  for (long long i = 1; i < n; ++i) {
    long long z = rev(i);
    dp[i + 1] = min(dp[i + 1], dp[i] + 1);
    if (z > i) dp[z] = min(dp[z], dp[i] + 1);
  }
//  for (int i = 1; i < n; ++i) cout << dp[i] << ' ';
//  cout << '\n';
  return dp[n];
}

long long main2_fast(long long n) {
  long long cnt = 1;
  while (n > 1) {
    while (n > 1 && n % 10 != 1) { 
      --n; ++cnt; 
    }
    if (n == 1) break;
    vector<long long> b = vec(n);
    for (size_t i = 1; i < b.size() / 2; ++i) b[i] = 0;
    //4 / 2 + 1 = 2 + 1 = 3
    long long b1 = num(b);
//    cout << n << ' ' << b1 << '\n';
    
    long long d = n - b1;
    
    long long z = rev(n);
    long long z1 = rev(b1);
    if (z1 < n && z1 < b1 && z1 + d < z) {
//      cout << "xx " << n << ' ' << z1 << '\n';
      cnt += d + 1;
      n = z1;
    } else if (z < n && z > 0) {
      n = z;
      ++cnt;
//      cout << "z " << n << ' ' << cnt << '\n';
    } else {
      --n;
      ++cnt;
//      cout << "z " << n << ' ' << cnt << '\n';
    }
//    cout << n << '\n';
  }
  return cnt;
}

int main() {
#ifdef MOCKINGJAY
  freopen("source/data.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#else
  
  freopen("source/A-large-0.in", "r", stdin);
  freopen("source/A-large-0.out", "w", stdout);
#endif


  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int T; cin >> T;
  for (int i = 1; i <= T; ++i) {
    cout << "Case #" << i << ": ";
    main2();
  }

}

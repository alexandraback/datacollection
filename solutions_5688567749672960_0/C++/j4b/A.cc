#include <iostream>
#include <vector>

using namespace std;

int reverse(int k) {
  int rk = 0;
  while(k > 0) {
    rk *= 10;
    rk += k % 10;
    k /= 10;
  }
  return rk;
}
int first(int k) {
  return reverse(k) % 10;
}

int last(int k) {
  return k % 10;
}

// int solve2(int k, int n) {
//   if (k == n) {
//     return 0;
//   } else {
//     int rk = reverse(k);
//     if (rk > k + 1 && rk < n) {
//       return 1 + min(solve(rk, n), solve(k+1, n));
//     } else {
//       return 1 + solve(k+1, n);
//     }
//   }
// } 

int solve(int n) {
  //return solve2(0, n);
  vector<int> m(10*n+1, 0);

  m[0] = 0;
  m[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (m[i] == 0) {
      m[i] = m[i-1] + 1;
    } else {
      m[i] = min(m[i], m[i-1] + 1);
    }

    if (reverse(i) > i) {
      m[reverse(i)] = m[i] + 1;
    } 
  }

  return m[n];
}

int main(int argc, char *argv[]) {
 
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    int n;
    cin >> n;

    cout << "Case #" << i << ": " << solve(n) << endl;
  }
}

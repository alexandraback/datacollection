#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>

#define rep(i, n) for(int i = 0; i < n; i++)

using namespace std;

typedef long long ll;

template<class T> ostream& operator<<(ostream& os, vector<T> v) {
  for(T x : v) os << x << ", ";
  return os;
}

int bit(int x, int i) {
  return (x >> i) & 1;
}

int A, B, K;
ll memo[40][2][2][2];

ll solve(int i, bool canA, bool canB, bool canK) {
  if(i < 0) return 1;

  ll& d = memo[i][canA][canB][canK];
  if(d != -1) return d;

  ll ans = 0;
  bool flgA = canA || bit(A, i);
  bool flgB = canB || bit(B, i);
  bool flgK = canK || bit(K, i);

  ans += solve(i-1, flgA, flgB, flgK);
  if(flgA) {
    ans += solve(i-1, canA, flgB, flgK);
  }
  if(flgB) {
    ans += solve(i-1, flgA, canB, flgK);
  }
  if(flgA && flgB && flgK) {
    ans += solve(i-1, canA, canB, canK);
  }

  return d = ans;
}

int main() {

  int T;
  cin >> T;

  rep(t, T) {

    cout << "Case #" << (t+1) << ": ";
    cin >> A >> B >> K;
    A--;
    B--;
    K--;

    rep(i, 40) rep(j, 2) rep(k, 2) rep(l, 2) {
      memo[i][j][k][l] = -1;
    }

    cout << solve(30, false, false, false) << endl;

  }

  return 0;
}

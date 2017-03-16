#include<iostream>

using namespace std;

#define rep(i, n) for (int i = 0; i < int(n); ++i)

long long e, r, n;
long long v[11111];

long long solve(long long a, long long b, long long c, long long d) {
  if (a >= b) return 0;
  long long mxI, mx = 0;
  for (int i = a; i < b; ++i) if (mx < v[i]) {
      mx = v[i];
      mxI = i;
    }
  long long nextc = c;
  for (int i = a; i < mxI; ++i) {
    nextc += r; 
    nextc = min(nextc, e);
  }
  long long nextd = d;
  for (int i = b - 1; i > mxI; --i) {
    nextd -= r;
    nextd = max(nextd, 0LL);
  }
  if (nextd < r) nextd = r;
  //cout << a << " " << b << " " << c << " " << d << " " << nextc << " " << nextd << endl;
  return solve(a, mxI, c, nextc) + mx * (nextc - max(nextd - r, 0LL)) + solve(mxI + 1, b, nextd, d);
}

int main() {
  int t;
  cin >> t;
  rep (iii, t) {
    cin >> e >> r >> n;
    rep (i, n) cin >> v[i];
    cout << "Case #" << iii + 1 << ": " << solve(0, n, e, min(e, r)) << endl;
  }
  return 0;
}

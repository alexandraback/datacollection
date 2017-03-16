#include <iostream>
#include <algorithm>
using namespace std;
int a, b, n;
inline int getd(int x) {
  int ans = 1;
  while (x / 10) {
    x /= 10;
    ans *= 10;
  }
  return ans;
}
int solve(int x) {
  int xd = getd(x);
  int ans = 0;
  int v[20];
  int vn = 0;
  for (int i = 10; i <= xd; i *= 10) {
    int left = x  % i;
    int right = x / i;
    int t = left * (xd / i) * 10+ right;
    if ((x < t) && (t <= b) && xd == getd(t) 
        && find(v, v+vn, t) == v+vn) {
      ++ans;
      v[vn++] = t;
    }
  }
  return ans;
}
int main() {
  cin >> n;
  for (int t = 0; t < n; ++t) {
    int ans = 0;
    cin >> a >> b;
    for (int i = a; i <= b; ++i)
      ans += solve(i);
    cout << "Case #" << (t+1) << ": " << (ans) << endl;
  }
}

/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
            pass System Test!
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template <typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &v) {
  if (!v.empty()) {
    out << '[';
    std::copy(v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
    out << "\b\b]";
  }
  return out;
}
template <typename T1, typename T2>
std::ostream &operator<<(std::ostream &out, const std::pair<T1, T2> &p) {
  out << "[" << p.first << ", " << p.second << "]";
  return out;
}
template <class T, class U>
void chmin(T &t, U f) {
  if (t > f) t = f;
}
template <class T, class U>
void chmax(T &t, U f) {
  if (t < f) t = f;
}

ll solve(ll M) {
  vector<bool> check(10, false);
  for (int i = 1; i < 100000000; ++i) {
    ll N = M * i;
    while (N > 0) {
      int digit = N - N / 10 * 10;
      check[digit] = true;
      N /= 10;
    }
    for (int j = 0; j < check.size(); ++j) {
      if (!check[j]) break;
      if (j == check.size() - 1) return M * i;
    }
  }
  return -1;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int i = 0; i < T; ++i) {
    int N;
    cin >> N;
    cout << "Case #" << (i + 1) << ": ";
    if (N == 0) {
      cout << "INSOMNIA";
    } else {
      ll ans = solve(N);
      if (ans == -1) {
        cout << "INSOMNIA";
      } else {
        cout << ans;
      }
    }
    cout << endl;
  }
}

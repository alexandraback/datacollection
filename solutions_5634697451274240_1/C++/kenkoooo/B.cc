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

string turn(const string &S) {
  string T = S;
  int N = S.size();
  for (int i = 0; i < N; ++i) {
    if (S[N - 1 - i] == '+') {
      T[i] = '-';
    } else {
      T[i] = '+';
    }
  }
  return T;
}

map<pair<string, char>, ll> dp;
ll solve(string S, char c) {
  char d = c == '+' ? '-' : '+';
  int N = S.size();
  if (N == 0) return 0;
  if (S.back() == c) return solve(S.substr(0, N - 1), c);
  if (dp.count({S, c})) return dp[{S, c}];
  ll ans = N;
  if (S[0] == d) ans = min(ans, 1 + solve(turn(S).substr(0, N - 1), c));
  ans = min(ans, 1 + solve(S.substr(0, N - 1), d));
  dp[{S, c}] = ans;
  return ans;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int i = 0; i < T; ++i) {
    string S;
    cin >> S;
    cout << "Case #" << (i + 1) << ": ";
    ll ans = min(solve(S, '+'), solve(S, '-') + 1);
    cout << ans << endl;
  }
}

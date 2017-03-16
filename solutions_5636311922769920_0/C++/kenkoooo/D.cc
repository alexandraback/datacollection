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

set<ll> solve(int K, int C) {
  set<ll> ans;
  ll orig_pos = 0;
  while (orig_pos < K) {
    ll real_pos = orig_pos;
    for (ll i = 1; i < C; ++i) {
      ll pos_in_block = real_pos % K;
      real_pos=real_pos*K+pos_in_block;
      if (orig_pos < K - 1) {
        orig_pos++;
        real_pos++;
      }
    }
    ans.insert(real_pos);
    orig_pos++;
  }
  return ans;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int testcase = 1; testcase <= T; ++testcase) {
    int K, C, S;
    cin >> K >> C >> S;
    set<ll> ans = solve(K, C);
    cout << "Case #" << testcase << ":";
    if (ans.size() > S) {
      cout << " IMPOSSIBLE";
    } else {
      for (ll a : ans) cout << " " << (a + 1);
    }
    cout << endl;
  }
}

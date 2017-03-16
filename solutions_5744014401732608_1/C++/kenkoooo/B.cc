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
template <typename T>
void uniq(vector<T> &v) {
  v.erase(unique(v.begin(), v.end()), v.end());
}

int64_t fast_pow(int64_t x, int64_t e) {
  int64_t ret = 1;
  int64_t cur = x;
  while (e) {
    if (e & 1) ret *= cur;
    cur *= cur;
    e >>= 1;
  }
  return ret;
}

int64_t dp_check(const vector<vector<bool>> &ans) {
  int N = ans.size();
  vector<int64_t> dp(N, 0);
  dp[0] = 1;

  for (int i = 1; i < N; ++i) {
    for (int j = 0; j < i; ++j) {
      if (ans[j][i]) dp[i] += dp[j];
    }
  }
  return dp[N - 1];
}

vector<vector<bool>> solve(int B, int64_t M) {
  int64_t checkM = M;
  if (fast_pow(2, B - 2) < M) return vector<vector<bool>>();
  vector<vector<bool>> ans(B, vector<bool>(B, false));

  int init = 0;
  while (fast_pow(2, init + 1) <= M) init++;
  for (int i = 0; i <= init; ++i) {
    ans[i][B - 1] = true;
    for (int j = i + 1; j <= init; ++j) {
      ans[i][j] = true;
    }
  }
  M -= fast_pow(2, init);

  int add = init + 1;
  for (int i = init; i > 0; --i) {
    if (M >= fast_pow(2, i - 1)) {
      ans[i][add] = true;
      ans[add][B - 1] = true;
      M -= fast_pow(2, i - 1);
    }
  }
  if (M == 1) ans[0][add] = true;

  if (checkM != dp_check(ans)) {
    cerr << B << " " << checkM << endl;
    for (int i = 0; i < ans.size(); ++i) {
      for (int j = 0; j < ans[i].size(); ++j) {
        if (ans[i][j])
          cerr << 1;
        else
          cerr << 0;
      }
      cerr << endl;
    }
  }
  return ans;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int T;
  cin >> T;
  for (int testcase = 1; testcase <= T; ++testcase) {
    int B;
    int64_t M;
    cin >> B >> M;

    cout << "Case #" << testcase << ": ";
    vector<vector<bool>> ans = solve(B, M);
    if (ans.size() == 0) {
      cout << "IMPOSSIBLE" << endl;
    } else {
      cout << "POSSIBLE" << endl;
      for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < ans[i].size(); ++j) {
          if (ans[i][j])
            cout << 1;
          else
            cout << 0;
        }
        cout << endl;
      }
    }
  }
}

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

int bitCount(int64_t x) {
  x = (x & 0x55555555) + (x >> 1 & 0x55555555);
  x = (x & 0x33333333) + (x >> 2 & 0x33333333);
  x = (x & 0x0f0f0f0f) + (x >> 4 & 0x0f0f0f0f);
  x = (x & 0x00ff00ff) + (x >> 8 & 0x00ff00ff);
  return (x & 0x0000ffff) + (x >> 16 & 0x0000ffff);
}

const int MAXS = 4;

int state(int j, int p, int s) { return j * MAXS * MAXS + p * MAXS + s; }

typedef tuple<int, int, int> C;
vector<tuple<int, int, int>> naive_solve(int J, int P, int S, int K) {
  vector<C> pool;
  for (int j = 0; j < J; ++j)
    for (int p = 0; p < P; ++p)
      for (int s = 0; s < S; ++s) pool.emplace_back(j + 1, p + 1, s + 1);
  int N = pool.size();
  cerr << "Pool: " << N << endl;

  int ans_mask = 0;
  for (int mask = 0; mask < (1 << N); ++mask) {
    if (mask % 1000000 == 0) cerr << mask << endl;
    if (bitCount(mask) <= bitCount(ans_mask)) continue;
    vector<int> cnt(state(MAXS, MAXS, MAXS), 0);
    for (int i = 0; i < N; ++i) {
      if (mask & (1 << i)) {
        int j, p, s;
        tie(j, p, s) = pool[i];
        cnt[state(0, p, s)]++;
        if (cnt[state(0, p, s)] > K) break;
        cnt[state(j, 0, s)]++;
        if (cnt[state(j, 0, s)] > K) break;
        cnt[state(j, p, 0)]++;
        if (cnt[state(j, p, 0)] > K) break;
      }
      if (i == N - 1 && bitCount(mask) > bitCount(ans_mask)) {
        ans_mask = mask;
      }
    }
  }

  vector<C> ans;
  for (int i = 0; i < N; ++i) {
    if (ans_mask & (1 << i)) {
      ans.push_back(pool[i]);
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
    int J, P, S, K;
    cin >> J >> P >> S >> K;

    cout << "Case #" << testcase << ": ";
    vector<tuple<int, int, int>> ans = naive_solve(J, P, S, K);
    cout << ans.size() << endl;
    for (const auto &t : ans) {
      int j, p, s;
      tie(j, p, s) = t;
      cout << j << " " << p << " " << s << endl;
    }
  }
}

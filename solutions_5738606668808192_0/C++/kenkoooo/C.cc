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

ll generate(ll mask, ll b) {
  ll ans = 0;
  ll a = 1;
  while (mask > 0) {
    if (mask & 1) ans += a;
    mask >>= 1;
    a *= b;
  }
  return ans;
}

ll get_divisor(ll checker, const vector<int> &primes) {
  ll N = min((ll)primes.size(), (ll)sqrt(checker) + 2);
  for (const auto p : primes) {
    if (checker % p == 0) return p;
    if (p > N) break;
  }
  return -1;
}

vector<int> eratosthenes(int N) {
  vector<bool> is_prime(N + 1, true);
  vector<int> primes;
  is_prime[0] = false;
  is_prime[1] = false;
  for (int i = 2; i <= N; ++i)
    if (is_prime[i]) {
      primes.push_back(i);
      for (int j = i * 2; j <= N; j += i) {
        is_prime[j] = false;
      }
    }
  return primes;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N = 16;
  int J = 50;
  vector<int> primes = eratosthenes(1e8);
  vector<vector<ll>> ans;
  vector<ll> subans(10);
  for (ll i = 0; i < (1 << (N - 2)); ++i) {
    if ((i + 1) % 100000 == 0) cerr << (i + 1) << endl;
    ll mask = (i << 1) + 1 + (1 << (N - 1));
    subans[0] = mask;
    for (int b = 2; b <= 10; ++b) {
      ll checker = generate(mask, b);
      ll d = get_divisor(checker, primes);
      if (d < 0) goto next;
      subans[b - 1] = d;
    }
    ans.push_back(subans);
    if (ans.size() == J) break;
  next:;
  }

  cout << "Case #1:" << endl;
  for (const auto &v : ans) {
    cout << static_cast<bitset<16>>(v[0]);
    // cout << static_cast<bitset<16>>(v[0]);
    for (int i = 1; i < v.size(); ++i) {
      cout << " " << v[i];
    }
    cout << endl;
  }
}

#include <cassert>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

template <typename T> inline T set_bit(const T &x, int index) {
  return x | ((T)1 << index);
}
template<typename T, typename U> inline bool makemax(T &res, const U &x) {
  if (x > res) {
    res = x;
    return true;
  }
  return false;
}
template <typename T> inline int get_bit(const T &x, int index) {
  return int((x >> index) & 1);
}

const int MAXN = 24;
int n;
string str1[MAXN], str2[MAXN];
int8_t memo[1<<MAXN];

int8_t rek(int state) {
  if (state == (1<<n)-1) {
    return 0;
  }
  auto& ret = memo[state];
  if (ret != -1) {
    return ret;
  }
  ret = 0;
  for (int i=0; i<n; ++i) {
    if (get_bit(state, i)) {
      continue;
    }
    bool seen1 = false, seen2 = false;
    for (int j=0; j<n; ++j) {
      seen1 |= get_bit(state, j) && str1[i] == str1[j];
      seen2 |= get_bit(state, j) && str2[i] == str2[j];
    }
    makemax(ret, (seen1 && seen2) + rek(set_bit(state, i)));
  }
  return ret;
}

int solve() {
  cin >> n;
  assert(n <= MAXN);
  for (int i=0; i<n; ++i) {
    cin >> str1[i] >> str2[i];
  }

  memset(memo, -1, 1<<n);
  return rek(0);
}

int main() {
  ios_base::sync_with_stdio(false);

  int T;
  cin >> T;
  for (int tt=1; tt<=T; ++tt) { // caret here
    cout << "Case #" << tt << ": " << solve() << '\n';
  }
}

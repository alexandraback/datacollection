#include <iostream>
#include <fstream>

using namespace std;

const int LIM = 150;
const int COINS_CNT = 18;
const int MAX_MASK = (1 << 18);

bool used[LIM], us[LIM];
int cns[LIM];

bool get_bit(int mask, int bit) {
  return (mask >> bit) & 1;
}

int get_bit_cnt(int mask) {
  int res = 0;
  for (int bit = 1; bit < COINS_CNT; ++bit)
    res += get_bit(mask, bit);
  return res;
}

bool check(int mask, int v) {
  for (int i = 0; i < LIM; ++i)
    us[i] = used[i];
  for (int bit = 1; bit < COINS_CNT; ++bit)
    if (get_bit(mask, bit))
      for (int pos = v; pos >= 0; --pos)
        if (us[pos] && pos + bit < LIM)
          us[pos + bit] = true;
  bool res = true;
  for (int i = 1; i <= v; ++i)
    res &= us[i];
  return res;
}

int main() {
  ifstream cin("C-small-attempt1.in");
  ofstream cout("C-small.out");
  int tests;
  cin >> tests;
  for (int test = 1; test <= tests; ++test) {
    int c, d, v;
    cin >> c >> d >> v;
    int coins = 0;
    int ans = LIM;
    fill(used, used + LIM, false);
    fill(cns, cns + LIM, false);
    for (int i = 0; i < d; ++i) {
      int tmp;
      cin >> tmp;
      if (coins < COINS_CNT)
        coins |= (1 << tmp);
      cns[i] = tmp;
    }
    used[0] = true;
    for (int i = 0; i < d; ++i)
      for (int pos = v; pos >= 0; --pos)
        if (used[pos] && pos + cns[i] < LIM)
          used[pos + cns[i]] = true;
    for (int mask = 0; mask < MAX_MASK; ++mask) {
      if (mask % 2 == 0) {
        bool b = false;
        for (int bit = 1; bit < COINS_CNT; ++bit)
          if (get_bit(mask, bit) == true && get_bit(coins, bit) == true)
            b = true;
        if (b)
          continue;
        if (check(mask, v))
          ans = min(ans, get_bit_cnt(mask));
      }
    }
    cout << "Case #" << test << ": " << ans << "\n";
  }
  return 0;
}

#include <iostream>
#include <vector>
#include <map>
using namespace std;
using ull = unsigned long long;
using vb = vector<bool>;

vb ab, bb, kb;
map<tuple<int, bool, bool, bool>, ull> cache;

ull dp(int p, bool ua, bool ub, bool uk) {
  auto key = make_tuple(p, ua, ub, uk);
  auto it = cache.find(key);
  if (it != cache.end()) return it->second;
  auto& ans = cache[key];
  
  if (p == -1) { return ans = 1; }
  bool a1 = true, b1 = true, k1 = true;
  if (ua && !ab[p]) {
    a1 = false;
  }
  if (ub && !bb[p]) {
    b1 = false;
  }
  if (uk && !kb[p]) {
    k1 = false;
  }

  ans = dp(p-1, !a1, !b1, !k1);
  if (a1 && b1 && k1) {
    ans += dp(p-1, ua, ub, uk);
  }
  if (a1) {
    ans += dp(p-1, ua, !b1, !k1);
  }
  if (b1) {
    ans += dp(p-1, !a1, ub, !k1);
  }
  return ans;
}

vb bits(ull x) {
  vb out;
  while (x) {
    out.push_back((x & 1) == 1);
    x >>= 1;
  }
  while (out.size() < 35) out.push_back(0);
  return out;
}

int main() {
  int ncases;
  cin >> ncases;
  for (int ncase = 1; ncase <= ncases; ++ncase) {
    ull a, b, k;
    cin >> a >> b >> k;

    ab = bits(a-1);
    bb = bits(b-1);
    kb = bits(k-1);

    cache.clear();
    cout << "Case #" << ncase << ": " << dp(34, true, true, true) << endl;
  }
}

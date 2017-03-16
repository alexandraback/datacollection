#define NDEBUG
#include <cassert>
#include <iostream>
#include <string>
#include <tuple>
using namespace std;

typedef long long int64;

int n;
string str1, str2;

int64 pow10[19];
tuple<int64, string, string> memo[19][3];

bool match(const string& str, int pos, int z) {
  return str[pos] == '?' || str[pos] == '0' + z;
}

tuple<int64, string, string>& calc(int pos, int mode) {
  if (pos == n) {
    static tuple<int64, string, string> zeroret(0, "", "");
    return zeroret;
  }
  auto& ret = memo[pos][mode];
  if (get<0>(ret) != -1) {
    return ret;
  }

  const int64 pos10 = pow10[n-pos-1];
  ret = make_tuple(LLONG_MAX, "", "");
  for (int z1=0; z1<=9; ++z1) {
    if (match(str1, pos, z1)) {
      for (int z2=0; z2<=9; ++z2) {
        if (match(str2, pos, z2)) {
          int newmode = mode;
          if (mode == 0) {
            newmode = z1 == z2 ? 0 : z1 > z2 ? 1 : 2;
          }
          auto& sub = calc(pos+1, newmode);
          int64 diff =
            newmode == 0 ? get<0>(sub) :
            newmode == 1 ? (z1 - z2) * pos10 + get<0>(sub) :
                           (z2 - z1) * pos10 + get<0>(sub);
          if (mode == 0) {
            assert(diff >= 0);
          }
          if (diff < get<0>(ret)) {
            ret = make_tuple(diff,
                             char('0'+z1) + get<1>(sub),
                             char('0'+z2) + get<2>(sub));
          }
        }
      }
    }
  }
  return ret;
}

string solve() {
  cin >> str1 >> str2;
  n = str1.size();
  for (int i=0; i<n; ++i) {
    for (int m=0; m<3; ++m) {
      memo[i][m] = make_tuple(-1, "", "");
    }
  }
  auto ret = calc(0, 0);
  return get<1>(ret) + ' ' + get<2>(ret);
}

int main() {
  ios_base::sync_with_stdio(false);

  pow10[0] = 1;
  for (int i=1; i<=18; ++i) {
    pow10[i] = 10*pow10[i-1];
  }

  int T;
  cin >> T;
  for (int tt=1; tt<=T; ++tt) { // caret here
    cout << "Case #" << tt << ": " << solve() << '\n';
  }
}

#define NDEBUG
#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

#define ZERO(v) memset((v), 0, sizeof (v))

int mapp[256];

int rm(char ch, const string& str) {
  int n = mapp[ch];
  for (char c : str) {
    assert(mapp[c] >= n);
    mapp[c] -= n;
  }
  return n;
}

string solve() {
  ZERO(mapp);

  string input;
  cin >> input;
  for (char ch : input) {
    ++mapp[ch];
  }

  int count[10] = {0};
  count[0] = rm('Z', "ZERO");
  count[2] = rm('W', "TWO");
  count[6] = rm('X', "SIX");
  count[8] = rm('G', "EIGHT");
  count[7] = rm('S', "SEVEN");
  count[5] = rm('V', "FIVE");
  count[4] = rm('F', "FOUR");
  count[9] = rm('I', "NINE");
  count[3] = rm('R', "THREE");
  count[1] = rm('O', "ONE");
  string ret;
  for (int z=0; z<=9; ++z) {
    ret += string(count[z], '0'+z);
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);

  int T;
  cin >> T;
  for (int tt=1; tt<=T; ++tt) { // caret here
    cout << "Case #" << tt << ": " << solve() << '\n';
  }
}

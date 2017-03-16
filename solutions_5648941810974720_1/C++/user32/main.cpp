#include <algorithm>
#include <bitset>
#include <cassert>
#include <cinttypes>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

struct Item {
  const char* value;
  int digit;
};

const Item kDigits[] = {
  {"ZERO", 0},
  {"FOUR", 4},
  {"SIX", 6},
  {"TWO", 2},
  {"EIGHT", 8},
  {"THREE", 3},
  {"ONE", 1},
  {"FIVE", 5},
  {"SEVEN", 7},
  {"NINE", 9}
};

void Solve() {
  string S;
  cin >> S;

  map<char, int> M;
  for (char ch : S) {
    M[ch]++;
  }

  string result;
  for (const Item& item : kDigits) {
    string value = item.value;
    for (;;) {
      bool ok = true;
      for (char ch : value) {
        if (M[ch] == 0) {
          ok = false;
        }
      }

      if (!ok) {
        break;
      }

      for (char ch : value) {
        M[ch]--;
      }

      result.push_back('0' + item.digit);
    }
  }

  int sum = 0;
  for (const auto& p : M) {
    sum += p.second;
  }
  assert(sum == 0);

  sort(result.begin(), result.end());
  cout << result << endl;
}

int main() {
//  freopen("../Console/1.txt", "rb", stdin);
  freopen("../Console/input", "rb", stdin);
  freopen("../Console/output", "wb", stdout);
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;
  for (int tc = 0; tc < T; ++tc) {
    cout << "Case #" << tc + 1 << ": ";
    Solve();
  }

  return 0;
}

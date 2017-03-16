#include <algorithm>
#include <array>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef int64_t i64;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int,int> ii;

bool TryGoDown(string& s, i64& answer) {
  if (s[0] == '1') {
    bool nonzero = false;
    for (int i = 1; i < s.size(); ++i) {
      if (s[i] != '0') {
        nonzero = true;
        break;
      }
    }
    if (!nonzero) {
      return false;
    }
  }
  s[s.size() - 1] = '9';
  for (int i = 1; i < s.size(); ++i) {
    if (s[s.size() - i - 1] != '0') {
      s[s.size() - i - 1] -= 1;
      break;
    }
    s[s.size() - i - 1] = '9';
  }
  ++answer;
}

void BeforeReverse(string& s, i64& answer) {
  if (s[s.size() - 1] == '0') {
    if (!TryGoDown(s, answer)) {
      return;
    }
  }
  const int size_half = s.size() / 2;
  answer += (s[s.size() - 1] - '1');
  s[s.size() - 1] = '1';
  i64 factor = 10;
  for (int i = 1; i < size_half; ++i) {
    answer += factor * (s[s.size() - i - 1] - '0');
    factor *= 10;
    s[s.size() - i - 1] = '0';
  }
}

void MayReverse(string& s, i64& answer) {
  if (s[s.size() - 1] == '0') {
    return;
  }
  bool reversed = false;
  const int size_half = s.size() / 2;
  for (int i = 0; i < size_half; ++i) {
    if (s[i] != s[s.size() - i - 1]) {
      reversed = true;
      swap(s[i], s[s.size() - i - 1]);
    }
  }
  if (reversed) {
    ++answer;
  }
}

void AfterReverse(string& s, i64& answer) {
  const int ss = s.size() - 1;
  i64 factor = 1;
  for (int i = 0; i < ss; ++i) {
    answer += factor * (s[ss - i] - '9');
    factor *= 10;
  }
  answer += factor * (s[0] - '0');

  s.clear();
  for (int i = 0; i < ss; ++i) {
    s.push_back('9');
  }
}

int main() {
  cin.sync_with_stdio(false);
  cout.sync_with_stdio(false);

  int T = 0;
  cin >> T;
  for (int tt = 1; tt <= T; ++tt) {
    string N;
    cin >> N;

    i64 answer = 0;
    while (N.size() > 1) {
      BeforeReverse(N, answer);
      MayReverse(N, answer);
      AfterReverse(N, answer);
    }
    answer += (N[0] - '0');
    cout << "Case #" << tt << ": " << answer << "\n";
  }
  
  return 0;
}

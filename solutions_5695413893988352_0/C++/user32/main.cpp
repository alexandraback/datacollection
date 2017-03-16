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

void Go(int pos, string& A, vector<int>& result) {
  if (pos == A.size()) {
    result.push_back(atoi(A.c_str()));
    return;
  }

  if (A[pos] != '?') {
    Go(pos + 1, A, result);
    return;
  }

  for (char ch = '0'; ch <= '9'; ++ch) {
    A[pos] = ch;
    Go(pos + 1, A, result);
    A[pos] = '?';
  }
}

string Out(int value, int len) {
  stringstream ss;
  ss << value;

  string result = ss.str();
  while (result.size() < len) {
    result = "0" + result;
  }

  return result;
}

void Solve() {
  string A, B;
  cin >> A >> B;

  int len = A.size();

  vector<int> left, right;
  Go(0, A, left);
  Go(0, B, right);

  sort(left.begin(), left.end());
  sort(right.begin(), right.end());

  int from = 2.0E7, to = 1.0E7;

  for (int l : left) {
    int idx = lower_bound(right.begin(), right.end(), l) - right.begin();

    for (int i = max(0, idx - 1); i <= min(idx + 1, (int)right.size() - 1);
         ++i) {
      int old_dist = abs(from - to);
      int dist = abs(l - right[i]);

      if (dist < old_dist) {
        from = l;
        to = right[i];
      } else if (dist == old_dist) {
        if (l < from) {
          from = l;
          to = right[i];
        } else if (l == from) {
          if (right[i] < to) {
            from = l;
            to = right[i];
          }
        }
      }
    }
  }

  cout << Out(from, len) << ' ' << Out(to, len) << endl;
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

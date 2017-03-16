#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int ntest, k, c, s;

  cin >> ntest;

  for (int test = 1; test <= ntest; test++) {
    cin >> k >> c >> s;

    vector<long long> res;

    for (int x = 0; x < k; x += c) {
      long long u = x;
      int v = x;

      for (int y = 0; y < c - 1; y++) {
        if (v + 1 < k) {
          v++;
        }

        u = u * k + v;
      }

      res.push_back(u);
    }

    cout << "Case #" << test << ": ";

    if (res.size() <= s) {
      for (int i = 0; i < res.size(); i++) {
        cout << res[i] + 1 << " ";
      }
    } else {
      cout << "IMPOSSIBLE";
    }

    cout << endl;
  }
}

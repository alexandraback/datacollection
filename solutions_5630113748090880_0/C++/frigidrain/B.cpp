#include <iostream>
#include <cstdio>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

string solve(string &s) {
  string res;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] >= res[0]) {
      res = s[i] + res;
    } else {
      res = res + s[i];
    }
  }
  return res;
}

int main() {
  int T, N, x;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    vector<int> f(2501, 0);
    cin >> N;
    for (int i = 0; i < 2*N - 1; i++) {
      for (int j = 0; j < N; j++) {
        cin >> x;
        f[x]++;
      }
    }
    vector<int> result;
    for (int i = 1; i <= 2500; i++) {
      if (f[i] % 2 == 1) {
        result.push_back(i);
      }
    }
    sort(result.begin(), result.end());
    printf("Case #%d:", t);
    for (int i = 0; i < result.size(); i++) {
      cout << ' ' << result[i];
    }
    cout << endl;
  }

}

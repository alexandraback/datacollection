#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;

int solve(int N, int S, int p, const vector<int> &t) {
  int res = 0;
  int s = S;
  for (int i = 0; i < N; i++) {
    if (3*p-2 <= t[i]) res++;
    else if (p > 1 && s > 0 && 3*p-4 <= t[i]) {
      s--;
      res++;
    }
  }
  return res;
}

int main() {
  int T;
  cin >> T;
  for (int testcase = 0; testcase < T; testcase++) {
    int N, S, p;
    cin >> N;
    cin >> S;
    cin >> p;
    vector<int> t(N);
    for (int i = 0; i < N; i++) {
      cin >> t[i];
    }
    int res = solve(N, S, p, t);
    cout << "Case #" << testcase + 1 << ": " << res << endl;
  }
  return 0;
}

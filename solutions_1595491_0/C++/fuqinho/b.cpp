#include <iostream>
#include <vector>
using namespace std;

int solve(int s, int p, vector<int>& tp) {
  int res = 0;
  for (int i = 0; i < tp.size(); i++) {
    if (min(tp[i], (tp[i] + 2) / 3) >= p) {
      res++;
    } else {
      if (s > 0 && min(tp[i], (tp[i] + 4) / 3) >= p) {
        res++;
        s--;
      }
    }
  }
  return res;
}

int main() {
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    int N, S, p;
    cin >> N >> S >> p;
    vector<int> tp(N);
    for (int i = 0; i < N; i++) cin >> tp[i];

    int answer = solve(S, p, tp);
    cout << "Case #" << t << ": " << answer << endl;
  }
}


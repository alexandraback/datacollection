#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct S {
  int ith, armin, cost;
  S(int i, int a, int c) : ith(i), armin(a), cost(c) {}
  bool operator< (const S &rhs) const {
    return this->cost > rhs.cost;
  }
};

int main(void) {
  int T, A, N;
  cin >> T;
  for (int cases = 1; cases <= T; cases++) {
    cin >> A >> N;
    vector<int> motes(N);
    for (int i = 0; i < N; i++) cin >> motes[i];
    sort(motes.begin(), motes.end());

    priority_queue<S> Q;
    Q.push(S(0, A, 0));
    while (!Q.empty()) {
      S s = Q.top(); Q.pop();

      if (s.ith == N) {
        cout << "Case #" << cases << ": " << s.cost << endl;
        break;
      }

      if (s.armin > motes[s.ith]) {
        Q.push(S(s.ith+1, s.armin + motes[s.ith], s.cost));
      }
      Q.push(S(s.ith, s.armin+s.armin-1, s.cost+1));
      Q.push(S(s.ith+1, s.armin, s.cost+1));
    }
  }
}

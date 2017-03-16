#include <cstdio>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

struct State {
  State (double F, double X, double t) : F(F), X(X), t(t) {}
  double F, X, t;
};

int main() {
  int T, Case = 1;
  scanf("%d", &T);
  while (T--) {
    printf("Case #%d: ", Case++);
    double C, F, X;
    scanf("%lf%lf%lf", &C, &F, &X);
    queue<State> q;
    q.push(State(2, 0, 0));
    double ans = 2e9;
    while (!q.empty()) {
      State state = q.front();
      q.pop();
      if (state.F > 150 * X) {
        continue;
      }
      ans = min(ans, state.t + (X - state.X) / state.F);
      if (state.X >= C) {
        q.push(State(state.F + F, state.X - C, state.t));
      } else {
        q.push(State(state.F + F, 0, state.t + (C - state.X) / state.F));
      }
    }
    printf("%.7lf\n", ans);
  }
  return 0;
}

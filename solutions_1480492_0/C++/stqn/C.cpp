#include <iostream>
#include <map>
#include <utility>

using namespace std;

const double EPS = 1e-9;

template <typename T> void upd_min(T& lhs, T rhs) {

  if (lhs > rhs) lhs = rhs;

}

double collision(map<double,int>& m) {

  double res = 1e9;
  pair<double,int> prev;
  map<double,int>::iterator it = m.begin();
  while (it != m.end()) {
    if (prev.second > it->second) {
      upd_min(res,
              (it->first - prev.first - 5.0)
              / (prev.second - it->second));
    }
    prev = *it;
    ++it;
  }
  return res;

}

map<double,int> forward(map<double,int>& m, double time) {

  map<double,int> res;
  map<double,int>::iterator it = m.begin();
  while (it != m.end()) {
    res[it->first + it->second * time] = it->second;
    ++it;
  }
  return res;

}

bool canInsert(map<double,int>& m, double pos) {

  map<double,int>::iterator it = m.lower_bound(pos - 5.0 + EPS);
  return it == m.end() || it->first > pos + 5.0;

}

bool exchange(map<double,int>& l, map<double,int>& r) {

  map<double,int>::iterator it = l.begin();
  if (it == l.end()) return true;
  for (;;) {
    pair<double,int> prev = *it;
    if (++it == l.end()) break;
    if (it->first - prev.first - 5.0 < EPS &&
        it->second < prev.second) {
      if (canInsert(r, prev.first)) {
        r[prev.first] = prev.second;
        --it;
        l.erase(it++);
      }
      else {
        return false;
      }
    }
  }
  return true;

}

int main() {

  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    int N;
    cin >> N;
    map<double,int> L, R;
    for (int i = 0; i < N; ++i) {
      char c;
      int S, P;
      cin >> c >> S >> P;
      (c == 'L' ? L : R)[P] = S;
    }
    double time = 0.0;
    for (;;) {
      double col = min(collision(L), collision(R));
      if (col == 1e9) {
        printf("Case #%d: Possible\n", t);
        break;
      }
      time += col;
      L = forward(L, col);
      R = forward(R, col);
      if (!exchange(L, R)) {
        printf("Case #%d: %.5f\n", t, time);
        break;
      }
      if (!exchange(R, L)) {
        printf("Case #%d: %.5f\n", t, time);
        break;
      }
    }
  }

  return 0;

}

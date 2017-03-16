#include <gmpxx.h>
#include <gtk/gtk.h>
#include <cairo.h>

#include "shelly.hpp"

using namespace std;
using namespace shelly;

int war(const vector<double> &f, const vector<double> &s) {
  assert(f.size() == s.size());
  if (f.empty())
    return 0;
  if (f[0] > s[s.size() - 1])
    return f.size();
  if (f[f.size() - 1] > s[s.size() - 1]) {
    vector<double> tf(f.begin(), f.end() - 1), ts(s.begin() + 1, s.end());
    return war(tf, ts) + 1;
  }
  vector<double> tf(f.begin(), f.end() - 1), ts(s.begin(), s.end());
  for (auto it = ts.begin(); ; ++it) {
    if (*it > f[f.size() - 1]) {
      ts.erase(it);
      break;
    }
  }
  return war(tf, ts);
}

int dwar(const vector<double> &f, const vector<double> &s) {
  assert(f.size() == s.size());
  if (f.empty())
    return 0;
  if (f[0] > s[s.size() - 1])
    return f.size();
  if (f[f.size() - 1] > s[s.size() - 1]) {
    vector<double> tf(f.begin(), f.end() - 1), ts(s.begin(), s.end() - 1);
    return dwar(tf, ts) + 1;
  }

  vector<double> tf(f.begin() + 1, f.end()), ts(s.begin(), s.end() - 1);
  return dwar(tf, ts);
}

int main(int argc, char **argv) {
  freopen("input.txt", "r", stdin);
  gtk_init(&argc, &argv);

  int T;
  cin >> T;
  for (int TT = 1; TT <= T; TT++) {
    int N;
    cin >> N;
    vector<double> f, s;
    for (int i = 0; i < N; i++) {
      double t;
      cin >> t;
      f.push_back(t);
    }
    for (int i = 0; i < N; i++) {
      double t;
      cin >> t;
      s.push_back(t);
    }
    Sort(f);
    Sort(s);

    cout << Format("Case #%0: %1 %2", TT, dwar(f, s), war(f, s)) << endl;
  }
  return 0;
}

#include <cassert>
#include <iostream>
#include <set>

using namespace std;

int get_score_war(set<double> me, set<double> he) {
  while (!me.empty() && *(me.begin()) < *(he.rbegin())) {
    he.erase(he.lower_bound(*(me.begin())));
    me.erase(me.begin());
  }
  return me.size();
}

int get_score_deceitful_war(set<double> me, set<double> he) {
  int won = 0;
  while (!me.empty()) {
    if (*(me.rbegin()) > *(he.rbegin())) {
      me.erase(--me.end());
      he.erase(--he.end());
      won++;
    } else {
      me.erase(me.begin());
      he.erase(--he.end());
    }
  }
  return won;
}

int main() {
  ios_base::sync_with_stdio(false);
  int tests;
  cin >> tests;

  for (int t = 0; t < tests; t++) {
    int n;
    cin >> n;
    set<double> me;
    set<double> he;
    for (int i = 0; i < n; i++) {
      double w; cin >> w;
      me.insert(w);
    }
    for (int i = 0; i < n ; i++) {
      double w; cin >> w;
      he.insert(w);
    }
    cout << "Case #" << (t + 1) << ": ";
    cout << get_score_deceitful_war(me, he) << " " << get_score_war(me, he) << '\n';
  }
}


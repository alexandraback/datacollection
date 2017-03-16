#include <iostream>
#include <vector>

#define debug(x) cerr << #x << " = " << x << endl

using namespace std;

const double EPS = 1e-9;

bool guaranteed_survival(const vector<int>& s, int sum, int ind, double perc) {
  double ind_score = double(s[ind])+perc*double(sum);
  double rem_votes = 1.0-perc;
  //debug(ind_score);
  for (int i = 0; i < int(s.size()) && rem_votes >= 0.0; ++i) if (i != ind) {
    //debug(i);
    //debug((ind_score-double(s[i]))/double(sum));
    rem_votes -= max(0.0, (ind_score-double(s[i]))/double(sum));
  }
  return rem_votes < 0.0;
}

int main() {
  cout.setf(ios::fixed);
  cout.precision(6);
  int T;
  cin >> T;
  for (int ca = 1; T--; ++ca) {
    int n;
    cin >> n;
    vector<int> s(n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      cin >> s[i];
      sum += s[i];
    }
    cout << "Case #" << ca << ":";
    for (int i = 0; i < n; ++i) {
      double lo = 0.0, hi = 1.0;
      for (; lo+EPS < hi;) {
        double md = (lo+hi)/2.0;
        //debug(md);
        if (guaranteed_survival(s, sum, i, md)) {
          hi = md;
        }
        else {
          lo = md;
        }
      }
      cout << " " << 100.0*lo;
    }
    cout << endl;
  }
}

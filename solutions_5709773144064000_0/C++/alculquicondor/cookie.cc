#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  int tc, row;
  double C, F, X;
  cin >> tc;
  cout << fixed << setprecision(7);
  for (int caso = 1; caso <= tc; ++caso) {
    cin >> C >> F >> X;
    cout << "Case #" << caso << ": ";
    double cfarm = 0, cget = 2, ans = 1e300, tmp;
    for (int i = 0; true; ++i) {
      tmp = cfarm + X / cget;
      if (tmp < ans)
        ans = tmp;
      else if (tmp > ans + 1e-7)
        break;
      //cerr << "# " << cfarm + X / cget << endl;
      cfarm += C / cget;
      cget += F;
    }
    //cerr << i << endl;
    cout << ans << endl;
  }
}


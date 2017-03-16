#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int main() {
  int T; cin >> T;
  int ncase = 0;
  while (T--) {
    int n; cin >> n;
    cout << "Case #" << ++ncase << ": ";
    int pa, sa;
    int pb, sb;
    if (n == 1) {
      int x;
      cin >> pa >> x >> sa;
      pb = pa;
      sb = sa+1;
    }
    else {

      int x;
      cin >> pa >> x >> sa;
      cin >> pb >> x >> sb;
      if (sb < sa) {
        swap(sa,sb);
        swap(pa,pb);
      }
    }

    // time for a to begin
    double ta = ((360-pa)/360.0)*double(sa);
    // time b
    double tb = ((360-pb)/360.0)*double(sb);

    if (ta+2*sa <= tb) {
      cout << 2 << endl;
    }
    else if (ta + sa <= tb) {
      cout << 1 << endl;
    }
    else {
      cout << 0 << endl;
    }

  }
}

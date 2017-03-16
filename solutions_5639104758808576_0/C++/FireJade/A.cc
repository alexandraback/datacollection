#include <iostream>
using namespace std;

int main() {
  int T; cin >> T;
  int x; string y;
  for (int caseNum = 1; caseNum <= T; caseNum++) {
    cin >> x >> y;
    int added = 0, total = 0;
    for (int i = 0; i < y.length(); i++) {
      int ct = (char)y[i] - '0';
      if (ct > 0 && i > total) {
        added += i - total;
        total += added;
      }
      total += ct;
    }
    cout << "Case #" << caseNum << ": " << added << endl;
  }
}

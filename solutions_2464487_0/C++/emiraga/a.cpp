#include <iostream>
#include <cmath>
using namespace std;

typedef long long LL;
typedef long double LLD;

LL r, t;

bool works(LL m) {
  LL Sm = m*(2*r-1) + 2*m*m;

  return Sm <= t;
}

int main() {
  int T; cin >> T;
  for (int cs = 1; cs <= T; cs++) {
    cout << "Case #" << cs << ": ";
    cin >> r >> t;

    LL m;
    LL l = 1;
    LL h = sqrt(LLD(t));
    while (l <= h) {
      m = (l+h) / 2;
      if(works(m)) {
        l=m+1;
      } else {
        h=m-1;
      }
    }
    LL res = l-1;
    cout << res << endl;
  }
  return 0;
}

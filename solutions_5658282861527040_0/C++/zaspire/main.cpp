#include <gmpxx.h>
//#include <gtk/gtk.h>
//#include <cairo.h>

#include "shelly.hpp"

using namespace std;
using namespace shelly;

int main(int argc, char **argv) {
  freopen("input.txt", "r", stdin);
//  gtk_init(&argc, &argv);

  int T;
  cin >> T;
  for (int TT = 1; TT <= T; TT++) {
    int A, B, K;
    int res = 0;
    cin >> A >> B >> K;
    for (int i = 0; i < A; i++) {
      for (int k = 0; k < B; k++) {
        if ((i & k) < K)
          res++;
      }
    }
    cout << Format("Case #%0: %1", TT, res) << endl;
  }
  return 0;
}

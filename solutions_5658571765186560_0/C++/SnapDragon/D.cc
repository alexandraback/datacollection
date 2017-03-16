#include <iostream>
using namespace std;

main() {
  int T, X, R, C, prob=1;
  for (cin >> T; T--;) {
    cin >> X >> R >> C;
    if (R > C) swap(R, C);

    if ((R*C) % X) goto fail;
    if (X > C) goto fail;
    if (X == 3 && R == 1) goto fail;
    if (X == 4 && R <= 2) goto fail;
    if (X == 5 && R <= 2) goto fail;
    if (X == 5 && R == 3 && C == 5) goto fail;
    if (X == 6 && R <= 3) goto fail;
    if (X >= 7) goto fail;

    cout << "Case #" << prob++ << ": GABRIEL" << endl;
    continue;
fail:
    cout << "Case #" << prob++ << ": RICHARD" << endl;
  }
}

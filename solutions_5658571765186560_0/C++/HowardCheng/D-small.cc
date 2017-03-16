#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

// 1st player wins?
bool solve()
{
  int X, R, C;
  cin >> X >> R >> C;

  if (R > C) swap(R, C);
  
  if ((R*C) % X != 0) return true;

  if (X == 1 || X == 2) return false;

  if (X == 3) {
    return R <= 1;
  }

  if (X == 4) {
    return R <= 2;
  }
  assert(false);
}

int main()
{
  int T;
  cin >> T;
  for (int i = 1; i <= T; i++) {
    cout << "Case #" << i << ": " << (solve() ? "RICHARD" : "GABRIEL") << endl;
  }
  
  return 0;
}
